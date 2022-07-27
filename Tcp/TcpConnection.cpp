//
// Created by 27673 on 2022/7/3.
//

#include "TcpConnection.h"

using namespace QE;
using namespace QE::net;

TcpConnection::TcpConnection(EventLoop *loop, const std::string &nameArg,
                             int sockfd, const InetAddress &localAddr,
                             const InetAddress &peerAddr)
    : loop_(CHECK_NOTNULL(loop)), name_(nameArg), state_(kConnecting),
      reading_(true), socket_(new Socket(sockfd)),
      channel_(new Channel(loop, sockfd)), localAddr_(localAddr),
      peerAddr_(peerAddr), highWaterMark_(64 * 1024 * 1024) {
  channel_->setReadCallback(
      [this](Timestamp timestamp) -> void { handleRead(timestamp); });
  channel_->setWriteCallback([this]() -> void { handleWrite(); });
  channel_->setCloseCallback([this] { handleClose(); });
  channel_->setErrorCallback([this] { handleError(); });
  LOG_DEBUG << "TcpConnection::ctor[" << name_ << "] at " << this
            << " fd=" << sockfd;
  socket_->setKeepAlive(true);
}

TcpConnection::~TcpConnection() {
  LOG_DEBUG << "TcpConnection::dtor[" << name_ << "] at " << this
            << " fd=" << channel_->fd() << " state=" << stateToString();
  assert(state_ == kDisconnected);
}

bool TcpConnection::getTcpInfo(struct tcp_info *tcpi) const {
  return socket_->getTcpInfo(tcpi);
}

std::string TcpConnection::getTcpInfoString() const {
  char buf[1024];
  buf[0] = '\0';
  socket_->getTcpInfoString(buf, sizeof buf);
  return buf;
}

/**
 *  该函数只可以再loop 中调用
 * 1） 缓冲区中没有数据 则直接发送数据。 没有发送完 再加入到缓冲区 并关注
 * epollout 事件 2） 缓冲区中存在数据 则不能直接发送，要存放于缓冲区。
 * @param message
 * @param len
 */
void TcpConnection::sendInLoop(const void *message, size_t len) {
  loop_->assertInLoopThread();
  size_t remaining = len;
  size_t nsend = 0;
  if (state_ == kDisconnected) { //该来连接以关闭
    LOG_WARN << "disconnected , give up writting";
    return;
  } else if (!channel_->isWriting() && outputBuffer_.readableBytes() == 0) {
    nsend = ::write(channel_->fd(), message, len);

    if (nsend >= 0) {
      remaining -= nsend;
      if (remaining == 0 && writeCompleteCallback_) {
        loop_->runInLoop(
            [this] { writeCompleteCallback_(shared_from_this()); });
      }
    } else if (nsend < 0) {
      nsend = 0;
      if (errno != EWOULDBLOCK) {
        LOG_SYSERR << "TcpConnection::sendInLoop";
        if (errno == EPIPE || errno == ECONNRESET) // FIXME: any others?
        {
          return;
        }
      }
    }
  }
  assert(remaining <= len);
  if (remaining > 0) {
    //判断缓冲是否移除风险
    size_t high = remaining + outputBuffer_.readableBytes();
    if (high >= highWaterMark_ && highWaterMarkCallback_) {
      loop_->runInLoop(
          [this, high] { highWaterMarkCallback_(shared_from_this(), high); });
    }

    //加入到缓冲区  并关注 epollout 事件
    outputBuffer_.append(static_cast<const char *>(message) + nsend, remaining);
    if (!channel_->isWriting()) {
      channel_->enableWriting();
    }
  }
}

void TcpConnection::sendInLoop(const muduo::StringPiece &message) {
  sendInLoop(message.data(), message.size());
}

void TcpConnection::send(const void *message, int len) {
  if (loop_->isInLoopThread()) {
    LOG_DEBUG << "send in self loop";
    sendInLoop(message, len);
  } else {
    LOG_DEBUG << "send in other loop";
    loop_->runInLoop([&] { sendInLoop(message, len); });
  }
}

void TcpConnection::send(Buffer *message) {
  std::string str = message->retrieveAllAsString();
  LOG_DEBUG << "send " << str;
  send(str.c_str(), str.length());
}

void TcpConnection::send(const muduo::StringPiece &message) {
  send(message.data(), message.size());
}

/**
 * 关闭连接的函数
 */
void TcpConnection::shutdownInLoop() {
  LOG_INFO << "shout down in loop";
  loop_->assertInLoopThread();
  // 如果 应用程 Buffer 中没有数据就，关闭 写端
  //关闭写端，就是再 内核缓冲区中 的末尾添加一个终止符
  // 再这里不能直接close ， rst 报文会清空发送缓冲区里没有发送完的数据
  if (!channel_->isWriting()) {
    LOG_INFO << "in";
    socket_->shutdownWrite();
  }
}

