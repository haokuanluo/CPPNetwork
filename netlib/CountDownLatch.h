//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_COUNTDOWNLATCH_H
#define C___NETWORK_COUNTDOWNLATCH_H

#include <mutex>
#include <condition_variable>

#include <netlib/noncopyable.h>

namespace ev
{

    class CountDownLatch: noncopyable
    {
    public:
        explicit
        CountDownLatch(int count)
                : count_(count)
        {}

        void count()
        {
            std::lock_guard<std::mutex> guard(mutex_);
            count_--;
            if (count_ <= 0)
                cond_.notify_all();
        }

        int getCount()
        {
            std::lock_guard<std::mutex> guard(mutex_);
            return count_;
        }

        void add()
        {
            std::lock_guard<std::mutex> guard(mutex_);
            count_++;
        }

        void wait()
        {
            std::unique_lock<std::mutex> lock(mutex_);
            while (count_ > 0)
                cond_.wait(lock);
        }

    private:
        int count_;
        std::mutex mutex_;
        std::condition_variable cond_;
    };

}

#endif //C___NETWORK_COUNTDOWNLATCH_H
