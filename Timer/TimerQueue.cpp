//
// Created by 27673 on 2022/6/30.
//

#include "TimerQueue.h"
#include "Timer.h"
#include <sys/timerfd.h>
#include <memory>
#include <iostream>

using std::cout;

//------------------------------------------------------------------
namespace QE {
    namespace net {
        namespace detail {

            int createTimerfd() {
                //非阻塞  +  无法fork 获得  +  修改系统时间不会触发
                int timerfd = ::timerfd_create(CLOCK_MONOTONIC,
                                               TFD_NONBLOCK | TFD_CLOEXEC);
                if (timerfd < 0) {
                    LOG_SYSFATAL << "Failed in timerfd_create";
                }
                return timerfd;
            }

            struct timespec howMuchTimeFromNow(Timestamp when) {
                int64_t microseconds = when.microSecondsSinceEpoch()
                                       - Timestamp::now().microSecondsSinceEpoch();
                if (microseconds < 100) {
                    microseconds = 100;
                }
                struct timespec ts;
                ts.tv_sec = static_cast<time_t>(
                        microseconds / Timestamp::kMicroSecondsPerSecond);
                ts.tv_nsec = static_cast<long>(
                        (microseconds % Timestamp::kMicroSecondsPerSecond) * 1000);
                return ts;
            }

            void readTimerfd(int timerfd, Timestamp now) {
                uint64_t howmany;
                ssize_t n = ::read(timerfd, &howmany, sizeof howmany);
                LOG_TRACE << "TimerQueue::handleRead() " << howmany << " at " << now.toString();
                if (n != sizeof howmany) {
                    LOG_ERROR << "TimerQueue::handleRead() reads " << n << " bytes instead of 8";
                }
            }

            void resetTimerfd(int timerfd, Timestamp expiration) {
                // wake up loop by timerfd_settime()
                struct itimerspec newValue;
                struct itimerspec oldValue;
                memset(&newValue, 0, sizeof newValue);
                memset(&oldValue, 0, sizeof oldValue);
                newValue.it_value = howMuchTimeFromNow(expiration);
                int ret = ::timerfd_settime(timerfd, 0, &newValue, &oldValue);
                if (ret) {
                    LOG_SYSERR << "timerfd_settime()";
                }
            }

        }  // namespace detail
    }  // namespace net
}  // namespace QE
//-------------------------------------------------------------
using namespace QE;
using namespace QE::net;
using namespace QE::net::detail;

TimerQueue::TimerQueue(EventLoop *loop)
        : loop_(loop),
          timerfd_(createTimerfd()),
          timerfdChannel_(loop, timerfd_),
          callingExpiredTimers_(false) {
    timerfdChannel_.setReadCallback(
            std::bind(&TimerQueue::handleRead, this));
    // we are always reading the timerfd, we disarm it with timerfd_settime.
    timerfdChannel_.enableReading();
}

TimerQueue::~TimerQueue() {
    timerfdChannel_.disableAll();  // 取消 poller 关注其所有事件
    timerfdChannel_.remove();  //使其从 loop poller 中移除
    ::close(timerfd_);       //关闭文件描述符
}

/**
 *  向 定时器队列中插入定时器
 * @param timer
 * @return  定时器队列中的最早 dealline 是否改变
 */
bool TimerQueue::insert(std::unique_ptr<Timer> timer) {
    loop_->assertInLoopThread();
    assert(timers_.size() == activeTimers_.size());
    bool earliestChanged = false;
    Timestamp when = timer->expiration();
    TimerId id = timer->sequence();
    if (timers_.size() == 0 || when < timers_.begin()->first) {
        earliestChanged = true;
    }
    {
        auto res = timers_.insert(Entry(timer->expiration(), timer->sequence()));
        assert(res.second);
    }
    {
        auto result = activeTimers_.insert({timer->sequence(), std::move(timer)});
        assert(result.second);
    }
    assert(timers_.size() == activeTimers_.size());
    return earliestChanged;
}

std::vector<std::unique_ptr<Timer>> TimerQueue::getExpired(Timestamp now) {
    Entry sentry(now, INT64_MAX);
    assert(activeTimers_.size() == timers_.size());

    std::vector<std::unique_ptr<Timer>> expired;
    auto end = timers_.lower_bound(sentry);
    assert(end == timers_.end() || now < end->first);


    for (auto it = timers_.begin(); it != end; ++it) {
        expired.push_back(std::move(activeTimers_[it->second]));
        activeTimers_.erase(it->second);
    }
    timers_.erase(timers_.begin(), end);

    return expired;

}

/**
 * 将不是一次性定时器的  重置时间
 * @param expired
 * @param now
 */
void TimerQueue::reset(std::vector<std::unique_ptr<Timer>> expired, Timestamp now) {
    Timestamp nextExpire;
    for (auto &it : expired) {
        if (it->repeat()
            && cancelingTimers_.find(it->sequence()) == cancelingTimers_.end()) {
            it->restart(now);
            insert(std::move(it));
        }
    }
    expired.clear();

    if (!timers_.empty()) {
        nextExpire = timers_.begin()->first;
    }
    if (nextExpire.valid()) {
        resetTimerfd(timerfd_, nextExpire);
    }
}

TimerId TimerQueue::addTimer(TimerCallback cb,
                             Timestamp when,
                             double interval) {
    Timer *timer = new Timer(std::move(cb), when, interval);
    loop_->runInLoop(
            std::bind(&TimerQueue::addTimerInLoop, this, timer));
    return TimerId(timer->sequence());
}

void TimerQueue::addTimerInLoop(Timer *timer) {
    loop_->assertInLoopThread();
    std::unique_ptr<Timer> ptr(timer);
    auto expiration = timer->expiration();
    bool earliestChanged = insert(std::move(ptr));
    if (earliestChanged) {
        resetTimerfd(timerfd_, expiration);
    }
}

void TimerQueue::cancel(TimerId timerId) {
    loop_->runInLoop(
            std::bind(&TimerQueue::cancelInLoop, this, timerId));
}

void TimerQueue::cancelInLoop(TimerId timerId) {
    loop_->assertInLoopThread();
    assert(activeTimers_.size() == timers_.size());
    auto it = activeTimers_.find(timerId);
    if (it != activeTimers_.end()) {
        {
            size_t n = timers_.erase(Entry{(*it).second->expiration(), timerId});
            assert(n == 1);
        }
        {
            size_t n = activeTimers_.erase(timerId);
            assert(n == 1);
        }
    } else if (callingExpiredTimers_) {
        cancelingTimers_.insert(timerId);
    }

    assert(activeTimers_.size() == timers_.size());

}

void TimerQueue::handleRead() {
    loop_->assertInLoopThread();
    Timestamp now(Timestamp::now());
    readTimerfd(timerfd_, now);

    auto expiredTimers_ = getExpired(now);

    callingExpiredTimers_ = true;
    cancelingTimers_.clear();
    // safe to callback outside critical section
    for (const auto &it : expiredTimers_) {
        it->run();
    }
    callingExpiredTimers_ = false;

    reset(std::move(expiredTimers_), now);
}