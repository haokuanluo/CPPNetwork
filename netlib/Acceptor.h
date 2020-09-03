#ifndef C___NETWORK_ACCEPTOR_H
#define C___NETWORK_ACCEPTOR_H


#include <memory>

#include <netlib/noncopyable.h>
#include <netlib/InetAddress.h>
#include <netlib/Channel.h>

namespace ev
{

    class EventLoop;

    class Acceptor:noncopyable
    {
    public:
        Acceptor(EventLoop* loop, const InetAddress& local);
        ~Acceptor();

        bool listening() const
        { return listening_; }

        void listen();

        void setNewConnectionCallback(const NewConnectionCallback& cb)
        { newConnectionCallback_ = cb; }

    private:
        void handleRead();

        bool listening_;
        EventLoop* loop_;
        const int acceptFd_;
        Channel acceptChannel_;
        InetAddress local_;
        NewConnectionCallback newConnectionCallback_;
    };

}

#endif //C___NETWORK_ACCEPTOR_H
