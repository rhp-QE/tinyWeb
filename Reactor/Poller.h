/*
 * @Author: QE 2767360276@qq.com
 * @Date: 2022-07-29 12:11:07
 * @LastEditors: QE 2767360276@qq.com
 * @LastEditTime: 2022-08-05 02:09:27
 * @FilePath: /tinyWeb/Reactor/Poller.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
