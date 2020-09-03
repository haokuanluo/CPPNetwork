//
// Created by admin on 22/08/2020.
//

#include "EventLoop.h"

#include <cassert>
#include <sys/types.h> // pid_t
#include <unistd.h>	// syscall()
#include <signal.h>
#include <numeric>

#include "Logger.h"
#include "Channel.h"

using namespace ev;

namespace
{

    __thread EventLoop* t_Eventloop = nullptr;

    pid_t gettid()
    {
        uint64_t tid;
        pthread_threadid_np(NULL, &tid);
        return static_cast<pid_t>(tid);
    }

    class IgnoreSigPipe
    {
    public:
        IgnoreSigPipe()
        {
            ::signal(SIGPIPE, SIG_IGN);
        }
    };

    IgnoreSigPipe ignore;

}

EventLoop::EventLoop()
        : tid_(gettid()),
          quit_(false),
          doingPendingTasks_(false),
          poller_(this),
          timerQueue_(this,poller_.kqfd())
{
    assert(t_Eventloop == nullptr);
    t_Eventloop = this;
}

EventLoop::~EventLoop()
{
    assert(t_Eventloop == this);
    t_Eventloop = nullptr;
}

void EventLoop::loop()
{
    assertInLoopThread();
    TRACE("EventLoop %p polling", this);
    quit_ = false;
    while (!quit_) {
        activeChannels_.clear();
        poller_.poll(activeChannels_);
        for (auto channel: activeChannels_)
            channel->handleEvents();
        doPendingTasks();
    }
    TRACE("EventLoop %p quit", this);
}

void EventLoop::quit()
{
    assert(!quit_);
    quit_ = true;
    if (!isInLoopThread())
        wakeup();
}

void EventLoop::runInLoop(const Task& task)
{
    if (isInLoopThread())
        task();
    else
        queueInLoop(task);
}

void EventLoop::runInLoop(Task&& task)
{
    if (isInLoopThread())
        task();
    else
        queueInLoop(std::move(task));
}

void EventLoop::queueInLoop(const Task& task)
{
    {
        std::lock_guard<std::mutex> guard(mutex_);
        pendingTasks_.push_back(task);
    }
    // if we are not in loop thread, just wake up loop thread to handle new task
    // if we are in loop thread && doing pending task, wake up too.
    // note that the following code has race condition:
    //     if (doingPendingTasks_ || isInLoopThread())
    if (!isInLoopThread() || doingPendingTasks_)
        wakeup();
}

void EventLoop::queueInLoop(Task&& task)
{
    {
        std::lock_guard<std::mutex> guard(mutex_);
        pendingTasks_.push_back(std::move(task));
    }
    if (!isInLoopThread() || doingPendingTasks_)
        wakeup();
}

Timer* EventLoop::runAt(Timestamp when, TimerCallback callback)
{
    return timerQueue_.addTimer(std::move(callback), when, Millisecond::zero());
}

Timer* EventLoop::runAfter(Nanosecond interval, TimerCallback callback)
{
    return runAt(clock::now() + interval, std::move(callback));
}

Timer* EventLoop::runEvery(Nanosecond interval, TimerCallback callback)
{
    return timerQueue_.addTimer(std::move(callback),
                                clock::now() + interval,
                                interval);
}

void EventLoop::cancelTimer(Timer* timer)
{
    timerQueue_.cancelTimer(timer);
}


void EventLoop::wakeup()
{
    poller_.wakeUp();
}


void EventLoop::updateChannel(Channel* channel)
{
    assertInLoopThread();
    poller_.updateChannel(channel);
}

void EventLoop::removeChannel(Channel* channel)
{
    assertInLoopThread();
    channel->disableAll();
}

void EventLoop::assertInLoopThread()
{
    assert(isInLoopThread());
}

void EventLoop::assertNotInLoopThread()
{
    assert(!isInLoopThread());
}

bool EventLoop::isInLoopThread()
{
    // tid_ is constant, don't worry about thread safety
    return tid_ == gettid();
}

void EventLoop::doPendingTasks()
{
    assertInLoopThread();
    std::vector<Task> tasks;
    {
        // shorten the critical area by a single swap
        std::lock_guard<std::mutex> guard(mutex_);
        tasks.swap(pendingTasks_);
    }
    doingPendingTasks_ = true;
    for (Task& task: tasks)
        task();
    doingPendingTasks_ = false;
}