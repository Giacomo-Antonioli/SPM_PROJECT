//
// Created by giaco on 18/05/2022.
//

#include "Graph.h"
#include "utimer.cpp"
#include <thread>
#include <utility>
#include <future>
#include <vector>
template<class T>
void Graph<T>::addNode(Node<T> *inputNode) {
    this->list_of_nodes.push_back(inputNode);
}
template<class T>
void Graph<T>::compute(){
    //this->list_of_nodes[0]->TemplateMDFI.executable_function();
}
template<class T>
void Graph<T>::compile(){
    //std::cout<<"compiled"<<std::endl;
    for (int i = 0; i < this->list_of_nodes.size()-1; ++i) {
        this->list_of_nodes[i]->compile();

    }
    this->list_of_nodes[this->list_of_nodes.size()-1]->TemplateMDFI.input_array.resize(this->list_of_nodes[this->list_of_nodes.size()-1]->inputAriety);
    this->list_of_nodes[this->list_of_nodes.size()-1]->TemplateMDFI.output_array.resize(this->list_of_nodes[this->list_of_nodes.size()-1]->outputAriety);
    this->list_of_nodes[this->list_of_nodes.size()-1]->TemplateMDFI.destinationList.resize(this->list_of_nodes[this->list_of_nodes.size()-1]->outputAriety);
    this->list_of_nodes[this->list_of_nodes.size()-1]->TemplateMDFI.inputList.resize(this->list_of_nodes[this->list_of_nodes.size()-1]->inputAriety);
    this->list_of_nodes[this->list_of_nodes.size()-1]->TemplateMDFI.isLast=true;

}
template class Graph<float>;
template class Graph<int>;