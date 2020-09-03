
#include <unordered_set>

#include <netlib/Logger.h>
#include <netlib/EventLoop.h>
#include <netlib/TcpConnection.h>
#include <netlib/TcpClient.h>
#include <netlib/TcpServer.h>
#include <netlib/CountDownLatch.h>
#include "common.h"
#include <deque>

using namespace ev;

class Master: noncopyable
{
public:
    Master(EventLoop* loop, std::vector<std::string>&& files, int32_t nReduce,int32_t port)
            : loop_(loop),
              files_(files),
              nReduce_(nReduce),
              local_(port),
              server_(loop,local_),
              latch_(files.size())
    {
        server_.setConnectionCallback(std::bind(
                &Master::onConnection, this, _1));
        server_.setMessageCallback(std::bind(
                &Master::onMessage, this, _1, _2));
        server_.start();
    }

private:
    void onMessage(const TcpConnectionPtr& conn, Buffer& buffer)
    {
        ::Task t(buffer.retrieveAllAsString());
        onFinishTask(conn,t);
    }
    void onConnection(const TcpConnectionPtr& conn) // not thread safe
    {
        assignTask(conn);
    }

    void assignTask(const TcpConnectionPtr& conn)
    {
        if (conn->connected()) {
            if (queue_.empty()) {
                pendingWorkers_.emplace_back(conn);
            } else {
                conn->send(queue_.front().toString());
                if (queue_.front().taskType != eTask) {
                    queue_.pop_front();
                }
            }
        }
    }

    void onFinishTask(const TcpConnectionPtr& conn, const ::Task& task) { // not thread safe
        //TODO: check duplication, add fault tolerance
        latch_--;
        if (latch_ == 0) {
            if (task.taskType == mTask)
                assignReduceTask();
            else
                assignExitTask();
        }
        assignTask(conn);
    }

    void assignReduceTask()
    {
        for(int i=0;i<nReduce_;i++) {
            latch_++;
            queue_.emplace_back(rTask,i,nReduce_,totalTask_);
        }
        while(!pendingWorkers_.empty()) {
            if (queue_.empty()) {
                break;
            }
            pendingWorkers_.front()->send(queue_.front().toString());
            pendingWorkers_.pop_front();
            queue_.pop_front();
        }
    }

    void assignExitTask() {
        ::Task t;
        t.taskType = eTask;
        queue_.emplace_back(t);
    }

    EventLoop* loop_;
    std::vector<std::string> files_;
    int32_t nReduce_;
    TcpServerSingle server_;
    InetAddress local_;
    std::deque<::Task> queue_;
    std::deque<TcpConnectionPtr> pendingWorkers_;
    int latch_;
    int totalTask_;

};
