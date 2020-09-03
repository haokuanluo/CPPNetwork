//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_CHANNEL_H
#define C___NETWORK_CHANNEL_H

#include <functional>
#include <memory>
#include <sys/event.h>
#include <netlib/epollconst.h>

#include <netlib/noncopyable.h>

namespace ev
{

    class EventLoop;

    class Channel: noncopyable
    {
    public:
        typedef std::function<void()> ReadCallback;
        typedef std::function<void()> WriteCallback;
        typedef std::function<void()> CloseCallback;
        typedef std::function<void()> ErrorCallback;

        Channel(EventLoop* loop, int fd);
        ~Channel();

        void setReadCallback(const ReadCallback& cb)
        { readCallback_ = cb; }
        void setWriteCallback(const WriteCallback& cb)
        { writeCallback_ = cb; }
        void setCloseCallback(const CloseCallback& cb)
        { closeCallback_ = cb; }
        void setErrorCallback(const ErrorCallback& cb)
        { errorCallback_ = cb; }

        void handleEvents();

        bool polling;
        int fd() const
        { return fd_; }
        bool isNoneEvents() const
        { return events_ == 0; }
        unsigned events() const
        { return events_; }
        unsigned readWrite() const
        { return readWrite_; }
        unsigned action () const
        { return action_; }
        void setRevents(unsigned flags,unsigned revents)
        { revents_ = revents; flags_ = flags; }

        void tie(const std::shared_ptr<void>& obj);

        void enableRead()
        {
            events_ |= (EPOLLIN | EPOLLPRI);
            readWrite_ = EVFILT_READ; action_ = EV_ADD|EV_ENABLE;
            update();
        }
        void enableWrite()
        { events_ |= EPOLLOUT; readWrite_ = EVFILT_WRITE; action_ = EV_ADD|EV_ENABLE; update();}
        void disableRead()
        { events_ &= ~EPOLLIN; readWrite_ = EVFILT_READ; action_ = EV_DELETE; update();}
        void disableWrite()
        { events_ &= ~EPOLLOUT; readWrite_ = EVFILT_WRITE; action_ = EV_DELETE; update();}
        void disableAll()
        {
            events_ = 0; readWrite_ = EVFILT_WRITE; action_ = EV_DELETE; update();
            readWrite_ = EVFILT_READ; action_ = EV_DELETE; update();
        }

        bool isReading() const { return events_ & EPOLLIN; }
        bool isWriting() const { return events_ & EPOLLOUT; }

    private:
        void update();
        void remove();

        void handleEventsWithGuard();

        EventLoop* loop_;
        int fd_;

        std::weak_ptr<void> tie_;
        bool tied_;

        unsigned events_;
        unsigned readWrite_;
        unsigned revents_;
        unsigned action_;
        unsigned flags_;

        bool handlingEvents_;

        ReadCallback readCallback_;
        WriteCallback writeCallback_;
        CloseCallback closeCallback_;
        ErrorCallback errorCallback_;
    };


}
#endif //C___NETWORK_CHANNEL_H
