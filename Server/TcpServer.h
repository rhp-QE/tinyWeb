//
// Created by 27673 on 2022/7/3.
//

#ifndef TINYWEB_TCPSERVER_H
#define TINYWEB_TCPSERVER_H

#include "../Reactor/EventLoop.h"
#include "../Tcp/TcpConnection.h"
#include "../exhead.h"
#include "Acceptor.h"
#include "EventLoopThreadPool.h"
#include <atomic>
#include <map>
#include <string>

namespace QE {
namespace net {
    class EventLoop;

    class EventLoopThreadPool;

    class TcpConnection;

    using std::string;

    class TcpServer {
    public:
        typedef std::function<void(EventLoop*)> ThreadInitCallback;
        enum Option {
            kNoReusePort,
            kReusePort,
        };

        // TcpServer(EventLoop* loop, const InetAddress& listenAddr);
        TcpServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg, int outtime = -1,
            Option option = kNoReusePort, bool usePoll = false);

        ~TcpServer(); // force out-line dtor, for std::unique_ptr members.

        const string& ipPort() const { return ipPort_; }

        const string& name() const { return name_; }

        EventLoop* getLoop() const { return loop_; }

        /// Set the number of threads for handling input.
        ///
        /// Always accepts new connection in loop's thread.
        /// Must be called before @c start
        /// @param numThreads
        /// - 0 means all I/O in loop's thread, no thread will created.
        ///   this is the default value.
        /// - 1 means all I/O in another thread.
        /// - N means a thread pool with N threads, new connections
        ///   are assigned on a round-robin basis.
        /// valid after calling start()
        std::shared_ptr<EventLoopThreadPool> threadPool() { return threadPool_; }

        /// Starts the server if it's not listening.
        ///
        /// It's harmless to call it multiple times.
        /// Thread safe.
        void start();

        /// Set connection callback.
        /// Not thread safe.
        void setConnectionCallback(const ConnectionCallback& cb) { connectionCallback_ = cb; }

        /// Set message callback.
        /// Not thread safe.
        void setMessageCallback(const MessageCallback& cb) { messageCallback_ = cb; }

        /// Set write complete callback.
        /// Not thread safe.
        void setWriteCompleteCallback(const WriteCompleteCallback& cb) { writeCompleteCallback_ = cb; }

        //设置EventLoopPool 的线程数目
        void setThreadNum(int num) { threadPool_->setThreadNum(num); }

    private:
        /// Not thread safe, but in loop
        void newConnection(int sockfd, const InetAddress& peerAddr);

        /// Thread safe.
        void removeConnection(const TcpConnectionPtr& conn);

        /// Not thread safe, but in loop
        void removeConnectionInLoop(const TcpConnectionPtr& conn);

        typedef std::map<string, TcpConnectionPtr> ConnectionMap;

        EventLoop* loop_; // the acceptor loop
        const string ipPort_;
        const string name_;
        std::unique_ptr<Acceptor> acceptor_; // avoid revealing Acceptor
        std::shared_ptr<EventLoopThreadPool> threadPool_;
        ConnectionCallback connectionCallback_;
        MessageCallback messageCallback_;
        WriteCompleteCallback writeCompleteCallback_;
        ThreadInitCallback threadInitCallback_;
        std::atomic<int> started_;
        // always in loop thread
        int nextConnId_;
        ConnectionMap connections_;
        int outtime;

        //超时管理模块
        WeakConnectionList weakConnectionList;

        //定时检查函数 每秒踢掉到期连接
        void outTime()
        {
            //                LOG_INFO << "call outTime() " << weakConnectionList.front().size();
            EntryPtr pptr;
            if (!weakConnectionList.front().empty()) {
                pptr = *weakConnectionList.front().begin();

                LOG_DEBUG << weakConnectionList.front().begin()->use_count();
            }
            weakConnectionList.pop();
            LOG_DEBUG << pptr.use_count() << "-----";
            weakConnectionList.push(Bucket());
        }

        //新连接到来 放到末尾
        void addEntry(const TcpConnectionPtr& conn)
        {
            EntryPtr entryPtr(new Entry(conn));
            conn->setWeakEntryPtr(entryPtr);
            weakConnectionList.back().insert(entryPtr);
            LOG_DEBUG << "call add Entry()";
        };

        //产生一个新的共享指针 放到轮盘末尾
        void updateEntry(const TcpConnectionPtr& conn)
        {
            EntryPtr ptr = conn->getWeakEntry().lock();
            if (ptr) {
                weakConnectionList.back().insert(ptr);
            }
        }

        //当消息到来时的回调
        void MessageCallbackTcpServer(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp timestamp)
        {
            messageCallback_(conn, buffer, timestamp);
            if (outtime >= 1) {
                updateEntry(conn);
            }
        }
    };

}
}

#endif // TINYWEB_TCPSERVER_H
