//
// Created by 27673 on 2022/7/4.
//

#include "EventLoopThreadPool.h"

using namespace QE;
using namespace QE::net;

EventLoopThreadPool::EventLoopThreadPool(int num) : numThreads_(num), pos(0) {
    for (int i = 0; i < num; ++i) {
        threads_.push_back(std::move(std::thread(&EventLoopThreadPool::threadfunc_, this)));
    }
}

void EventLoopThreadPool::threadfunc_() {
    auto loop = new EventLoop;
    {
        std::lock_guard<std::mutex> lockGuard(mutex_);
        loops_.push_back(loop);
    }
    loop->loop();
}

EventLoop* EventLoopThreadPool::getNextLoop() {
    if (numThreads_ == 0) return nullptr;
    int k = ++pos;
    return loops_[k % numThreads_];
}