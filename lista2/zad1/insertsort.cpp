#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int bound=0;
ll porownania=0,przestawienia=0;

template <typename T> bool cmp(T val1,T val2)
{
    porownania++;
    return val1>val2;
}
template <typename T> void swp(vector<T>* vec,int val1,int val2)
{
    przestawienia+=3;
    swap((*vec)[val1],(*vec)[val2]);
}
template <typename T> void prz(vector<T>* vec,int val1,T val2)
{
    przestawienia++;
    (*vec)[val1]=val2;
}
template <typename T> void show(std::vector<T> *vec)
{
    for(int i=0;i<(*vec).size();i++)
    {
        if((*vec)[i]>9)
            cout<<(*vec)[i]<<" ";
        else
            cout<<"0"<<(*vec)[i]<<" ";
    }
    cout<<endl;
}
template <typename T> void insertionSort(vector<T> *vec,vector<T> *base)
{
    int n=(*vec).size();
    for(int i=1;i<n;i++)
    {
        int key=(*vec)[i];
        int j=i;
        while(j-1>=0 && cmp((*vec)[j-1],key))
        {
            prz(vec,j,(*vec)[j-1]);
            j--;
        }
        prz(vec,j,key);

        if((*vec).size()<bound)
        {
            cout<<"kolejny krok:";
            show(vec);
            cout<<"porownanie:";
            show(base);
        }
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int j=0;j<k;j++)
    {
        vector<int> vec,base;
        if(n<bound)
            cout<<"tablica wyjściowa"<<endl;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec.push_back(a);
            base.push_back(a);
        }
        if(n<bound)
            show(&vec);

        insertionSort(&vec,&base);

        if(n<bound)
            cout<<"posortowana:";

        if(n<bound)
            show(&vec);

        cout<<porownania<<" "<<przestawienia<<endl;
        porownania=0,przestawienia=0;
        for(int i=1;i<n;i++)
        {
            if(vec[i-1]>vec[i])
            {
                cout<<"bląd sortowania"<<endl;
                break;
            }
        }
    }
}