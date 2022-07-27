//
// Created by 27673 on 2022/7/3.
//

#ifndef TINYWEB_TCPCONNECTION_H
#define TINYWEB_TCPCONNECTION_H

#include "../Reactor/Channel.h"
#include "../Reactor/EventLoop.h"
#include <muduo/net/Socket.h>
#include <muduo/net/InetAddress.h>
#include <memory>
#include <boost/any.hpp>
#include <muduo/net/Buffer.h>
#include "../exhead.h"
#include <unordered_set>
#include <queue>

struct tcp_info;


namespace QE {
    namespace net {
        typedef muduo::net::Socket Socket;

        class EventLoop;

        class Channel;

        class TcpConnection;

        //------------------------------------------------------
        class Entry;

        typedef std::shared_ptr<Entry> EntryPtr;
        typedef std::weak_ptr<Entry> WeakEntryPtr;
        typedef std::unordered_set<EntryPtr> Bucket;
        typedef std::queue<Bucket> WeakConnectionList;
        //-------------------------------------------------------

        typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

        ///
/// TCP connection, for both client and server usage.
///
/// This is an interface class, so don't expose too much details.
        class TcpConnection : noncopyable,
                              public std::enable_shared_from_this<TcpConnection> {
        public:
            /// Constructs a TcpConnection with a connected sockfd
            ///
            /// User should not create this object.
            TcpConnection(EventLoop *loop,
                          const std::string &name,
                          int sockfd,
                          const InetAddress &localAddr,
                          const InetAddress &peerAddr);

            ~TcpConnection();

            EventLoop *getLoop() const { return loop_; }

            const std::string &name() const { return name_; }

            const InetAddress &localAddress() const { return localAddr_; }

            const InetAddress &peerAddress() const { return peerAddr_; }

            bool connected() const { return state_ == kConnected; }

            bool disconnected() const { return state_ == kDisconnected; }

            // return true if success.
            bool getTcpInfo(struct tcp_info *) const;

            std::string getTcpInfoString() const;

            // void send(string&& message); // C++11
            void send(const void *message, int len);

            void send(const muduo::StringPiece &message);

            // void send(Buffer&& message); // C++11
            void send(Buffer *message);  // this one will swap data
            void shutdown(); // NOT thread safe, no simultaneous calling
            // void shutdownAndForceCloseAfter(double seconds); // NOT thread safe, no simultaneous calling
            void forceClose();

            void forceCloseWithDelay(double seconds);

            void setTcpNoDelay(bool on);

            // reading or not
            void startRead();

            void stopRead();

            bool isReading() const { return reading_; }; // NOT thread safe, may race with start/stopReadInLoop

            void setContext(const boost::any &context) { context_ = context; }

            const boost::any &getContext() const { return context_; }

            boost::any *getMutableContext() { return &context_; }

            void setConnectionCallback(const ConnectionCallback &cb) { connectionCallback_ = cb; }

            void setMessageCallback(const MessageCallback &cb) { messageCallback_ = cb; }

            void setWriteCompleteCallback(const WriteCompleteCallback &cb) { writeCompleteCallback_ = cb; }

            void setHighWaterMarkCallback(const HighWaterMarkCallback &cb, size_t highWaterMark) {
                highWaterMarkCallback_ = cb;
                highWaterMark_ = highWaterMark;
            }

            /// Advanced interface
            Buffer *inputBuffer() { return &inputBuffer_; }

            Buffer *outputBuffer() { return &outputBuffer_; }

            /// Internal use only.
            void setCloseCallback(const CloseCallback &cb) { closeCallback_ = cb; }

            // called when TcpServer accepts a new connection
            void connectEstablished();   // should be called only once
            // called when TcpServer has removed me from its map
            void connectDestroyed();  // should be called only once


            WeakEntryPtr getWeakEntry() { return weakEntryPtr; }

            void setWeakEntryPtr(WeakEntryPtr ptr) { weakEntryPtr = ptr; }

        private:
            enum StateE {
                kDisconnected, kDisconnecting, kConnected, kConnecting
            };

            void handleRead(Timestamp receiveTime);

            void handleWrite();

            void handleClose();

            void handleError();

            // void sendInLoop(string&& message);
            void sendInLoop(const muduo::StringPiece &message);

            void sendInLoop(const void *message, size_t len);

            void shutdownInLoop();

            // void shutdownAndForceCloseInLoop(double seconds);
            void forceCloseInLoop();

            void setState(StateE s) { state_ = s; }

            const char *stateToString() const;

            void startReadInLoop();

            void stopReadInLoop();

            EventLoop *loop_;
            const std::string name_;
            StateE state_;  // FIXME: use atomic variable
            bool reading_;
            // we don't expose those classes to client.
            std::unique_ptr<Socket> socket_;
            std::unique_ptr<Channel> channel_;
            const InetAddress localAddr_;
            const InetAddress peerAddr_;
            ConnectionCallback connectionCallback_;
            MessageCallback messageCallback_;
            WriteCompleteCallback writeCompleteCallback_;
            HighWaterMarkCallback highWaterMarkCallback_;
            CloseCallback closeCallback_;
            size_t highWaterMark_;
            Buffer inputBuffer_;
            Buffer outputBuffer_; // FIXME: use list<Buffer> as output buffer.
            boost::any context_;
            //用于存放 weakEnrty;
            WeakEntryPtr weakEntryPtr;

            // FIXME: creationTime_, lastReceiveTime_
            //        bytesReceived_, bytesSent_


            void defaultConnectionCallback(const TcpConnectionPtr &conn);

            void defaultMessageCallback(const TcpConnectionPtr &conn,
                                        Buffer *buffer,
                                        Timestamp receiveTime);

        };


    }
}


namespace QE {
    namespace net {
        class EventLoop;

        class Channel;

        class TcpConnection;

        class TimerQueue;


        //用于管理 踢掉超连接部分  采用 RALL  手法，  析构时调用关闭函数。
        class Entry {
        public:
            explicit Entry(const TcpConnectionPtr &ptr) : weakPtr(ptr) {}

            ~Entry() {
                LOG_DEBUG<<"~Entry()";
                if (!weakPtr.expired()) {
                    LOG_DEBUG<<"call shoutdown()";
                    weakPtr.lock()->forceClose();
                }
            }

        private:
            std::weak_ptr<TcpConnection> weakPtr;
        };


    }
}


#endif //TINYWEB_TCPCONNECTION_H
