#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int k=stoi(argv[2]);
    int n=stoi(argv[1]);

    std::mt19937 generator;
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss { uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
    generator.seed(ss);

    std::exponential_distribution<double> distribution(0.3);

    cout<<n<<" "<<k<<endl;

    for(int j=0;j<k;j++)
    {
        int a=distribution(generator);
        cout<<a<<endl;

        for(int i=0;i<n;i++)
        {
            a+=distribution(generator);
            a=min(a,2*n-1);
            cout<<a<<endl;
        }
    }
}