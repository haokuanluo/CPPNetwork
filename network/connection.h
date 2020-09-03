//
// Created by admin on 05/07/2020.
//

#ifndef C___NETWORK_CONNECTION_H
#define C___NETWORK_CONNECTION_H

//
// Created by admin on 05/07/2020.
//

#include "connection.h"
#include <functional>
#include <sys/time.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <string.h>
#include <errno.h>
#include <mutex>
#include <vector>
#include <thread>

#define TRUE 1

class Connection {
public:

    Connection() = default;

    void StartListen(int port_number);


    ~Connection();

    void Send(char* message, int len, int socket);


private:
    int port_number_;
    char data_[100000];
    int len_=0;
    std::mutex mu_;
    std::vector<std::thread> thread_pool_;

};





#endif //C___NETWORK_CONNECTION_H
