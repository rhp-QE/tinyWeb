#include "test.pb.h"

#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/InetAddress.h"
#include "muduo/net/TcpClient.h"
#include "muduo/net/TcpConnection.h"
#include "muduo/net/protorpc/RpcChannel.h"

#include <stdio.h>

#include <unistd.h>

using namespace muduo;
using namespace muduo::net;

class RpcClient : noncopyable {
public:
    RpcClient(EventLoop *loop, const InetAddress &serverAddr)
            : loop_(loop),
              client_(loop, serverAddr, "RpcClient"),
              channel_(new RpcChannel),
              stub_(get_pointer(channel_)) {
        client_.setConnectionCallback(
                std::bind(&RpcClient::onConnection, this, _1));
        client_.setMessageCallback(
                std::bind(&RpcChannel::onMessage, get_pointer(channel_), _1, _2, _3));
        // client_.enableRetry();
    }

    void connect() {
        client_.connect();
    }

private:
    void onConnection(const TcpConnectionPtr &conn) {
        if (conn->connected()) {
            //channel_.reset(new RpcChannel(conn));
            channel_->setConnection(conn);
            mmath::SudokuRequest request;
            int a, b;
            scanf("%d%d", &a, &b);
            request.set_val_1(a);
            request.set_val_2(b);
            ::mmath::SudokuResponse *response = new mmath::SudokuResponse;

            stub_.Solve(NULL, &request, response, NewCallback(this, &RpcClient::solved, response));
        } else {
            loop_->quit();
        }
    }

    void solved(mmath::SudokuResponse *resp) {
        LOG_INFO << "solved:\n" << resp->DebugString();
        client_.disconnect();
    }

    EventLoop *loop_;
    TcpClient client_;
    RpcChannelPtr channel_;
    mmath::SudokuService::Stub stub_;

};

int main(int argc, char *argv[]) {

    EventLoop loop;
    InetAddress serverAddr("127.0.0.1", 8989);
    RpcClient rpcClient(&loop, serverAddr);
    rpcClient.connect();
    loop.loop();
    google::protobuf::ShutdownProtobufLibrary();
}