void TcpConnection::shutdown() {
  // FIXME: use compare and swap
  if (state_ == kConnected) {
    LOG_INFO << "shutdown";
    setState(kDisconnecting);
    // FIXME: shared_from_this()?
    loop_->runInLoop([this] { shutdownInLoop(); });
  }
}

void TcpConnection::forceClose() {
  // FIXME: use compare and swap
  if (state_ == kConnected || state_ == kDisconnecting) {
    setState(kDisconnecting);

    auto sthis = shared_from_this(); //延长 生命周期 至该函数结束
    loop_->queueInLoop([this] { forceCloseInLoop(); });
  }
}

void TcpConnection::forceCloseWithDelay(double seconds) {
  if (state_ == kConnected || state_ == kDisconnecting) {
    auto it = shared_from_this();
    setState(kDisconnecting);
    loop_->runAfter(seconds, [&] {
      forceClose();
    }); // not forceCloseInLoop to avoid race condition
  }
}

void TcpConnection::forceCloseInLoop() {
  loop_->assertInLoopThread();
  if (state_ == kConnected || state_ == kDisconnecting) {
    // as if we received 0 byte in handleRead();
    handleClose();
  }
}

const char *TcpConnection::stateToString() const {
  switch (state_) {
  case kDisconnected:
    return "kDisconnected";
  case kConnecting:
    return "kConnecting";
  case kConnected:
    return "kConnected";
  case kDisconnecting:
    return "kDisconnecting";
  default:
    return "unknown state";
  }
}

void TcpConnection::setTcpNoDelay(bool on) { socket_->setTcpNoDelay(on); }

void TcpConnection::startRead() {
  loop_->runInLoop([this] { startReadInLoop(); });
}

void TcpConnection::startReadInLoop() {
  loop_->assertInLoopThread();
  if (!reading_ || !channel_->isReading()) {
    channel_->enableReading();
    reading_ = true;
  }
}

void TcpConnection::stopRead() {
  loop_->runInLoop([this] { stopReadInLoop(); });
}

void TcpConnection::stopReadInLoop() {
  loop_->assertInLoopThread();
  if (reading_ || channel_->isReading()) {
    channel_->disableReading();
    reading_ = false;
  }
}

void TcpConnection::connectEstablished() {
  loop_->assertInLoopThread();
  assert(state_ == kConnecting);
  setState(kConnected);
  channel_->tie(shared_from_this());
  channel_->enableReading();
  connectionCallback_(shared_from_this());
}

void TcpConnection::connectDestroyed() {
  loop_->assertInLoopThread();
  if (state_ == kConnected) {
    setState(kDisconnected);
    channel_->disableAll();

    connectionCallback_(shared_from_this());
  }
  LOG_DEBUG << "call channel remove";
  channel_->remove();
}

void TcpConnection::handleRead(Timestamp receiveTime) {
  loop_->assertInLoopThread();
  int savedErrno = 0;
  ssize_t n = inputBuffer_.readFd(channel_->fd(), &savedErrno);
  if (n > 0) {
    messageCallback_(shared_from_this(), &inputBuffer_, receiveTime);
  } else if (n == 0) {
    handleClose();
  } else {
    errno = savedErrno;
    LOG_SYSERR << "TcpConnection::handleRead";
    handleError();
  }
}

/**
 * 缓冲可写 事件发生时的回调
 * 缓冲区写完  取消关注
 */
void TcpConnection::handleWrite() {
  loop_->assertInLoopThread();
  if (channel_->isWriting()) {
    ssize_t n = ::write(channel_->fd(), outputBuffer_.peek(),
                        outputBuffer_.readableBytes());
    if (n > 0) {
      outputBuffer_.retrieve(n);
      if (outputBuffer_.readableBytes() == 0) {
        channel_->disableWriting();
        if (writeCompleteCallback_) {
          loop_->queueInLoop(
              [this] { writeCompleteCallback_(shared_from_this()); });
        }
        if (state_ == kDisconnecting) {
          shutdownInLoop();
        }
      }
    } else {
      LOG_SYSERR << "TcpConnection::handleWrite";
      // if (state_ == kDisconnecting)
      // {
      //   shutdownInLoop();
      // }
    }
  } else {
    LOG_TRACE << "Connection fd = " << channel_->fd()
              << " is down, no more writing";
  }
}

void TcpConnection::handleClose() {
  loop_->assertInLoopThread();
  LOG_TRACE << "fd = " << channel_->fd() << " state = " << stateToString();
  assert(state_ == kConnected || state_ == kDisconnecting);
  // we don't close fd, leave it to dtor, so we can find leaks easily.
  setState(kDisconnected);
  channel_->disableAll();

  TcpConnectionPtr guardThis(shared_from_this());
  connectionCallback_(guardThis);
  // must be the last line
  closeCallback_(guardThis);
}

void TcpConnection::handleError() {
  int err = muduo::net::sockets::getSocketError(channel_->fd());
  LOG_ERROR << "TcpConnection::handleError [" << name_
            << "] - SO_ERROR = " << err << " " << muduo::strerror_tl(err);
}
