//
// Created by admin on 22/08/2020.
//


#include <unistd.h>
#include <sys/event.h>
#include <cassert>
#include <EPoller.h>
#include <Logger.h>
#include <EventLoop.h>

using namespace ev;

EPoller::EPoller(EventLoop* loop)
        :loop_(loop),
         events_(128),
         epollfd_(::kqueue()),
         wakeupFd_(1)
{
    kevent_add(epollfd_,&wakeupEvent_,wakeupFd_,EVFILT_USER, EV_ADD, 0, 0, NULL);
    if (epollfd_ == -1)
        SYSFATAL("EPoller::epoll_create1()");
}

EPoller::~EPoller()
{
    ::close(epollfd_);
}

void EPoller::wakeUp()
{
    kevent_add(epollfd_, &wakeupEvent_, wakeupFd_, EVFILT_USER, 0, NOTE_TRIGGER, 0, NULL);
}
void EPoller::poll(ChannelList& activeChannels)
{
    loop_->assertInLoopThread();
    int maxEvents = static_cast<int>(events_.size());
    struct timespec timeout;
    timeout.tv_sec = 0;
    timeout.tv_nsec = 0;
    int nEvents = kevent(epollfd_, NULL, 0, events_.data(), maxEvents, &timeout);
    if (nEvents == -1) {
        if (errno != EINTR)
            SYSERR("EPoller::epoll_wait()");
    }
    else if (nEvents > 0) {
        for (int i = 0; i < nEvents; ++i) {
            if (events_[i].udata == NULL) continue; // wakeup trigger
            auto channel = static_cast<Channel*>(events_[i].udata);
            channel->setRevents(events_[i].flags,events_[i].filter);
            activeChannels.push_back(channel);
        }
        if (nEvents == maxEvents)
            events_.resize(2 * events_.size());
    }
}

void EPoller::updateChannel(Channel* channel)
{
    loop_->assertInLoopThread();
    struct kevent ev[1];
    kevent_add(epollfd_,&ev[0], channel->fd(), channel->readWrite(),
            channel->action(), 0, 0, (void*)channel);
}

void kevent_add(int kqfd, struct kevent *kev,
           uintptr_t ident,
           short     filter,
           u_short   flags,
           u_int     fflags,
           intptr_t  data,
           void      *udata)
{
    EV_SET(kev, ident, filter, flags, fflags, data, udata);
    kevent(kqfd, kev, 1, NULL, 0, NULL);
}

