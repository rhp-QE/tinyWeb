
#ifndef QE_NET_PROTORPC_RPCSERVER_H
#define QE_NET_PROTORPC_RPCSERVER_H

#include "../Server/TcpServer.h"

//前向声明
namespace google {
namespace protobuf {
    class Service;
} // namespace protobuf
} // namespace google

namespace QE {
namespace net {

    class RpcServer {
    public:
        RpcServer(EventLoop* loop,
            const InetAddress& listenAddr);

        void setThreadNum(int numThreads)
        {
            server_.setThreadNum(numThreads);
        }

        void registerService(::google::protobuf::Service*);
        void start();

    private:
        void onConnection(const TcpConnectionPtr& conn);

        // void onMessage(const TcpConnectionPtr& conn,
        //                Buffer* buf,
        //                Timestamp time);

        TcpServer server_;
        std::map<std::string, ::google::protobuf::Service*> services_;
    };

} // namespace net
} // namespace muduo

#endif // MUDUO_NET_PROTORPC_RPCSERVER_H
