#ifndef DOUBLE_LIST
#define DOUBLE_LIST

#include "Double_node.h"

template <typename Type>
class Double_list{
    private: 
        //all Double_list variable
        Double_node<Type> *list_head;
        Double_node<Type> *list_tail;
        int list_size;
    public:
        //all method in Double_list class
        Double_list();
        Double_list(const Double_list <Type> &);
        int size() const;
        bool empty() const;
        Type front() const;
        Type back() const;
        Double_node<Type> *head() const;
        Double_node<Type> *tail() const;
        int count(const Type) const;
        void swap(Double_list<Type>&);
        Double_list<Type> operator=(Double_list<Type>);
        void push_front(const Type);
        void push_back(const Type);
        Type pop_front();
        Type pop_back();
        Double_list<Type> operator+ (Double_list<Type>& rhs);
        void merge(Double_list<Type> &second_list);
        int erase(const Type);
        void print();
        //void append(Double_list<Type>);
        ~Double_list();
       
};

template <typename Type>
void testAccessors(Double_list<Type> list);
#endif