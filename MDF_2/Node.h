//
// Created by giaco on 18/05/2022.
//
#include <stdlib.h>
#include <vector>
#include <functional>
#include <map>
#include <shared_mutex>

#ifndef SPM_NODE_H
#define SPM_NODE_H

#include "MDFI.h"

template<class T>
class Node {
private:

public:

    int id=0;
    int inputAriety;
    int outputAriety;
    Node<T>(int id,int inputAriety,int outputAriety);
    std::vector<Node*> dependencies;
    std::function<std::vector<T>(std::vector<T>)> toCompute;
    MDFI<T> TemplateMDFI;
    std::vector<int> depChannels;
    int fatherTouchedMe=0;
    void AddDependency(Node* dependentNode);
    void addFunction(std::function<std::vector<T>(std::vector<T>)> functiontobeadded);
    void compile();




    void addDep(Node *nodeDep);

    MDFI<T> generateMDFI(unsigned long id, std::map<unsigned long, MDFI<T>> *pMap, std::shared_mutex *pMutex,
                         sharedQueue<unsigned long> *pQueue);
};


#endif //SPM_NODE_H
