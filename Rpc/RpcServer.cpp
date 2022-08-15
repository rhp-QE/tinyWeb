#include "RpcServer.h"
#include "RpcChannal.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>

using namespace QE;
using namespace QE::net;

RpcServer::RpcServer(EventLoop* loop,
    const InetAddress& listenAddr)
    : server_(loop, listenAddr, "RpcServer")
{
    server_.setConnectionCallback(
        [this](const TcpConnectionPtr& conn) {
            this->onConnection(conn);
        });
}

void RpcServer::registerService(google::protobuf::Service* service)
{
    const google::protobuf::ServiceDescriptor* desc = service->GetDescriptor();
    services_[desc->full_name()] = service;
}

void RpcServer::start()
{
    server_.start();
}

void RpcServer::onConnection(const TcpConnectionPtr& conn)
{
    LOG_INFO << "RpcServer - " << conn->peerAddress().toIpPort() << " -> "
             << conn->localAddress().toIpPort() << " is "
             << (conn->connected() ? "UP" : "DOWN");
    if (conn->connected()) {
        RpcChannelPtr channel(new RpcChannel(conn));
        channel->setServices(&services_);
        conn->setMessageCallback(
            [channel](const TcpConnectionPtr& conn,
                Buffer* buf,
                Timestamp receiveTime) {
                channel->onMessage(conn, buf, receiveTime);
            });
        conn->setContext(channel);
    } else {
        conn->setContext(RpcChannelPtr());
        // FIXME:
    }
}

// void RpcServer::onMessage(const TcpConnectionPtr& conn,
//                           Buffer* buf,
//                           Timestamp time)
// {
//   RpcChannelPtr& channel = boost::any_cast<RpcChannelPtr&>(conn->getContext());
//   channel->onMessage(conn, buf, time);
// }
