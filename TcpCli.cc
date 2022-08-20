#include "Reactor/EventLoop.h"
#include "Server/TcpClient.h"
#include "exhead.h"
using namespace QE;
using namespace QE::net;

int main(){
    EventLoop loop;
    InetAddress addr("192.168.47.1",6789);
    TcpClient client(&loop,addr,"test");
    client.connect();
    loop.loop();
}