#include "Server/TcpServer.h"
#include "Tcp/TcpConnection.h"
#include <muduo/base/Logging.h>

using namespace std;
using namespace QE;
using namespace QE::net;

void onConnection(const TcpConnectionPtr& conn)
{
    if (conn->connected()) {
        // conn->shutdown();
        conn->setTcpNoDelay(true);
    }
}

void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp)
{
    LOG_INFO << "get message";
    auto res = buf->peek();

    printf("%s\n", res);

    conn->send(buf);
}

void test() { }

int main()
{
    InetAddress address("127.0.0.1", 9090);
    EventLoop loop;
    TcpServer server(&loop, address, "ECHO", 10);
    //注册回调
    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    //开启服务
    server.start();
    loop.loop();
}
