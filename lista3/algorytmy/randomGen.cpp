#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main(int argc, char *argv[])
{
    //int k=stoi(argv[2]);
    int k=5;
    int n=stoi(argv[1]);

    std::mt19937 generator;
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss { uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
    generator.seed(ss);

    std::uniform_int_distribution<int> distribution(0, 2*n-1);

    cout<<n<<" "<<k<<endl;

    for(int j=0;j<k;j++)
        for(int i=0;i<n;i++)
            cout<<distribution(generator)<<endl;
}