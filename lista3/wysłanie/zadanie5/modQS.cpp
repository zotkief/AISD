#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int bound=30;
ll przestawienia=0,porownania=0;

bool cmp3(int val1,int val2)
{
    return val1==val2;
}
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

/////////////////////////////
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
int median(vector<int> *vec, int low,int high) {
    vector<int> temp;
    for(int i=low;i<=high;i++)
        temp.push_back(vec->at(i));
    for(int i = 1; i < temp.size(); ++i) 
    {
        int key = temp[i];
        int j = i - 1;
        while(j >= 0 && temp[j] > key) {
            temp[j+1] = temp[j];
            --j;
        }
        temp[j+1] = key;
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
int select(std::vector<int> *vec,int low,int high,int i)
{
    if (low == high) return vec->at(low);
    std::vector<int> M;
    for(int j=low;j<high+1;j+=5)
    {
        int temp=median(vec,j,min(high,j+5-1));
        M.push_back(temp);
    }
    
    int pivot=select(&M,0,M.size()-1,(M.size()-1)/2);
    int r=partition(vec,low,high,pivot);
    int k=r-low;

    if(i==k)
        return vec->at(r);
    if(i<k)
        return select(vec,low,r-1,i);
    else    
        return select(vec,r+1,high,i-k-1);

}
//////////////////////////////


template <typename T> void qsStep(std::vector<T> *vec,int beg,int end,std::vector<T> *base)
{
    if(end-beg<1)
        return;
    
    T pivot=select(vec,beg,end,(end-beg)/2);

    int i=beg,j=end;
    while(i<=j)
    {
        while(i<=end && cmp(pivot,(*vec)[i]))
        {
            i++;
        }
        while(j>=beg && cmp((*vec)[j],pivot))
        {
            j--;
        }

        if(i<=j)
        {
            swp(vec,i,j);
            i++;
            j--;
        }
    }
    if((*base).size()<bound)
    {
        cout<<"kolejny krok"<<endl;
        cout<<"sortowana:";
        show(vec);
        cout<<"startowa:";
        show(base);
    }
    qsStep(vec,beg,j,base);
    qsStep(vec,i,end,base);
}
template <typename T> void quickSort(std::vector<T> *vec,std::vector<T> *base)
{
    qsStep(vec,0,(*vec).size()-1,base);
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

        quickSort(&vec,&base);

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