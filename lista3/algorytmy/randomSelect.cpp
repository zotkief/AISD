#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int bound=30;
ll przestawienia=0,porownania=0;

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
int partition(vector<int> *arr, int low, int high) {
  
    int pivot = arr->at((low+high)/2);
    swp(arr,high,(low+high)/2);
  
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (cmp(pivot,arr->at(j))) {
            i++;
            swp(arr,i,j);
        }
    }
    
    swp(arr,i+1,high);  
    return i + 1;
}
int select(std::vector<int> *vec,int beg,int end,int i,std::vector<int> *base)
{
    if(base->size()<=bound)
    {
        show(vec,beg,end);
    }
    if(beg==end)
        return vec->at(beg);
    int r=partition(vec,beg,end);
    int k=r-beg;

    if(i==k)
        return vec->at(r);
    if(i<k)
        return select(vec,beg,r-1,i,base);
    else    
        return select(vec,r+1,end,i-(k+1),base);


}
int main(int argc,char** argv)
{
    int n,k;
    cin>>n>>k;
    for(int j=0;j<k;j++)
    {

        int l;
        if(argc>1)
            l=atoi(argv[1]);
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

        int res=select(&vec,0,vec.size()-1,l,&base);

    
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