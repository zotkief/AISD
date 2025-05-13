#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int parts=5;
int bound=30;
ll przestawienia=0,porownania=0;

bool cmp3(int val1,int val2)
{
    return val1==val2;
}
bool cmp(int val1,int val2)
{
    porownania++;
    return val1>val2;
}
void swp(vector<int>* vec,int val1,int val2)
{
    przestawienia+=3;
    swap((*vec)[val1],(*vec)[val2]);
}
void prz(vector<int>* vec,int val1,int val2)
{
    przestawienia++;
    (*vec)[val1]=val2;
}
void show(std::vector<int> *vec,int p,int q)
{
    for(int i=p;i<=q;i++)
    {
        if((*vec)[i]>9)
            cout<<(*vec)[i]<<" ";
        else
            cout<<"0"<<(*vec)[i]<<" ";
    }
    cout<<endl;
}
int median(vector<int> *vec, int low,int high) {
    vector<int> temp;
    for(int i=low;i<=high;i++)
        temp.push_back(vec->at(i));
    for(int i = 1; i < temp.size(); ++i) 
    {
        int key = temp[i];
        int j = i - 1;
        while(j >= 0 && cmp(temp[j] , key)) {
            temp[j+1] = temp[j];
            --j;
        }
        temp[j+1] = key;
        przestawienia+=3;
        przestawienia+=temp.size();
    }
    return temp[temp.size()/2];
}
int partition(vector<int>* vec, int low, int high, int pivot) {
    int pivotIdx = low;
    while (pivotIdx <= high && !cmp3((*vec)[pivotIdx], pivot)) {
        ++pivotIdx;
    }
    if (pivotIdx > high) 
        pivotIdx = high;
    swp(vec, pivotIdx, high);
    int i = low;
    for (int j = low; j < high; ++j) {
        if (cmp(pivot,(*vec)[j])) {
            swp(vec, i, j);
            ++i;
        }
    }
    swp(vec, i, high);
    return i;
}


int select(std::vector<int> *vec,int low,int high,int i,std::vector<int> *base)
{
    if (low == high) return vec->at(low);

    if(base->size()<=bound)
    {
        show(vec,low,high);
    }
    std::vector<int> M;
    for(int j=low;j<high+1;j+=parts)
    {
        int temp=median(vec,j,min(high,j+parts-1));
        M.push_back(temp);
    }
    
    int pivot=select(&M,0,M.size()-1,(M.size()-1)/2,base);
    int r=partition(vec,low,high,pivot);
    int k=r-low;

    if(i==k)
        return vec->at(r);
    if(i<k)
        return select(vec,low,r-1,i,base);
    else    
        return select(vec,r+1,high,i-k-1,base);

}
int main(int argc,char** argv)
{
    int n,k,l;
    l=stoi(argv[1]);
    if(argc>2)
    {
        parts=stoi(argv[2]);
    }
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
            show(&vec,0,n-1);

        int res=select(&vec,0,vec.size()-1,l-1,&base);

    
        if(n<bound)
        {
            cout<<"wynik:"<<endl<<"statystyka pozycyjna:"<<res<<endl;
            cout<<"stan kocowy:"<<endl;
            show(&vec,0,vec.size()-1);
            cout<<"początkowy stan tablicy:"<<endl;
            show(&base,0,base.size()-1);
            cout<<"posortowana:"<<endl;
            sort(base.begin(),base.end()); 
            show(&base,0,base.size()-1);
        }


        cout<<porownania<<" "<<przestawienia<<endl;
        porownania=0,przestawienia=0;
    }
}