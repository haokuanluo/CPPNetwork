//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_TIMERQUEUE_H
#define C___NETWORK_TIMERQUEUE_H

#include <memory>
#include <set>

#include <netlib/Timer.h>
#include <netlib/Channel.h>
#include <netlib/Callbacks.h>
#include <netlib/Timestamp.h>

namespace ev
{

    class TimerQueue: noncopyable
    {
    public:
        explicit
        TimerQueue(EventLoop* loop,int kqfd);
        ~TimerQueue();

        Timer* addTimer(TimerCallback cb, Timestamp when, Nanosecond interval);
        void cancelTimer(Timer* timer);

    private:
        typedef std::pair<Timestamp, Timer*> Entry;
        typedef std::set<Entry> TimerList;
        void timerfdSet(int fd, Timestamp when);
        void handleRead();
        std::vector<Entry> getExpired(Timestamp now);

    private:
        EventLoop* loop_;
        const int timerfd_;
        Channel timerChannel_;
        TimerList timers_;
        int kqfd_;
    };

}
#endif //C___NETWORK_TIMERQUEUE_H
