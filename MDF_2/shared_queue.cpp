//
// Created by giaco on 30/06/2022.
//

#include <stdlib.h>
#include <vector>
#include <functional>
#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <utility>
#include <queue>
#include <condition_variable>

template<typename QTYPE> //Create my own shared queue

class sharedQueue {

private:
    std::deque <QTYPE> q;       //Queue
    std::mutex m;               //Mutex to protect the queue
    std::condition_variable c;  //Condition variable to notify queue usage

public:
    QTYPE get_element() {
        std::unique_lock <std::mutex> l(m);
        while (q.empty())
            c.wait(l);
        QTYPE task = q.front();
        q.pop_front();
        return task;
    }

    void add_element(QTYPE element) {
        std::unique_lock <std::mutex> l(m);
        q.push_back(element);
        c.notify_all();
    }
    void add_element_front(QTYPE element) {
        std::unique_lock <std::mutex> l(m);
        q.push_front(element);
        c.notify_all();
    }

    bool is_empty(){
        bool isempty= false;
        std::unique_lock <std::mutex> l(m);
        isempty=q.empty();
        c.notify_all();
        return isempty;
    }
    int size(){
        int isempty= 0;
        std::unique_lock <std::mutex> l(m);
        isempty=q.size();
        c.notify_all();
        return isempty;
    }


};


