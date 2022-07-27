//
// Created by 27673 on 2022/6/29.
//

#ifndef TINYWEB_ASYNCLOG_H
#define TINYWEB_ASYNCLOG_H

#include "../exhead.h"
#include <vector>
#include <memory>
#include <atomic>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>


namespace QE {
    class AsyncLog {
    private:
        typedef detail::LogLargeLBuffer Buffer;
        typedef std::vector<std::unique_ptr<Buffer>> BufferVector;
        typedef std::unique_ptr<Buffer> BufferPtr;
        const int BufferNum = 3;


    public:
        AsyncLog(const std::string &basename, const off_t rollSize, int flushInterval = 3);

        ~AsyncLog();

        void start();

        void stop();

        void append(const char* logline, int len);

    private:
        void threadFunc_();  //后端线程
        const int flushInterval_;
        std::atomic<bool> running_;
        const std::string basename_;
        const off_t rollSize_;
        //std::unique_ptr<std::thread> threadPtr_;
        std::thread thread_;

        std::mutex mutex_;    //用于保护交换缓冲区的操作
        std::condition_variable cond_;
        std::condition_variable aemptyBuffer_;
        BufferPtr currentBuffer_;
        BufferVector fullBuffers_;
        BufferVector emptyBuffers_;

        BufferPtr nextBuffer_;

    };
}


#endif //TINYWEB_ASYNCLOG_H
