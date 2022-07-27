//
// Created by 27673 on 2022/7/3.
//

#ifndef TINYWEB_ACCEPTOR_H
#define TINYWEB_ACCEPTOR_H

#include <muduo/net/Socket.h>
#include "../Reactor/Channel.h"
#include "../Reactor/EventLoop.h"
#include <muduo/net/InetAddress.h>


namespace QE {
    namespace net {


        class EventLoop;

        class Acceptor : muduo::noncopyable {
        public:
            typedef std::function<void(int sockfd, const InetAddress &)> NewConnectionCallback;

            Acceptor(EventLoop *loop, const InetAddress &listenAddr, bool reuseport);

            ~Acceptor();

            void setNewConnectionCallback(const NewConnectionCallback &cb) { newConnectionCallback_ = cb; }

            void listen();

            bool listening() const { return listening_; }

            // Deprecated, use the correct spelling one above.
            // Leave the wrong spelling here in case one needs to grep it for error messages.
            // bool listenning() const { return listening(); }

        private:
            void handleRead();

            EventLoop *loop_;
            muduo::net::Socket acceptSocket_;
            Channel acceptChannel_;
            NewConnectionCallback newConnectionCallback_;
            bool listening_;
            int idleFd_;
        };
    }
}


#endif //TINYWEB_ACCEPTOR_H
