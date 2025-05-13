#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include "list.hpp"

using namespace std;

int main()
{
    vector<int> arr;
    List<int> list;

    std::mt19937 generator;
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss { uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
    generator.seed(ss);

    //merging
    std::uniform_int_distribution<int> mergeDst(10, 99);
    List<int> l1,l2;
    for(int i=0;i<10;i++)
    {
        l1.insert(mergeDst(generator));
        l2.insert(mergeDst(generator));
    }
    cout<<"pierwsza lista:"<<endl;
    l1.show();
    cout<<"druga lista:"<<endl;
    l2.show();

    l1.merge(&l2);

    cout<<"zlaczona lista:"<<endl;
    l1.show();
    //merging
    
    std::uniform_int_distribution<int> distribution(0, 100000);
        
    for(int i=0;i<10000;i++)
    {
        arr.push_back(distribution(generator));
        list.insert(arr[i]);
    }

    uniform_int_distribution<int> dirDST(0, 1);

    //przykład z losowymi
    long long operations=0;
    for(int i=0;i<1000;i++)
    {   
        operations+=list.find(distribution(generator));
    }
    cout<<"wyszukiwanie losowych: "<<((double)operations)/1000.0<<endl;
    //przykład z losowymi

    //przykład ze wszystkimi
    long long number=0;

    while(arr.size()>0)
    {
        uniform_int_distribution<int> dst(0, arr.size());
        int index=dst(generator);
        
        number+=list.find(arr[index]);

        arr.erase(arr.begin()+index);
    }
    cout<<"wyszukiwanie wszystkich: "<<((double)number)/10000.0<<endl;
    //przykład ze wszystkimi
}