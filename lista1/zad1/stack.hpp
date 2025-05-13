#include "ex.hpp"

template<class T> class Stack
{
    struct Node
    {
        T value;
        Node* prev;
        Node(T val)
        {
            value=val;
            prev=nullptr;
        }
    };
    Node* tail;
public:
    Stack()
    {
        tail=nullptr;
    }
    void put(T element)
    {
        Node* nodePtr=new Node(element);
        nodePtr->prev=tail;
        tail=nodePtr;
    }
    T get()
    {
        if(tail==nullptr)
        {
            throw NoElement("no element to get from stack");
        }
        else
        {
            T val=tail->value;
            Node* temp=tail;
            tail=tail->prev;
            delete(temp);
            return val;
        }
    }
    ~Stack()
    {
        while (tail != nullptr)
            get();
    }
};