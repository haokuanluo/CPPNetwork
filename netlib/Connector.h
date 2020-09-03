//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_CONNECTOR_H
#define C___NETWORK_CONNECTOR_H


#include <functional>

#include <netlib/InetAddress.h>
#include <netlib/Channel.h>
#include <netlib/noncopyable.h>

namespace ev
{

    class EventLoop;
    class InetAddress;

    class Connector: noncopyable
    {
    public:
        Connector(EventLoop* loop, const InetAddress& peer);
        ~Connector();

        void start();

        void setNewConnectionCallback(const NewConnectionCallback& cb)
        { newConnectionCallback_ = cb; }

        void setErrorCallback(const ErrorCallback& cb)
        { errorCallback_ = cb; }

    private:
        void handleWrite();

        EventLoop* loop_;
        const InetAddress peer_;
        const int sockfd_;
        bool connected_;
        bool started_;
        Channel channel_;
        NewConnectionCallback newConnectionCallback_;
        ErrorCallback errorCallback_;
    };

}

#endif //C___NETWORK_CONNECTOR_H
