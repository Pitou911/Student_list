#ifndef DOUBLE_NODE
#define DOUBLE_NODE


template <typename Type>
class Double_node{
    private: 
        //all Double_node valriable
        Double_node *next;
        Double_node *prev;
        Type Data;
    public:
        //all method in Double_node class
        Double_node(Type);
        Double_node *getNext() const;
        void setNext(Double_node *);
        Double_node *getPrev() const;
        void setPrev(Double_node *);
        Type getData() const;
        void setData(const Type&);
        Type *getDataAddress();
};

#endif