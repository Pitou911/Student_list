#include "Double_list.h"
#include <iostream>
using namespace std;

template <typename Type>


// create a empty list constructor
Double_list<Type>::Double_list(){
    //set list_head and list_size to NULL and list_size to 0
    this->list_head = NULL;
    this->list_tail = NULL;
    this->list_size = 0;
}

// copy the constructor
template <typename Type>
Double_list<Type>::Double_list(const Double_list<Type> &dl){
  // check if the node in parameter is empty
    if(dl.list_head == NULL){ 
        this->list_head = this->list_tail = NULL;
        this->list_size = 0;
        return;
    }else{
      // create a new node with data that the parameter's head points to and point this list head to that node
        this->list_head = new Double_node<Type>(dl.list_head->getData());
        // create a node pointer points to the next node of the list head of the list in parameter
        Double_node<Type> *tempNext = dl.list_head->getNext();
        // create a node pointer point to this list head, in order to know the last node
        Double_node<Type> *temp = this->list_head;
        //increase the list size by 1
        this->list_size = 1;
        while(tempNext != NULL){
          // while next node of list head of the parameter list is not NULL
          // create a new node with data of the next node of parameter's list head
            Double_node<Type> *newNode = new Double_node<Type>(tempNext->getData());
            // set the next point of temp to that new node
            temp->setNext(newNode);
            // set the previous pointer of new node points to temp
            newNode->setPrev(temp);
            // move temp pointer to the next node
            temp = temp->getNext();
            // move tempnext pointer to the next node
            tempNext = tempNext->getNext();
            this->list_size++;
        }
        // assign the list tail to the last node which is the temp node
        this->list_tail = temp;
    }
}
//function for returning size of the list
template <typename Type>
int Double_list<Type>::size() const{
    return this->list_size;
}
//checkng the empty list 
template <typename Type>
bool Double_list<Type>::empty() const{
    return list_size==0;
}

// return the data of the first node
template <typename Type>
// Need to throw an exception
Type Double_list<Type>::front() const{
    if (empty())
    {
        throw underflow_error("underflow!!!");
    }
    return this->list_head->getData();
}

// return the data of the last node
template <typename Type>
// Need to throw an exception
Type Double_list<Type>::back() const{

    if (empty())
    {
        throw underflow_error("underflow!!!");
    }

    return this->list_tail->getData();
}

// return the address of the first node that head points to
template <typename Type>
Double_node<Type>* Double_list<Type>::head()const{
    return this->list_head;
}

// return the address of the last node that tail points to
template <typename Type>
Double_node<Type>* Double_list<Type>::tail()const{
    return this->list_tail;
}

// return the number of node whose data is equal to the value in the parameter
template <typename Type>
int Double_list<Type>::count(const Type obj) const{
    Double_node<Type> *curr = this->list_head;
    int count = 0;
    while(curr != NULL){
        if(curr->getData() == obj){
            count++;
            curr = curr->getNext();
        }else{
            curr = curr->getNext();
        }
    }
    return count;
}


//swap 2 list by taking other list as parameter
template <typename Type>
void Double_list<Type>::swap(Double_list<Type> &list){
    
    //create temp head, tail and size, and set it to this list
    Double_node<Type> *hTemp = this->list_head;
    Double_node<Type> *tTemp = this->list_tail;
    int sizeTemp = this->list_size;

    //set the list head, tail and size to other list
    this->list_head = list.list_head;
    this->list_tail = list.list_tail;
    this->list_size = list.list_size;

    //set parameter's list to temp
    list.list_head = hTemp;
    list.list_tail = tTemp;
    list.list_size = sizeTemp;

}

// = assignment operator
template <typename Type>
Double_list<Type> Double_list<Type>::operator=(Double_list<Type> rhs)
{
    //create new empty list
    //create a temp node pointer to tranverse through the list
    Double_node<Type> *temp = rhs.list_head;
    Double_list<Type> newList;
    
    //Copy all right hand side(rhs) node to the new list
    //loop for list_size times and push right hand size(rhs) node or temp node to new list 
    for (int i = 0; i < rhs.list_size; i++)
    {
        newList.push_back(temp->getData());
        temp = temp->getNext();
    }

    //swap left hand side list with new list
    swap(newList);

    //Delete new list that has swaped by access the node one by one and delete it
    //loop until new list head == NULL
    while(newList.list_head != NULL)
    {
        Double_node<Type> *temp2 = newList.list_head;
        newList.list_head = newList.list_head->getNext();
        delete temp2;
    }

    
    //return left hand side list or this list
    return *this;

}

// push the data in parameter to the list from the head
template <typename Type>
void Double_list<Type>::push_front(const Type obj){

    //create new node of the that store the data
    Double_node<Type> *temp = new Double_node<Type>(obj);
    if(list_head == NULL){
        list_head = temp;
        list_tail = temp;
    }else{
        //assign temp as the previous node of the head node
        list_head->setPrev(temp);
        //set list_head as the next node of temp node 
        temp->setNext(list_head);
        //assign temp as head node
        list_head = temp;
    }
    //increase the list size by one
    list_size++;
}

