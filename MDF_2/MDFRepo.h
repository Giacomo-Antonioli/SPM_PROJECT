//
// Created by giaco on 06/07/2022.
//

#ifndef SPM_MDFREPO_H
#define SPM_MDFREPO_H
#include "MDFI.h"
#include <vector>
#include "Node.h"
#include "Graph.h"
#include <map>
#include "ThreadPool.hpp"
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
template<class T>
class MDFRepo {

public:


 std::map<unsigned long int,MDFI<T>> waiting;
 std::shared_mutex mutex;
 std::condition_variable_any cv;

 sharedQueue<MDFI<T>> firable;
 bool streamEnded=false;
 sharedQueue<unsigned long int> promotable;
//std::vector<MDFI> firable;
thread emitterhtread;
bool emitter_async=false;
void insertInWaiting(MDFI<T> toBeInserted);
void promoteToFirable(MDFI<T> toBeInserted);
void execute(MDFI<T> toCompute);
long unsigned int global_id=0;
//Graph *graph;
    std::vector<Graph<T>*> list_of_graphs;
    sharedQueue<std::pair< long unsigned int,T>> resultList;
    Thread_pool<std::function<void()>> pool;
    void startPool(int nw);
    void killPool();

    void addGraph(Graph<T> *tobeAdded);

    void startEmitter(int numberOfTasks,bool ThreadedEmitter);

    void startFlow(int nw);

    void startEmitterThreaded(int numberOfTasks);
};


#endif //SPM_MDFREPO_H
