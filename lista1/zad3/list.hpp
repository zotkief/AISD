#include <random>
#include <chrono>

#include "ex.hpp"

template<class T> class List
{
    struct Node
    {
        T value;
        Node* next;
        Node* prev;
        Node(T val)
        {
            value=val;
            next=nullptr;
            prev=nullptr;
        }
    };
    Node* current;
    int elementCount;
public:
    List()
    {
        current=nullptr;
        elementCount=0;
    }
    void insert(T element)
    {
        Node* nodePtr=new Node(element);
        if(current==nullptr)
        {
            nodePtr->next=nodePtr;
            nodePtr->prev=nodePtr;
            current=nodePtr;
        }
        else
        {
            current->next->prev=nodePtr;
            nodePtr->next=current->next;
            current->next=nodePtr;
            nodePtr->prev=current;
        }
        elementCount++;
    }
    void merge(List<T>* list)
    {
        if(list->elementCount==0 && elementCount==0)
        {
            return;
        }
        else if(list->elementCount==0)
        {
            list->current=current;
            list->elementCount=elementCount;
        }
        else if(elementCount==0)
        {
            current=list->current;
            elementCount=list->elementCount;
        }
        else 
        {
            Node* tempInternal=current->next;
            Node* tempExternal=list->current->next;

            list->current->next=tempInternal;
            current->next=tempExternal;

            tempExternal->prev=current;
            tempInternal->prev=list->current;

            elementCount=elementCount+list->elementCount;
            list->elementCount=elementCount;
        }
    }
    T get()
    {
        if(current==nullptr)
        {
            throw NoElement("no element to get from list");
        }
        else
        {
            T val=current->value;
            return val;
        }
    }
    void next()
    {
        if(current==nullptr)
        {
            throw NoElement("nothing to iterate");
        }
        else
        {
            current=current->next;
        }
    }
    void prev()
    {
        if(current==nullptr)
        {
            throw NoElement("nothing to iterate");
        }
        else
        {
            current=current->prev;
        }
    }
    int size()
    {
        return elementCount;
    }
    void show()
    {
        for(int i=0;i<elementCount;i++)
        {
            std::cout<<get()<<" ";
            next();
        }
        std::cout<<std::endl;
    }
    int find(T element)
    {
        int operations=0;

        std::mt19937 generator;
        uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::seed_seq ss { uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
        generator.seed(ss);

        std::uniform_int_distribution<int> dst(0, 1);

        bool direction=dst(generator);

        for(int i=0;i<elementCount;i++)
        {
            operations++;
            if(get()==element)
                return operations;
            
            if(direction)
                next();
            else
                prev();
        }
        return operations;
    }
};