cmake_minimum_required(VERSION 3.18)

project(tinyWeb)

set(CMAKE_CXX_STANDARD 14)
set (
        src
        Server/TcpServer.cpp
        Server/EventLoopThreadPool.cpp
        Timer/TimerQueue.cpp
        Timer/Timer.cpp
        Tcp/TcpConnection.cpp
        Log/AsyncLog.cpp
        Server/Acceptor.cpp
        Reactor/EventLoop.cpp
        Reactor/Channel.cpp
        Reactor/Poller.cpp
)

set(
        memory
        Memory/alloc.h
)

set(
        http
        http/HttpServer.cpp
        http/HttpContext.cpp
        http/HttpResponse.cpp
        
)
set (
        base
        Base/Mutex.cpp
)
set (
        coroutine
        Coroutine/Coroutine.cpp
        Coroutine/Coroutine.h
)

#add_executable(tinyWeb   main.cpp)
add_executable(tinyWeb TcpTest.cpp ${src} ${coroutine})
target_link_libraries(tinyWeb muduo_net muduo_base muduo_http)
