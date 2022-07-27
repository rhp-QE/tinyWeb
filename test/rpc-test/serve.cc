#include "test.pb.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/protorpc/RpcServer.h>
#include <unistd.h>

using namespace ::muduo;
using namespace ::muduo::net;


namespace mmath {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    class MmathImpl : public SudokuService {
        void Solve(::google::protobuf::RpcController *controller,
                   const ::mmath::SudokuRequest *request,
                   ::mmath::SudokuResponse *response,
                   ::google::protobuf::Closure *done) override {
            response->set_solved(true);
            int res = gcd(request->val_1(), request->val_2());
            response->set_res(res);
            done->Run();
        }
    };

    class NodeImpl : public SudokuService {
        void Solve(::google::protobuf::RpcController *controller,
                   const ::mmath::SudokuRequest *request,
                   ::mmath::SudokuResponse *response,
                   ::google::protobuf::Closure *done) override {
            response->set_solved(true);
            int a = request->val_1();
            int b = request->val_2();
            //--------------------------------
            int res = a * b;
            response->set_res(res);


            done->Run();
        }
    };
}

 
int main() {
    EventLoop loop;
    InetAddress listenAddr(8989);
    mmath::MmathImpl impl;
    mmath::NodeImpl im2;
    RpcServer server(&loop, listenAddr);
    server.registerService(&impl);
    server.registerService(&im2);
    server.start();
    loop.loop();
    google::protobuf::ShutdownProtobufLibrary();
}