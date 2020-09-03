#include <netlib/noncopyable.h>
#include <netlib/EventLoop.h>
#include <netlib/TcpClient.h>
#include <netlib/InetAddress.h>
#include <netlib/Buffer.h>
#include <netlib/Callbacks.h>
#include <netlib/TcpConnection.h>
#include <netlib/Logger.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "common.h"

using namespace ev;

class Worker: noncopyable
{
public:
    Worker(EventLoop* loop,MapFunc mapfunc, ReduceFunc reduceFunc,int port):
        eventLoop_(loop),
        mapFunc_(mapfunc),
        reduceFunc_(reduceFunc),
        local_(port),
        client_(loop,local_),
        hasher_()
    {

    }

private:
    void onMessage(const TcpConnectionPtr& conn, Buffer& buffer)
    {
        ::Task t(buffer.retrieveAllAsString());
        if (t.taskType == mTask) {
            doMapTask(t);
        } else if (t.taskType == rTask) {
            doReduceTask(t);
        } else {
            doExit();
        }
    }
    void onConnection(const TcpConnectionPtr& conn) // not thread safe
    {
        INFO("connection %s is [%s]",
             conn->name().c_str(),
             conn->connected() ? "up" : "down");
    }

    std::string getContent(std::string fileName)
    {
        std::ifstream inFile;
        inFile.open(fileName); //open the input file

        std::stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        return strStream.str(); //str holds the content of the file
    }

    void doMapTask(const ::Task& t) {
        std::string content = getContent(t.fileName);
        auto KeyVals = mapFunc_(t.fileName,content);
        std::vector<KVBucket > kvBuckets(t.nReduce);
        for(KeyValue kv:KeyVals) {
            int bucket = hasher_(kv.first)%t.nReduce;
            kvBuckets[bucket].push_back(kv);
        }
        char fileName[20];
        for(int i=0;i<t.nReduce;i++) {
            // the important part
            sprintf(fileName,"mr-%d-%d",t.taskIndex,i);
            std::ofstream outFile(fileName);
            for (const auto &e : kvBuckets[i]) outFile << e.first <<' '<<e.second << "\n";
        }
    }

    void doReduceTask(const ::Task& t) {
        KVBucket intermediate;
        std::ifstream inFile;
        char fileName[20];
        for(int i=0;i<t.totalTask;i++) {
            sprintf(fileName,"mr-%d-%d",i,t.reduceIndex);
            inFile.open(fileName);
            KeyValue kv;
            while(inFile>>kv.first>>kv.second) {
                intermediate.push_back(kv);
            }
            inFile.close();
        }
        std::sort(intermediate.begin(),intermediate.end());
        std::vector<std::string> values;
        for(int i=0;i<intermediate.size();) {
            int j = i+1;
            values.push_back(intermediate[i].second);
            for(;j<intermediate.size() && intermediate[j].first == intermediate[i].first;j++)
                values.push_back(intermediate[j].second);
            auto output = reduceFunc_(intermediate[i].first,values);
            sprintf(fileName,"%s %s\n",intermediate[i].first.c_str(),output.c_str());
            i=j;

        }
        //TODO: send complete info
    }

    void doExit()
    {
        eventLoop_->quit();
    }



    MapFunc mapFunc_;
    ReduceFunc reduceFunc_;
    EventLoop* eventLoop_;
    TcpClient client_;
    InetAddress local_;
    std::hash<std::string> hasher_;
};