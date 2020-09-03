//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_EVENTLOOPTHREAD_H
#define C___NETWORK_EVENTLOOPTHREAD_H


#include <thread>

#include <CountDownLatch.h>

namespace ev
{

    class EventLoop;

    class EventLoopThread: noncopyable
    {
    public:
        EventLoopThread() = default;
        ~EventLoopThread();

        EventLoop* startLoop();

    private:
        void runInThread();

        bool started_ = false;
        EventLoop* loop_ = nullptr;
        std::thread thread_;
        CountDownLatch latch_{1};
    };

}

#endif //C___NETWORK_EVENTLOOPTHREAD_H
