//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_EVENTLOOP_H
#define C___NETWORK_EVENTLOOP_H

#include <atomic>
#include <mutex>
#include <vector>
#include <sys/types.h>

#include <netlib/Timer.h>
#include <netlib/EPoller.h>
#include <netlib/TimerQueue.h>
namespace ev
{

    class EventLoop: noncopyable
    {
    public:

        EventLoop();
        ~EventLoop();

        void loop();
        void quit(); // thread safe

        void runInLoop(const Task& task);
        void runInLoop(Task&& task);
        void queueInLoop(const Task& task);
        void queueInLoop(Task&& task);

        Timer* runAt(Timestamp when, TimerCallback callback);
        Timer* runAfter(Nanosecond interval, TimerCallback callback);
        Timer* runEvery(Nanosecond interval, TimerCallback callback);
        void cancelTimer(Timer* timer);

        void wakeup();

        void updateChannel(Channel* channel);
        void removeChannel(Channel* channel);

        void assertInLoopThread();
        void assertNotInLoopThread();
        bool isInLoopThread();

    private:
        void doPendingTasks();
        const pid_t tid_;
        std::atomic_bool quit_;
        bool doingPendingTasks_;
        EPoller poller_;
        EPoller::ChannelList activeChannels_;
        std::mutex mutex_;
        std::vector<Task> pendingTasks_; // guarded by mutex_
        TimerQueue timerQueue_;
    };

}

#endif //C___NETWORK_EVENTLOOP_H
