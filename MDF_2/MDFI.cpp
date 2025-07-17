//
// Created by giaco on 07/07/2022.
//

#include "MDFI.h"

template<class T>
void MDFI<T>::move_to_input()
{
    for(int i=0;i<this->inputList.size();i++)
        this->updateFromToken(i);
}
template<class T>
void MDFI<T>::updateFromToken(int i){
    if(this->inputList[i].presence_bit)
  this->input_array[i]=this->inputList[i].value;
}
template<class T>
bool MDFI<T>::checkIfFirable(){
   int counter_false=0;
    for(auto i :this->inputList)
        if(!i.presence_bit)
            counter_false++;
    if(counter_false>0)
        return false;
    return true;

}
template<class T>
void MDFI<T>::execute() {
    for (int i = 0; i < this->inputList.size(); ++i) {
        this->input_array[i]=this->inputList[i].value;
    }
    this->output_array=this->executable_function(this->input_array);
}


/*
void MDFI::createDestinationToken(){
    for(int i=0;i<this->output_array.size();i++){
        this->destinationList[i].
    }
}*/
template class MDFI<float>;
template class MDFI<int>;