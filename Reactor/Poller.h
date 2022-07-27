//
// Created by 27673 on 2022/7/1.
//

#ifndef TINYWEB_POLLER_H
#define TINYWEB_POLLER_H

#include "../exhead.h"
#include <vector>
#include "EventLoop.h"
#include "Channel.h"

#include <map>
#include <sys/epoll.h>

namespace QE {
    namespace net {
        class Channel;

        class EventLoop;

///
/// Base class for IO Multiplexing
///
/// This class doesn't own the Channel objects.
        class Poller : noncopyable {
        public:
            typedef std::vector<Channel *> ChannelList;

            Poller(EventLoop *loop);

            ~Poller();

            /// Polls the I/O events.
            /// Must be called in the loop thread.
            Timestamp poll(int timeoutMs, ChannelList *activeChannels);

            /// Changes the interested I/O events.
            /// Must be called in the loop thread.
            void updateChannel(Channel *channel);

            /// Remove the channel, when it destructs.
            /// Must be called in the loop thread.
            void removeChannel(Channel *channel);

            bool hasChannel(Channel *channel) const;

            void assertInLoopThread() const;

        protected:
            typedef std::map<int, Channel *> ChannelMap;
            ChannelMap channels_;

        private:

            EventLoop *ownerLoop_;
            static const int kInitEventListSize = 16;

            static const char *operationToString(int op);

            void fillActiveChannels(int numEvents,
                                    ChannelList *activeChannels) const;

            void update(int operation, Channel *channel) const;

            typedef std::vector<struct epoll_event> EventList;

            int epollfd_;
            EventList events_;
        };

    }  // namespace net
}  // namespace muduo


#endif //TINYWEB_POLLER_H
