//
// Created by admin on 22/08/2020.
//

#include <cassert>

#include <EventLoop.h>
#include <Channel.h>

using namespace ev;

Channel::Channel(EventLoop* loop, int fd)
        : polling(false),
          loop_(loop),
          fd_(fd),
          tied_(false),
          events_(0),
          revents_(0),
          handlingEvents_(false)
{}

Channel::~Channel()
{ assert(!handlingEvents_); }

void Channel::handleEvents()
{
    loop_->assertInLoopThread();
    // channel is always a member of another object
    // e.g. Timer, Acceptor, TcpConnection
    // TcpConnection is managed by std::shared_ptr,
    // and may be destructed when handling events,
    // so we use weak_ptr->shared_ptr to
    // extend it's life-time.
    if (tied_) {
        auto guard = tie_.lock();
        if (guard != nullptr)
            handleEventsWithGuard();
    }
    else handleEventsWithGuard();
}

void Channel::handleEventsWithGuard()
{
    handlingEvents_ = true;
    if ( flags_ & EV_EOF) {
        if (closeCallback_) closeCallback_();
    }
    if (revents_ == EVFILT_READ || revents_ == EVFILT_TIMER) {
        if (readCallback_) readCallback_();
    }
    if (revents_ == EVFILT_WRITE) {
        if (writeCallback_) writeCallback_();
    }
    handlingEvents_ = false;
}

void Channel::tie(const std::shared_ptr<void>& obj)
{
    tie_ = obj;
    tied_ = true;
}

void Channel::update()
{
    loop_->updateChannel(this);
}

void Channel::remove()
{
    assert(polling);
    loop_->removeChannel(this);
}

