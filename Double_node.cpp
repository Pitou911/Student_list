#include "Double_node.h"

#include <iostream>
#include <stdexcept>
using namespace std;

//Double_node class constructor.
//Set next and prev to NUll, and Data to inputed parameter
template <typename Type>
Double_node<Type>::Double_node(Type Data){
    this->Data = Data;
    this->next = NULL;
    this->prev = NULL;
}

//Set next pointer in the node
template <typename Type>
void Double_node<Type>::setNext(Double_node<Type> *next){
    this->next = next;
}

//get the next pointer in the node
template <typename Type>
Double_node<Type> *Double_node<Type>::getNext() const{
    return this->next;
}

//set the prev pointer in the node
template <typename Type>
void Double_node<Type>::setPrev(Double_node<Type> *prev){
    this->prev = prev;
}

//get prev pointer in the node
template <typename Type>
Double_node<Type> *Double_node<Type>::getPrev() const{
    return this->prev;
}

//get data in the node
template <typename Type>
Type Double_node<Type>::getData() const{
    return this->Data;
}

//set Data in the node
template <typename Type>
void Double_node<Type>::setData(const Type& Data){
    this->Data = Data;
}

template <typename Type>
Type* Double_node<Type>::getDataAddress()
{
    Type *temp = &this->Data;

    return temp;
}