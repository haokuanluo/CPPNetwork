//
// Created by admin on 22/08/2020.
//

#ifndef C___NETWORK_NONCOPYABLE_H
#define C___NETWORK_NONCOPYABLE_H


namespace ev
{

    class noncopyable
    {
    public:
        noncopyable(const noncopyable&) = delete;
        void operator=(const noncopyable&) = delete;

    protected:
        noncopyable() = default;
        ~noncopyable() = default;
    };

}


#endif //C___NETWORK_NONCOPYABLE_H
