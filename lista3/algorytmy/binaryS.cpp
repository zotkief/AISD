#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int porownania=0;

bool cmp(int val1,int val2)
{
    porownania++;
    return val1>val2;
}
bool cmp2(int val1,int val2)
{
    porownania++;
    return val1==val2;
}
int BS(vector<int>* vec,int num,int low,int high)
{
    if (low > high) 
        return -1;
    int mid=(low+high)/2;
    if(cmp2(vec->at(mid),num))
    {
        return 1;
    }
    else if(cmp(vec->at(mid),num))
    {
        return BS(vec,num,low,mid-1);
    }
    else
    {
        return BS(vec,num,mid+1,high);
    }
}
int main(int argc, char *argv[])
{
    int k=stoi(argv[2]);
    int n=stoi(argv[1]);
    int l;

    std::mt19937 generator;
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss { uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
    generator.seed(ss);

    std::exponential_distribution<double> distribution(0.7);
    std::uniform_int_distribution<int> index(0,n-1);

    //cout<<n<<" "<<k<<endl;

    for(int j=0;j<k;j++)
    {
        porownania=0;
        vector<int> vec;
        int a=distribution(generator);
        vec.push_back(a);

        for(int i=0;i<n;i++)
        {
            a+=distribution(generator);
            a=min(a,2*n-1);
            vec.push_back(a);
        }

        if(argc<4)
        {
            l=vec[index(generator)];
        }
        else if(stoi(argv[3])==-1)
        {
            l=2*n+1;
        }
        else
        {
            l=vec[stoi(argv[3])];
        }
        auto t0 = high_resolution_clock::now();
        BS(&vec,l,0,vec.size()-1);
        auto t1 = high_resolution_clock::now();
        auto dt = duration_cast<nanoseconds>(t1 - t0).count();

        cout<<porownania<<" "<<dt<<endl;
        //cout<<"ns"<<endl;
    }
}