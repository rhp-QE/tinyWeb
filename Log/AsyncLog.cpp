//
// Created by 27673 on 2022/6/29.
//

#include "AsyncLog.h"
#include <assert.h>
#include <iostream>

namespace QE {

AsyncLog::AsyncLog(const std::string& basename, const off_t rollSize, int flushInterval)
    : basename_(basename)
    , rollSize_(rollSize)
    , flushInterval_(flushInterval)
{
    //提前准备好 BuferNum 块缓冲区
    currentBuffer_ = std::make_unique<Buffer>();
    currentBuffer_->bzero();
    for (int i = 0; i < BufferNum; ++i) {
        emptyBuffers_.push_back(std::make_unique<Buffer>());
        emptyBuffers_.back()->bzero();
    }
}

AsyncLog::~AsyncLog()
{
    if (running_) {
        stop();
    }
}

void AsyncLog::start()
{
    running_ = true;
    thread_ = std::thread(&AsyncLog::threadFunc_, this);
}

void AsyncLog::stop()
{
    running_ = false;
    thread_.join();
}

void AsyncLog::append(const char* logline, int len)
{
    std::unique_lock<std::mutex> uniqueLock(mutex_);
    if (currentBuffer_->avail() > len) {
        currentBuffer_->append(logline, len);
    } else {
        fullBuffers_.push_back(std::move(currentBuffer_));
        while (emptyBuffers_.empty()) {
            // std::cout << "no" << std::endl;
            aemptyBuffer_.wait(uniqueLock);
        }
        currentBuffer_ = std::move(emptyBuffers_.back());
        emptyBuffers_.pop_back();
        cond_.notify_one();
    }
}

void AsyncLog::threadFunc_()
{
    assert(running_ == true);
    LogFile output(basename_, rollSize_, false);
    BufferVector buffersToWrite;
    BufferVector buffersToSave;

    //保留 后端线程已近刷新到缓冲区的 buffer
    //在获得锁后再传给 前端的 空 buffer 集合

    buffersToSave.push_back(std::make_unique<Buffer>());
    buffersToSave.back()->bzero();

    while (running_) {
        assert(buffersToWrite.empty());
        {
            std::unique_lock<std::mutex> uniqueLock(mutex_);
            while (buffersToSave.size() > 1) {
                emptyBuffers_.push_back(std::move(buffersToSave.back()));
                buffersToSave.pop_back();
                aemptyBuffer_.notify_one();
            }
            if (fullBuffers_.empty()) {
                cond_.wait_for(uniqueLock, std::chrono::duration<int>(flushInterval_));
            }
            if (currentBuffer_.get())
                fullBuffers_.push_back(std::move(currentBuffer_));
            buffersToWrite.swap(fullBuffers_);
            currentBuffer_ = std::move(buffersToSave.back());
            buffersToSave.pop_back();
        }

        assert(!buffersToWrite.empty());

        for (const auto& buffer : buffersToWrite) {
            output.append(buffer->data(), buffer->length());
        }

        while (!buffersToWrite.empty()) {
            buffersToWrite.back()->reset();
            buffersToSave.push_back(std::move(buffersToWrite.back()));
            buffersToWrite.pop_back();
        }
        output.flush();
    }
    output.flush();
}

}