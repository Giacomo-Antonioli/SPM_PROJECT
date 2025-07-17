//
// Created by giaco on 18/05/2022.
//

#include "Node.h"

template<class T>
Node<T>::Node(int id, int inputAriety, int outputAriety) {
    this->id = id;
    this->inputAriety = inputAriety;
    this->outputAriety = outputAriety;
}

template<class T>
void Node<T>::addFunction(std::function<std::vector<T>(std::vector<T>)> functiontobeadded) {

    this->toCompute = functiontobeadded;
    this->TemplateMDFI.executable_function = functiontobeadded;
}

template<class T>
void Node<T>::compile() {

    this->TemplateMDFI.input_array.resize(this->inputAriety);
    this->TemplateMDFI.output_array.resize(this->outputAriety);
    this->TemplateMDFI.destinationList.resize(this->outputAriety);
    this->TemplateMDFI.inputList.resize(this->inputAriety);
    for (int i = 0; i < this->outputAriety; ++i) {
        this->TemplateMDFI.destinationList[i].index_of_current_output = i;
        this->TemplateMDFI.destinationList[i].position_in_destination_token_list = this->dependencies[i]->fatherTouchedMe;
        this->dependencies[i]->fatherTouchedMe++;
    }


}




template<class T>
void Node<T>::addDep(Node *nodeDep) {
    this->dependencies.push_back(nodeDep);
    this->depChannels.push_back(nodeDep->id);
}

template<class T>
MDFI<T> Node<T>::generateMDFI(unsigned long id, std::map<unsigned long, MDFI<T>> *pMap, std::shared_mutex *pMutex,
                              sharedQueue<unsigned long> *pQueue) {
    MDFI<T> toBeReturned;
    //   this->TemplateMDFI.f1=toBeReturned.f1;
    toBeReturned = this->TemplateMDFI;
    toBeReturned.pMap = pMap;
    toBeReturned.mutexPointer = pMutex;
    toBeReturned.toPromote = pQueue;
    int current_id = this->id;
    // std::cout<<"OFFSET: "<<id<<std::endl;
    toBeReturned.id = (current_id - 1) + id;
    //std::cout<<"Generating MDFI with ID: "<<toBeReturned.id<<std::endl;
/*    for (int i = 0; i < this->inputAriety; ++i) {
        toBeReturned.inputList[i].value=0.0;
        toBeReturned.inputList[i].presence_bit=false;

    }*/
    for (int i = 0; i < this->dependencies.size(); ++i) {

        toBeReturned.destinationList[i].destination_MDFI = this->dependencies[i]->id - 1 + id;
    }
    return toBeReturned;


}

template
class Node<float>;

template
class Node<int>;
