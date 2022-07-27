//
// Created by 27673 on 2022/6/30.
//

#include "Timer.h"

#include <utility>


using namespace QE;
using namespace QE::net;

std::atomic_uint64_t Timer::s_numCreated_;
Timer::Timer(TimerCallback timerCallback, Timestamp when, double interval) :
        timerCallback_(std::move(timerCallback)),
        expiration_(when),
        interval_(interval),
        repeat_(interval > 0.0),
        sequence_(++Timer::s_numCreated_) {}


void Timer::restart(Timestamp now) {
    if(repeat_){
        expiration_= muduo::addTime(now,interval_);
    }else{
        expiration_=Timestamp::invalid();
    }
}


void Timer::run() {
    timerCallback_();
}


