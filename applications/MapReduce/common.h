//
// Created by admin on 27/08/2020.
//

#ifndef C___NETWORK_COMMON_H
#define C___NETWORK_COMMON_H

#include <string>
#include <cstring>

typedef std::pair<std::string,std::string> KeyValue;
typedef std::vector<KeyValue> KVBucket;
typedef std::function<KVBucket(std::string,std::string)> MapFunc;
typedef std::function<std::string(std::string,std::vector<std::string>)> ReduceFunc;



enum TaskType {
    mTask,
    rTask,
    eTask
};

struct Task {

    Task() = default;

    Task(TaskType tasktype,int taskindex,char* filename,int nReduce):
        taskType(tasktype),
        taskIndex(taskindex),
        nReduce(nReduce)
    {
        strcpy(fileName,filename);
    }

    Task(TaskType tasktype,int taskindex,int nReduce,int totalTask):
            taskType(tasktype),
            taskIndex(taskindex),
            nReduce(nReduce),
            totalTask(totalTask)
    {
    }

    Task(std::string s)
    {
        strcpy((char* )this,s.c_str());
    }

    TaskType taskType;
    int taskIndex{};
    char fileName[50]{};
    int reduceIndex{};
    int nReduce{};
    int totalTask{};

    std::string toString() {
        return std::string((char*) this,sizeof(Task));
    }
};

#endif //C___NETWORK_COMMON_H
