//
// Created by 27673 on 2022/7/4.
//

#ifndef TINYWEB_EVENTLOOPTHREADPOOL_H
#define TINYWEB_EVENTLOOPTHREADPOOL_H

#include "../Reactor/EventLoop.h"
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>


namespace QE {
    namespace net {
        class EventLoop;

        class EventLoopThreadPool {
        public:
            EventLoopThreadPool(EventLoop *mainLoop);
            void start();
            void setThreadNum(int num);
            EventLoop*  getNextLoop();
        private:
            int numThreads_;
            std::atomic<int> pos;
            std::mutex mutex_;
            std::vector<EventLoop*> loops_;
            EventLoop* mainLoop_;
            std::vector<std::thread> threads_;

            void threadfunc_();
        };
    }
}


#endif //TINYWEB_EVENTLOOPTHREADPOOL_H
