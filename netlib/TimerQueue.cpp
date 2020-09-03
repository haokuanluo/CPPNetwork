//
// Created by frank on 17-11-17.
//
#include <strings.h>
#include <unistd.h>
#include <ratio> // std::nano::den

#include <Logger.h>
#include <EventLoop.h>
#include <TimerQueue.h>

using namespace ev;

namespace
{

    int timerfdCreate()
    {
        return 1;
    }

    void timerfdRead(int fd)
    {
        return;
    }

    int durationFromNow(Timestamp when)
    {
        Nanosecond ns = when - clock::now();
        return ns.count()/1000000ll;
    }
}

void TimerQueue::timerfdSet(int fd, Timestamp when)
{
    int timeMs = durationFromNow(when);
    struct kevent ev[1];
    kevent_add(kqfd_,&ev[0],timerfd_,EVFILT_TIMER, EV_ADD | EV_ONESHOT, 0, timeMs,&timerChannel_);
}

TimerQueue::TimerQueue(EventLoop *loop,int kqfd)
        : loop_(loop),
          timerfd_(timerfdCreate()),
          timerChannel_(loop, timerfd_),
          kqfd_(kqfd)
{
    loop_->assertInLoopThread();
    timerChannel_.setReadCallback([this](){handleRead();});
    //timerChannel_.enableRead();
}

TimerQueue::~TimerQueue()
{
    for (auto& p: timers_)
        delete p.second;
    ::close(timerfd_);
}


Timer* TimerQueue::addTimer(TimerCallback cb, Timestamp when, Nanosecond interval)
{
    Timer* timer = new Timer(std::move(cb), when, interval);
    loop_->runInLoop([=](){
        auto ret = timers_.insert({when, timer});
        assert(ret.second);

        if (timers_.begin() == ret.first)
            timerfdSet(timerfd_, when);
    });
    return timer;
}

void TimerQueue::cancelTimer(Timer* timer)
{
    assert(timer != NULL);
    loop_->runInLoop([timer, this](){
        timer->cancel();
        timers_.erase({timer->when(), timer});
        delete timer;
    });
}

void TimerQueue::handleRead()
{
    loop_->assertInLoopThread();
    timerfdRead(timerfd_);

    Timestamp now(clock::now());
    for (auto& e: getExpired(now)) {
        Timer* timer = e.second;
        assert(timer->expired(now));

        if (!timer->canceled())
            timer->run();
        if (!timer->canceled() && timer->repeat()) {
            timer->restart();
            e.first = timer->when();
            timers_.insert(e);
        }
        else delete timer;
    }

    if (!timers_.empty())
        timerfdSet(timerfd_, timers_.begin()->first);
}

std::vector<TimerQueue::Entry> TimerQueue::getExpired(Timestamp now)
{
    Entry en(now + 1ns, nullptr);
    std::vector<Entry> entries;

    auto end = timers_.lower_bound(en);
    entries.assign(timers_.begin(), end);
    timers_.erase(timers_.begin(), end);

    return entries;
}

