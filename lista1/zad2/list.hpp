#include "ex.hpp"

template<class T> class List
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
            current=nodePtr;
        }
        else
        {
            nodePtr->next=current->next;
            current->next=nodePtr;
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
        for(int i=0;i<elementCount;i++)
        {
            operations++;
            if(get()==element)
                return operations;
            
            next();
        }
        return operations;
    }
};