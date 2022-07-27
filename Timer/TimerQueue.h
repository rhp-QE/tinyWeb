//
// Created by 27673 on 2022/6/30.
//

#ifndef TINYWEB_TIMERQUEUE_H
#define TINYWEB_TIMERQUEUE_H

#include "../exhead.h"
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "../Reactor/Channel.h"



//该类用于管理定时器 , 注意只在 eventloop 中注册一个最近的时间 ， 时间到期后再 注册下一个

// -------------------成员变量-----------
//  --set 维护的定时器列表  方便 定时器的查寻
//        是定时器的拥有者  直接管理其生命周期
//  -- 该定时器队列的 channel
//  -- timerfd
//  -- 该定时器队列所属于的 Eventloop  (使用 弱指针维护)
#include "TimeId.h"

namespace QE {
    namespace net {
        class EventLoop;
        class Channel;
        class Timer;

        class TimerQueue {


        public:
            explicit TimerQueue(EventLoop *loop);

            ~TimerQueue();

            ///
            /// Schedules the callback to be run at given time,
            /// repeats if @c interval > 0.0.
            ///
            /// Must be thread safe. Usually be called from other threads.
            TimerId addTimer(TimerCallback cb,
                             Timestamp when,
                             double interval);

            void cancel(TimerId timerId);

        private:

            typedef std::pair<Timestamp, TimerId> Entry;
            typedef std::set<Entry> TimerList;
            typedef std::unordered_map<TimerId, std::unique_ptr<Timer>> ActiveTimerList;


            void addTimerInLoop(Timer *timer);

            void cancelInLoop(TimerId timerId);

            //当timefd 触发时调用
            void handleRead();

            //获取 并 移除过期的定时器
            std::vector<std::unique_ptr<Timer>> getExpired(Timestamp now);

            void reset(std::vector<std::unique_ptr<Timer>> exptr , Timestamp now);

            bool insert(std::unique_ptr<Timer> timer);

            EventLoop *loop_;
            const int timerfd_;
            Channel timerfdChannel_;

            //按时间排序的 定时器
            TimerList timers_;

            //存在的定时器  unordered_set 维护  便于判断该定时器是否存在
            ActiveTimerList activeTimers_;
            bool callingExpiredTimers_; /* atomic */

            //记录已经取消了的定时器  采用懒惰删除法
            std::unordered_set<TimerId> cancelingTimers_;

        };
    }
}


#endif //TINYWEB_TIMERQUEUE_H
