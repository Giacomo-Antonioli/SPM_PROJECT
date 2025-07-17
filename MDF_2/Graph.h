//
// Created by giaco on 18/05/2022.
//
#include "Node.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "MDFG.h"


#ifndef SPM_GRAPH_H
#define SPM_GRAPH_H

template<class T>
class Graph {

private:


public:
    std::vector<Node<T> *> list_of_nodes;



    void addNode(Node<T> *inputNode);

    void compile();

    void compute();


    void addPointer();
};


#endif //SPM_GRAPH_H
