//
// Created by 27673 on 2022/7/1.
//

#include "EventLoop.h"
#include <algorithm>
#include "Poller.h"
#include "../Timer/TimerQueue.h"
#include <muduo/net/SocketsOps.h>


#include <csignal>
#include <sys/eventfd.h>
#include <unistd.h>

namespace QE {
    namespace net {

        //每个线程 都有独一份，指向loop
        __thread EventLoop *t_loopInThisThread = 0;

        const int kPollTimeMs = 10000;

        int createEventfd() {
            int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
            if (evtfd < 0) {
                LOG_SYSERR << "Failed in eventfd";
                abort();
            }
            return evtfd;
        }

#pragma GCC diagnostic ignored "-Wold-style-cast"

        class IgnoreSigPipe {
        public:
            IgnoreSigPipe() {
                ::signal(SIGPIPE, SIG_IGN);
                // LOG_TRACE << "Ignore SIGPIPE";
            }
        };

#pragma GCC diagnostic error "-Wold-style-cast"

        IgnoreSigPipe initObj;
    }
}  // namespace


using namespace QE;
using namespace QE::net;

EventLoop *EventLoop::getEventLoopOfCurrentThread() {
    return t_loopInThisThread;
}


EventLoop::EventLoop()
        : looping_(false),
          quit_(false),
          eventHandling_(false),
          callingPendingFunctors_(false),
          iteration_(0),
          threadId_(std::this_thread::get_id()),
          poller_(new Poller(this)),
          timerQueue_(new TimerQueue(this)),
          wakeupFd_(createEventfd()),
          wakeupChannel_(new Channel(this, wakeupFd_)),
          currentActiveChannel_(nullptr) {
    LOG_DEBUG << "EventLoop created " << this << " in thread ";
    if (t_loopInThisThread) {
        LOG_FATAL << "Another EventLoop " << t_loopInThisThread
                  << " exists in this thread ";
    } else {
        t_loopInThisThread = this;
    }
//    wakeupChannel_->setReadCallback(
//            std::bind(&EventLoop::handleRead, this));

    wakeupChannel_->setReadCallback(
            [this](Timestamp)->void {handleRead();});
    // we are always reading the wakeupfd
    wakeupChannel_->enableReading();
}

EventLoop::~EventLoop() {
    LOG_DEBUG << "EventLoop " << this << " of thread "
              << " destructs in thread ";
    wakeupChannel_->disableAll();
    wakeupChannel_->remove();
    ::close(wakeupFd_);
    t_loopInThisThread = nullptr;
}

void EventLoop::loop() {
    assert(!looping_);
    assertInLoopThread();
    looping_ = true;
    quit_ = false;  // FIXME: what if someone calls quit() before loop() ?
    LOG_TRACE << "EventLoop " << this << " start looping";

    while (!quit_) {
        activeChannels_.clear();
        pollReturnTime_ = poller_->poll(kPollTimeMs, &activeChannels_);
        ++iteration_;
        if (Logger::logLevel() <= Logger::TRACE) {
            printActiveChannels();
        }
        // TODO sort channel by priority
        eventHandling_ = true;
        for (Channel *channel : activeChannels_) {
            currentActiveChannel_ = channel;
            currentActiveChannel_->handleEvent(pollReturnTime_);
        }
        currentActiveChannel_ = nullptr;
        eventHandling_ = false;
        doPendingFunctors();
    }

    LOG_TRACE << "EventLoop " << this << " stop looping";
    looping_ = false;
}

void EventLoop::quit() {
    quit_ = true;
    // There is a chance that loop() just executes while(!quit_) and exits,
    // then EventLoop destructs, then we are accessing an invalid object.
    // Can be fixed using mutex_ in both places.
    if (!isInLoopThread()) {
        wakeup();
    }
}

void EventLoop::runInLoop(Func cb) {
    if (isInLoopThread()) {
        cb();
    } else {
        queueInLoop(std::move(cb));
    }
}

void EventLoop::queueInLoop(Func cb) {
    {
        std::lock_guard<std::mutex> lockGuard(mutex_);
        pendingFunctors_.push_back(std::move(cb));
    }

    if (!isInLoopThread() || callingPendingFunctors_) {
        wakeup();
    }
}

size_t EventLoop::queueSize() {
    return pendingFunctors_.size();
}

TimerId EventLoop::runAt(Timestamp time, TimerCallback cb) {
    return timerQueue_->addTimer(std::move(cb), time, 0.0);
}

TimerId EventLoop::runAfter(double delay, TimerCallback cb) {
    Timestamp time(addTime(Timestamp::now(), delay));
    return runAt(time, std::move(cb));
}

TimerId EventLoop::runEvery(double interval, TimerCallback cb) {
    Timestamp time(addTime(Timestamp::now(), interval));
    return timerQueue_->addTimer(std::move(cb), time, interval);
}

void EventLoop::cancelTimer(TimerId timerId) {
    timerQueue_->cancel(timerId);
}

void EventLoop::updateChannel(Channel *channel) {
    assert(channel->ownerLoop() == this);
    assertInLoopThread();
    poller_->updateChannel(channel);
}

void EventLoop::removeChannel(Channel *channel) {
    assert(channel->ownerLoop() == this);
    assertInLoopThread();
    if (eventHandling_) {
        assert(currentActiveChannel_ == channel ||
               std::find(activeChannels_.begin(), activeChannels_.end(), channel) == activeChannels_.end());
    }
    poller_->removeChannel(channel);
}

bool EventLoop::hasChannel(Channel *channel) {
    assert(channel->ownerLoop() == this);
    assertInLoopThread();
    return poller_->hasChannel(channel);
}

void EventLoop::abortNotInLoopThread() {
    LOG_FATAL << "EventLoop::abortNotInLoopThread - EventLoop " << this
              << " was created in threadId_ = "
              << ", current thread id = ";
}

void EventLoop::wakeup() const {
    uint64_t one = 1;
    ssize_t n = muduo::net::sockets::write(wakeupFd_, &one, sizeof one);
    if (n != sizeof one) {
        LOG_ERROR << "EventLoop::wakeup() writes " << n << " bytes instead of 8";
    }
}

void EventLoop::handleRead() const {
    uint64_t one = 1;
    ssize_t n = muduo::net::sockets::read(wakeupFd_, &one, sizeof one);
    if (n != sizeof one) {
        LOG_ERROR << "EventLoop::handleRead() reads " << n << " bytes instead of 8";
    }
}

void EventLoop::doPendingFunctors() {
    std::vector<Func> functors;
    callingPendingFunctors_ = true;

    {
        std::lock_guard<std::mutex> lockGuard(mutex_);
        functors.swap(pendingFunctors_);
    }

    for (const Func &functor : functors) {
        functor();
    }
    callingPendingFunctors_ = false;
}

void EventLoop::printActiveChannels() const {
    for (const Channel *channel : activeChannels_) {
        LOG_TRACE << "{" << channel->reventsToString() << "} ";
    }
}