//
// Created by 27673 on 2022/6/29.
//

#ifndef TINYWEB_EXHEAD_H
#define TINYWEB_EXHEAD_H

//本项目 会使用 muduo 中的一些基础 组件
#include <muduo/base/noncopyable.h>
#include <muduo/base/copyable.h>
#include <muduo/base/FileUtil.h>
#include <muduo/base/LogFile.h>
#include <muduo/base/LogStream.h>
#include <muduo/base/Timestamp.h>
#include <muduo/base/Logging.h>
#include <functional>
#include <muduo/net/Buffer.h>
#include <muduo/net//InetAddress.h>
#include <muduo/net/Socket.h>
#include <muduo/net/SocketsOps.h>


namespace QE{
    typedef muduo::noncopyable noncopyable;
    typedef muduo::noncopyable copyable;
    typedef muduo::LogFile LogFile;
    typedef muduo::Timestamp Timestamp;
    typedef muduo::Logger Logger;






    namespace detail{
        typedef muduo::detail::FixedBuffer<muduo::detail::kLargeBuffer> LogLargeLBuffer;
        typedef muduo::detail::FixedBuffer<muduo::detail::kSmallBuffer> LogSmallLBuffer;
    }
    namespace FileUtil{
        typedef muduo::FileUtil::AppendFile AppendFile;
    }



    namespace net{
        typedef muduo::net::Socket Socket;
        typedef muduo::net::InetAddress InetAddress;
        typedef muduo::net::Buffer Buffer;
        //class Buffer;
        class TcpConnection;
        typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
        typedef std::function<void()> TimerCallback;
        typedef std::function<void (const TcpConnectionPtr&)> ConnectionCallback;
        typedef std::function<void (const TcpConnectionPtr&)> CloseCallback;
        typedef std::function<void (const TcpConnectionPtr&)> WriteCompleteCallback;
        typedef std::function<void (const TcpConnectionPtr&, size_t)> HighWaterMarkCallback;

// the data has been read to (buf, len)
        typedef std::function<void (const TcpConnectionPtr&,
                                    Buffer*,
                                    Timestamp)> MessageCallback;

        void defaultConnectionCallback(const TcpConnectionPtr& conn);
        void defaultMessageCallback(const TcpConnectionPtr& conn,
                                    Buffer* buffer,
                                    Timestamp receiveTime);
    }

}

#endif //TINYWEB_EXHEAD_H