// push the data in parameter to the list from the tail which is the last node
template <typename Type>
void Double_list<Type>::push_back(const Type obj){
    //create new node of the that store the data
    Double_node<Type> *temp = new Double_node<Type>(obj);
    //check if the node is empty
    if(list_tail == NULL){
        list_head = temp;
        list_tail = temp;
    }else{
        //assign temp as the next node of the tail 
        list_tail->setNext(temp);
        //set list_tail as the previous node of temp node 
        temp->setPrev(list_tail); 
        //assign temp as the last node
        list_tail = temp;
    }
    //increase the list size by one
    list_size++;
}

// return the data of the front node that was deleted
template <typename Type>
Type Double_list<Type>::pop_front(){
    //assign pointer point to the first node
    Double_node<Type> *curr = this->list_head;
    Type pop;
    //need exception
    if(empty())
    {
        throw underflow_error("underflow!!!");
    }
    else if (list_size == 1 )
    {
        //just added else if statement, to solve the problem in demonstration
        this->list_tail = NULL;
        this->list_head = NULL;
        this->list_size--;
        pop = curr->getData();
        delete curr;
    }
    else{
        //assign next node as the head
        this->list_head = curr->getNext();
        //set the previous node of the head to null
        this->list_head->setPrev(NULL);
        //decrease the size of the list
        this->list_size--;
        //get data from the front node
        pop = curr->getData();
        //delete node to free the memory
        delete curr;
    }
    //return value that we have pop
    return pop;
    
}


// return the data of the last node that was deleted
template <typename Type>
Type Double_list<Type>::pop_back(){
    //create new node pointer that point to the last node
    Double_node<Type> *curr = this->list_tail;
    Type pop;
    if(empty()){
        throw underflow_error("underflow!!!");
    }
    else
    {
        //create new node pointer that point to the previous node of the tail
        Double_node<Type> *tempPrev = curr->getPrev();
        if (list_size != 1)
        {
            //assign previous node as the last node or tail
            this->list_tail = tempPrev;
            //set the next node of the tail to NUll
            this->list_tail->setNext(NULL);
        }
        else
        {
            this->list_head = this->list_tail =  NULL;
        }
        //decrease size of the node
        this->list_size--;
        //get data from the last node that we store at first
        pop = curr->getData();
        delete curr;

    }
    return pop;
    
}

template <typename Type>
Double_list<Type> Double_list<Type>:: operator + (Double_list<Type>& rhs)
{
    Double_list<Type> newList;
    Double_node<Type>* temp = this->head();
    while(temp != NULL)
    {
        newList.push_back(temp->getData());
        temp = temp->getNext();
    }

    temp = rhs.head();
    while(temp != NULL)
    {
        newList.push_back(temp->getData());
        temp = temp->getNext();
    }

    return newList;
}

template <typename Type>
void Double_list<Type>::merge(Double_list<Type> &second_list){
    *this = *this + second_list;
    sortId(*this);
}

template <typename Type>
int Double_list<Type>::erase(const Type obj){
    //create a node pointer to tranverse through the list
    Double_node<Type>* temp = list_head;
    
    //create a boolean to keep track if we have erased a node yet
    bool erased = false;
    
    //run the loop until the end of the list or until a node is erased
    while (temp != NULL && !erased)
    {
        //check if the node matches with the key 
        if (temp->getData() == obj)
        {
            //check if the matched node is the first node of the list and re-asign the pointer on the leftside of the node
            if (temp->getPrev() == NULL)
            {
                list_head = temp->getNext();  
            }else
            {
                temp->getPrev()->setNext(temp->getNext());
            }

            //check if the matched node is the last node of the list and re-assign the pointers on the rightside of the node
            if(temp->getNext() == NULL)
            {
                list_tail = temp->getPrev();
            }else 
            {
                temp->getNext()->setPrev(temp->getPrev()) ;
            }

            //de-allocate the memory of the matched list
            delete temp;
            erased = true;

            //decrement the size of the list
            this->list_size--;
        }
        temp = temp->getNext();
    }
    //return 1 or 0 accordingly
    return erased;
}

//template <typename Type>
//void Double_list<Type>::append(Double_list<Type> second_list){
//    Double_node<Type> *temp = second_list.list_head;
//    while(temp != NULL){
//      this->push_back(temp->getData());
//      temp = temp->getNext();
//    }
//}

//print the list 
template <typename Type>
void Double_list<Type>::print()
{
    //create a node pointer to tranverse through the list
    Double_node<Type>* temp = list_head;
    
    //visit each node and print out its data until the end of the list
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

template <typename Type>
Double_list<Type>::~Double_list(){
    //tranverse through the list until the end
    while(list_head != NULL){
        //store the memory of the current node to de-allocate
        Double_node<Type> *current = list_head;
        //point the head to the next node
        list_head = list_head->getNext();
        //decrement the list size and de-allocate the memory
        list_size--;
        delete current;
    }
    this->list_tail = NULL;
}


//print out all accessors in Double_list object by taking the list and count key as parameter
template <typename Type>
void testAccessors(Double_list<Type> list)
{
    //check whether the list is empty and display list size
    cout << "Empty? :" << list.empty() << endl;
    cout << "size: " << list.size() << endl;

    //try to display the front node of the list, if the list is empty the front method will throw the exception
    try
    {
        cout << "front: " << list.front() << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    

    //try to display the back node of the list, if the list is empty the back function will throw the exception
    try
    {
        cout << "back: " << list.back() << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    //Display head and tail pointer
    cout << "head: " << list.head() << endl;
    cout << "tail: " << list.tail() << endl;
}