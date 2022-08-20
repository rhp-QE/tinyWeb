cmake_minimum_required(VERSION 3.18)

project(tinyWeb)

set(CMAKE_CXX_STANDARD 14)

set (
        src

        Tcp/TcpConnection.cpp

        Timer/TimerQueue.cpp
        Timer/Timer.cpp

        Server/EventLoopThreadPool.cpp
        Reactor/EventLoop.cpp
        Reactor/Channel.cpp 
        Reactor/Poller.cpp

        Log/AsyncLog.cpp
        Base/copyable
        Base/noncopyable
)

set (
        server 
        Server/TcpServer.cpp
        Server/TcpClient.cpp 
        Server/Acceptor.cpp
        Server/Connector.cpp    
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
        coroutine
        Coroutine/Coroutine.cpp
)

set(
        rpc
        Rpc/RpcServer.cpp
        Rpc/RpcChannal.cpp
        Rpc/RpcCodec.cpp
        Rpc/ProtobufCodec.cpp
        Rpc/rpc.pb.cc
)

#add_executable(tinyWeb   main.cpp)
add_definitions("-Wall -g")
add_executable(tinyWeb TcpTest.cpp ${server} ${src} )
add_executable(tinyWeb1 TcpCli.cc ${server} ${src} )
add_executable(RpcServer serv.cpp test.pb.cc ${rpc} ${server} ${src}  )
add_executable(RpcClient cli.cpp test.pb.cc ${rpc} ${server} ${src} )
target_link_libraries(tinyWeb muduo_net muduo_base )
target_link_libraries(tinyWeb1 muduo_net muduo_base )
target_link_libraries(RpcServer muduo_net muduo_base  protobuf)
target_link_libraries(RpcClient muduo_net muduo_base  protobuf)
