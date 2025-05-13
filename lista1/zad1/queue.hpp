#include "ex.hpp"

template<class T> class Queue
{
    struct Node
    {
        T value;
        Node* next;
        Node(T val)
        {
            value=val;
            next=nullptr;
        }
    };
    Node* root;
    Node* tail;
public:
    Queue()
    {
        root=nullptr;
        tail=nullptr;
    }
    void put(T element)
    {
        Node* nodePtr=new Node(element);
        if(root==nullptr)
        {
            tail=nodePtr;
            root=nodePtr;
        }
        else
        {
            tail->next=nodePtr;
            tail=tail->next;
        }
    }
    T get()
    {
        if(root==nullptr)
        {
            throw NoElement("no element to get from queue");
        }
        else
        {
            T val=root->value;
            Node* temp=root;
            root=root->next;
            if(root==nullptr)
                tail=nullptr;
            delete(temp);
            return val;
        }
    }
    ~Queue()
    {
        while (root != nullptr)
            get();
    }
};