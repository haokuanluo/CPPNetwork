//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_EPOLLER_H
#define C___NETWORK_EPOLLER_H
#include <vector>

#include <netlib/noncopyable.h>

namespace ev
{
    class EventLoop;
    class Channel;

    class EPoller: noncopyable
    {
    public:
        typedef std::vector<Channel*> ChannelList;

        explicit
        EPoller(EventLoop* loop);
        ~EPoller();

        void poll(ChannelList& activeChannels);
        void updateChannel(Channel* channel);
        void wakeUp();
        int kqfd() const {return epollfd_;}

    private:
        EventLoop* loop_;
        std::vector<struct kevent> events_;
        int epollfd_;
        const int wakeupFd_;
        struct kevent wakeupEvent_;
    };

}
void kevent_add(int kqfd, struct kevent *kev,
                uintptr_t ident,
                short     filter,
                u_short   flags,
                u_int     fflags,
                intptr_t  data,
                void      *udata);

#endif //C___NETWORK_EPOLLER_H
