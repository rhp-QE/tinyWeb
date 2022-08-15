//
// Created by 27673 on 2022/7/4.
//

#include "EventLoopThreadPool.h"
#include <cassert>

using namespace QE;
using namespace QE::net;

EventLoopThreadPool::EventLoopThreadPool(EventLoop* mainLoop)
    : numThreads_(0)
    , pos(0)
    , mainLoop_(mainLoop)
{
    assert(mainLoop != nullptr);
}

void EventLoopThreadPool::setThreadNum(int num)
{
    assert(numThreads_ == 0);
    numThreads_ = num;
}

void EventLoopThreadPool::start()
{
    for (int i = 0; i < numThreads_; ++i) {
        threads_.push_back(std::move(std::thread(&EventLoopThreadPool::threadfunc_, this)));
    }
}

void EventLoopThreadPool::threadfunc_()
{
    auto loop = new EventLoop;
    {
        std::lock_guard<std::mutex> lockGuard(mutex_);
        loops_.push_back(loop);
    }
    loop->loop();
}

EventLoop* EventLoopThreadPool::getNextLoop()
{
    if (numThreads_ == 0) {
        return mainLoop_;
    }

    int k = ++pos;
    return loops_[k % numThreads_];
}