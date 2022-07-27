//
// Created by 27673 on 2022/7/3.
//

#include "TcpServer.h"

using namespace QE;
using namespace QE::net;

TcpServer::TcpServer(EventLoop *loop,
                     const InetAddress &listenAddr,
                     const string &nameArg, int outtime,
                     Option option, bool usePool)
        : loop_(CHECK_NOTNULL(loop)),
          ipPort_(listenAddr.toIpPort()),
          name_(nameArg),
          acceptor_(new Acceptor(loop, listenAddr, option == kReusePort)),
        // connectionCallback_(defaultConnectionCallback),
        // messageCallback_(defaultMessageCallback),
          nextConnId_(1),
          outtime(outtime) {
    acceptor_->setNewConnectionCallback([this](int sockfd, const InetAddress &addr) {
        newConnection(sockfd, addr);
    });

    threadPool_ = std::make_shared<EventLoopThreadPool>(3);

    assert(weakConnectionList.empty());

    //如果设定了超时时间
    if (outtime >= 1) {
        for (int i = 0; i < outtime; ++i) weakConnectionList.push(Bucket());
        loop->runEvery(1.0, [this] { this->outTime(); });
    }
}

TcpServer::~TcpServer() {
    loop_->assertInLoopThread();
    LOG_TRACE << "TcpServer::~TcpServer [" << name_ << "] destructing";

    for (auto &item : connections_) {
        TcpConnectionPtr conn(item.second);
        item.second.reset();
        conn->getLoop()->runInLoop(
                std::bind(&TcpConnection::connectDestroyed, conn));
    }
}


void TcpServer::start() {
    assert(!acceptor_->listening());
    loop_->runInLoop(
            std::bind(&Acceptor::listen, acceptor_.get()));

}

void TcpServer::newConnection(int sockfd, const InetAddress &peerAddr) {
    loop_->assertInLoopThread();
    EventLoop *ioLoop = threadPool_->getNextLoop();
    if (ioLoop == nullptr) {
        LOG_INFO << "no ";
        ioLoop = loop_;
    }
    char buf[64];
    snprintf(buf, sizeof buf, "-%s#%d", ipPort_.c_str(), nextConnId_);
    ++nextConnId_;
    string connName = name_ + buf;

    LOG_INFO << "TcpServer::newConnection [" << name_
             << "] - new connection [" << connName
             << "] from " << peerAddr.toIpPort();
    InetAddress localAddr(muduo::net::sockets::getLocalAddr(sockfd));
    // FIXME poll with zero timeout to double confirm the new connection
    // FIXME use make_shared if necessary
    TcpConnectionPtr conn(new TcpConnection(ioLoop,
                                            connName,
                                            sockfd,
                                            localAddr,
                                            peerAddr));
    connections_[connName] = conn;
    conn->setConnectionCallback(connectionCallback_);
    conn->setMessageCallback([this](const TcpConnectionPtr &conn,
                                    Buffer *buffer,
                                    Timestamp timestamp) { MessageCallbackTcpServer(conn, buffer, timestamp); });

    conn->setWriteCompleteCallback(writeCompleteCallback_);
    conn->setCloseCallback([this](const TcpConnectionPtr &conn) -> void { removeConnection(conn); }); // FIXME: unsafe
    ioLoop->runInLoop([conn] { conn->connectEstablished(); });


    //如果开启 超时断开连接
    if (outtime >= 1) {
        addEntry(conn);
    }
}

void TcpServer::removeConnection(const TcpConnectionPtr &conn) {
    // FIXME: unsafe
    //loop_->runInLoop(std::bind(&TcpServer::removeConnectionInLoop, this, conn));
    //注意这里不能用引用捕获 tcpPtr 因为在这里他只是一个 临时 变量
    // 反思  ：  捕获 优选使用 值捕获。
    loop_->runInLoop([this, conn] { removeConnectionInLoop(conn); });
}

void TcpServer::removeConnectionInLoop(const TcpConnectionPtr &conn) {
    loop_->assertInLoopThread();
    LOG_INFO << "TcpServer::removeConnectionInLoop [" << name_
             << "] - connection " << conn->name();
    size_t n = connections_.erase(conn->name());
    (void) n;
    assert(n == 1);
    EventLoop *ioLoop = conn->getLoop();
    auto th = conn.get();
    //ioLoop->queueInLoop([&]{TcpConnection::connectDestroyed(conn);});

    ioLoop->queueInLoop(
            std::bind(&TcpConnection::connectDestroyed, conn));
}

