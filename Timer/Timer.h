//
// Created by 27673 on 2022/6/30.
//

#ifndef TINYWEB_TIMER_H
#define TINYWEB_TIMER_H

#include "../exhead.h"
#include <atomic>
//封装了一个定时器类
//主要包括了
//定时器的超时时间
//是否是 重复定时器
//重复周期
//定时器的回调函数
//定时器 编号
//静态成员  已近分配的编号

//-----------成员方法------------------
//1） 上卖弄所有成员的访问方法
//2） run 函数  供外界调用

namespace QE {
    namespace net {
        class Timer {
        public:
            Timer(TimerCallback timerCallback, Timestamp when, double interval);

            ~Timer() { LOG_DEBUG << "~ Timer()"; }

            Timestamp expiration() const { return expiration_; }

            bool repeat() const { return repeat_; }

            int64_t sequence() const { return sequence_; }

            void restart(Timestamp now);

            static int64_t numCreated() { return s_numCreated_; }

            void run();

        private:
            Timestamp expiration_;
            const bool repeat_;
            double interval_;
            const TimerCallback timerCallback_;
            const int64_t sequence_;
            static std::atomic_uint64_t s_numCreated_;

        };
    }
}


#endif //TINYWEB_TIMER_H
