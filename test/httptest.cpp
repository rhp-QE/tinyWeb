#include <muduo/net/http/HttpServer.h>
#include <muduo/net/http/HttpRequest.h>
#include <muduo/net/http/HttpResponse.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <iostream>

#include <iostream>
#include <map>
#include <string>

using namespace muduo;
using namespace muduo::net;
using namespace std;

void onRequest(const HttpRequest &req, HttpResponse *resq) {
    cout << "on request" << endl;
    resq->setStatusCode(HttpResponse::k200Ok);
    resq->setStatusMessage("text/html");
    string now = Timestamp::now().toFormattedString();
    resq->setBody(now);

}

int main(int argc, char *argv[]) {
    int numThreads = 0;
    if (argc > 1) {

        muduo::Logger::setLogLevel(muduo::Logger::WARN);
        numThreads = atoi(argv[1]);
    }
    muduo::net::EventLoop loop;
    HttpServer server(&loop, muduo::net::InetAddress("127.0.0.1", 8989), "fasdf");
    server.setThreadNum(numThreads);
    server.setHttpCallback(onRequest);
    server.start();
    loop.loop();
    return 0;
}