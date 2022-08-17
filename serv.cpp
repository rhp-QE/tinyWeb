#include "test.pb.h"

#include "Reactor/EventLoop.h"
#include "Rpc/RpcServer.h"
#include <muduo/base/Logging.h>

using namespace QE;
using namespace QE::net;

typedef long long ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

namespace sudoku {

class SudokuServiceImpl : public SudokuService {
public:
    virtual void Solve(google::protobuf::RpcController* controller,
        const ::sudoku::SudokuRequest* request,
        ::sudoku::SudokuResponse* response,
        ::google::protobuf::Closure* done)
    {
        LOG_INFO << "SudokuServiceImpl::Solve";
        LOG_INFO << request->GetTypeName();
        response->set_solved(true);
        response->set_checkerboard("1234567");
        done->Run();
    }

    virtual void Gcd(google::protobuf::RpcController* controller,
        const ::sudoku::GcdRequest* request,
        ::sudoku::GcdResponse* response,
        ::google::protobuf::Closure* done)
    {
        ll val1=request->val1();
        ll val2=request->val2();
        ll res=gcd(val1,val2);
        response->set_res(res);
        done->Run();
    }
};

}

int main()
{
    LOG_INFO << "pid = " << getpid();
    EventLoop loop;
    InetAddress listenAddr(9981);
    sudoku::SudokuServiceImpl impl;
    RpcServer server(&loop, listenAddr);
    server.registerService(&impl);
    server.start();
    loop.loop();
}
