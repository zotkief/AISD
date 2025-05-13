#include <iostream>
#include "queue.hpp"
#include "stack.hpp"

using namespace std;

int main()
{
    Queue<int> q;
    cout<<"liczby wsadzane do kolejki:"<<endl;
    for(int i=0;i<50;i++)
    {
        q.put(i);
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"liczby wyciągane z kolejki:"<<endl;


    for(int i=0;i<50;i++)
        cout<<q.get()<<" ";
    cout<<endl;
    

    cout<<"liczby wsadzane do stosu:"<<endl;

    Stack<int> s;
    for(int i=0;i<50;i++)
    {
        s.put(i);
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"liczby wyciągane ze stosu:"<<endl;

    
    for(int i=0;i<50;i++)
        cout<<s.get()<<" ";
    cout<<endl;
}