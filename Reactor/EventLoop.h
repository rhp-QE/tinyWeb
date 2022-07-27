//
// Created by 27673 on 2022/7/1.
//

#ifndef TINYWEB_EVENTLOOP_H
#define TINYWEB_EVENTLOOP_H

/**成员变量
 * 1）TimeQueue; 组合
 * 2) Poller  ;  组合
 * 3）__thread Eventloop *;  只有所属线程才可以获得
 * 4）所属线程的id
 * 5)
 */

//#include "../exhead.h"

#include "Poller.h"
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <boost/any.hpp>
#include "../Timer/TimeId.h"
#include "Channel.h"
#include "Poller.h"

namespace QE {
    namespace net {
        class TimerQueue;
        class Channel;
        class Poller;

        class EventLoop : noncopyable {
        public:
            typedef std::function<void()> Func;


            EventLoop();

            ~EventLoop();

            void loop();

            void quit();

            void runInLoop(Func cb);

            size_t queueSize();

            TimerId runAt(Timestamp time, TimerCallback cb);

            TimerId runAfter(double delay, TimerCallback cb);

            TimerId runEvery(double interval, TimerCallback cb);

            void cancelTimer(TimerId timerId);


            //internel usage
            void wakeup() const;

            void updateChannel(Channel *channel);

            void removeChannel(Channel *channel);

            bool hasChannel(QE::net::Channel *channel);

            void queueInLoop(Func cb);


            // pid_t threadId() const { return threadId_; }
            void assertInLoopThread() {
                if (!isInLoopThread()) {
                    abortNotInLoopThread();
                }
            }

            bool isInLoopThread() const { return threadId_ == std::this_thread::get_id(); }

            // bool callingPendingFunctors() const { return callingPendingFunctors_; }
            bool eventHandling() const { return eventHandling_; }

            void setContext(const boost::any &context) { context_ = context; }

            const boost::any &getContext() const { return context_; }

            boost::any *getMutableContext() { return &context_; }

            static EventLoop *getEventLoopOfCurrentThread();

        private:
            void abortNotInLoopThread();

            void handleRead() const;  // waked up
            void doPendingFunctors();

            void printActiveChannels() const; // DEBUG

            typedef std::vector<Channel *> ChannelList;

            bool looping_; /* atomic */
            std::atomic<bool> quit_;
            bool eventHandling_; /* atomic */
            bool callingPendingFunctors_; /* atomic */
            int64_t iteration_;
            const std::thread::id threadId_;
            Timestamp pollReturnTime_;
            std::unique_ptr<Poller> poller_;

            std::unique_ptr<TimerQueue> timerQueue_;
            int wakeupFd_;
            // unlike in TimerQueue, which is an internal class,
            // we don't expose Channel to client.
            std::unique_ptr<Channel> wakeupChannel_;
            boost::any context_;

            // scratch variables
            ChannelList activeChannels_;
            Channel *currentActiveChannel_;

            std::mutex mutex_;
            std::vector<Func> pendingFunctors_ ;

        };
    }
}


#endif //TINYWEB_EVENTLOOP_H
