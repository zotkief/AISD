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
template <typename T> bool cmp2(T val1,T val2)
{
    porownania++;
    return val1>=val2;
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
////////////////////
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
//////////////////////////////////////

void dualPivotQuickSort(std::vector<int>* arr, int low, int high, std::vector<int>* base) {
    if (low >= high) return;

    // 1) Wybór pivotów metodą median-of-medians na kopii podtablicy
    int length = high - low + 1;
    int m1 = (length) / 3;
    int m2 = 2 * (length) / 3;

    std::vector<int> tmp(arr->begin() + low, arr->begin() + high + 1);
    int leftPivot = select(&tmp, 0, tmp.size() - 1, m1);
    int rightPivot = select(&tmp, 0, tmp.size() - 1, m2);
    if (leftPivot > rightPivot) std::swap(leftPivot, rightPivot);

    // 2) Znajdź i przesuń pivoty na końce segmentu
    int idxL = low;
    while ((*arr)[idxL] != leftPivot) ++idxL;
    swp(arr, low, idxL);
    int idxR = high;
    while ((*arr)[idxR] != rightPivot) --idxR;
    swp(arr, high, idxR);

    // 3) Trójpodział (3-way partition)
    int lt = low + 1;
    int gt = high - 1;
    int i = low + 1;
    while (i <= gt) {
        if (cmp(leftPivot, (*arr)[i])) {           // (*arr)[i] < leftPivot
            swp(arr, i++, lt++);
        } else if (cmp((*arr)[i], rightPivot)) {  // (*arr)[i] > rightPivot
            swp(arr, i, gt--);
        } else {
            ++i;
        }
    }

    // 4) Umieszczenie pivotów w ostatecznych miejscach
    swp(arr, low, --lt);
    swp(arr, high, ++gt);

    // 5) Rekurencja na trzech podsegmentach
    dualPivotQuickSort(arr, low, lt - 1, base);
    dualPivotQuickSort(arr, lt + 1, gt - 1, base);
    dualPivotQuickSort(arr, gt + 1, high, base);
}


void sort(std::vector<int>* arr,std::vector<int>* base) {
    dualPivotQuickSort(arr, 0, arr->size() - 1,base);
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

        sort(&vec,&base);

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