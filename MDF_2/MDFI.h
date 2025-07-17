//
// Created by giaco on 07/07/2022.
//

#ifndef SPM_MDFI_H
#define SPM_MDFI_H
#include <stdlib.h>
#include <vector>
#include <functional>
#include <map>
#include "Token.h"
#include "Destination_Token.h"
#include <shared_mutex>
#include "shared_queue.cpp"


template<class T>
class MDFI {
public:
    long unsigned int id=0;
    std::function<std::vector<T>(std::vector<T>)> executable_function;
    std::vector<Token> inputList;
    std::vector<Destination_Token> destinationList;
    std::vector<T> input_array;
    std::vector<T> output_array;
    bool isLast=false;
    std::map<unsigned long, MDFI<T>> *pMap;
    sharedQueue<unsigned long int> *toPromote;

    bool firable=false;
    void updateFromToken(int i);
    std::shared_mutex *mutexPointer;


    bool checkIfFirable();

    void move_to_input();
    void execute();
};


#endif //SPM_MDFI_H
