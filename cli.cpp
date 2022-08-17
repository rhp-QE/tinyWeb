#include "Reactor/Channel.h"
#include "test.pb.h"

#include "Base/noncopyable.h"
#include "Reactor/EventLoop.h"
#include "Rpc/RpcChannal.h"
#include "Server/TcpClient.h"
#include "Tcp/TcpConnection.h"
#include <functional>
#include <google/protobuf/stubs/callback.h>
#include <muduo/base/Logging.h>
#include <muduo/net/InetAddress.h>
#include <stdio.h>
#include <unistd.h>

using namespace QE;
using namespace QE::net;

sudoku::GcdRequest* re = new sudoku::GcdRequest();
sudoku::GcdResponse* rq = new sudoku::GcdResponse();
void func1();
class so : public google::protobuf::Closure {
    typedef std::function<void(void)> callBack;

public:
    void set(const callBack& val) { back_ = val; }
    void Run()
    {
        back_();
    }

private:
    callBack back_;
};

class RpcClient : public noncopyable {
public:
    RpcClient(EventLoop* loop, const InetAddress& serverAddr)
        : loop_(loop)
        , client_(loop, serverAddr, "RpcClient")
        , channel(new RpcChannel)
        , stub_(channel.get())
    {
        client_.setConnectionCallback(
            [this](const TcpConnectionPtr& conn) {
                this->onConnection(conn);
            });

        client_.setMessageCallback(
            [this](const TcpConnectionPtr& conn,
                Buffer* buf,
                Timestamp receiveTime) {
                channel->onMessage(conn, buf, receiveTime);
            });

        // client_.enableRetry();
    }

    void connect()
    {
        client_.connect();
    }

    RpcChannelPtr get() { return channel; }

private:
    void onConnection(const TcpConnectionPtr& conn)
    {
        if (conn->connected()) {
            channel->setConnection(conn);
            func1();
        } else {
            loop_->quit();
        }
    }

    void solved(sudoku::SudokuResponse* resp)
    {
        LOG_INFO << "called ; now is : " << Timestamp::now().toString();
        LOG_INFO << "solved:\n"
                 << resp->DebugString();
        client_.disconnect();
    }

    void solve(sudoku::GcdResponse* resp)
    {
        LOG_INFO << "called ; now is : " << Timestamp::now().toString();
        LOG_INFO << "solved:\n"
                 << resp->DebugString();
        client_.disconnect();
    }

    EventLoop* loop_;
    TcpClient client_;
    RpcChannelPtr channel;
    sudoku::SudokuService::Stub stub_;
};

EventLoop loop;
InetAddress serverAddr("127.0.0.1", 9981);
RpcClient rpcClient(&loop, serverAddr);

void func1()
{
    sudoku::SudokuService::Stub stub(rpcClient.get().get());
    re->set_val1(90);
    re->set_val2(34);
    so* ss = new so();
    ss->set([]() { LOG_INFO << "接替成功 " << rq->DebugString(); });
    stub.Gcd(nullptr, re, rq, ss);
}

int main(int argc, char* argv[])
{
    // LOG_INFO << "pid = " << getpid();

    rpcClient.connect();
    LOG_INFO << "loop brefor";
    loop.loop();

    google::protobuf::ShutdownProtobufLibrary();
}
