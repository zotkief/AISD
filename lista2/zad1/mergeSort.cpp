#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int bound=40;
ll przestawienia=0,porownania=0;

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
template <typename T> void prz(vector<T>* vec,vector<T>* src)
{
    przestawienia++;
    vec->push_back(src->front());
    src->erase(src->begin());
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

template <typename T> void merge(std::vector<T>* vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> leftVec(n1), rightVec(n2);

    for (int i = 0; i < n1; ++i)
    {
        leftVec[i] = (*vec)[left + i];
        przestawienia++;
    }
    for (int i = 0; i < n2; ++i)
    {
        rightVec[i] = (*vec)[mid + 1 + i];
        przestawienia++;
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (cmp2(rightVec[j],leftVec[i])) {
            (*vec)[k] = leftVec[i];
            i++;
        } else {
            (*vec)[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        przestawienia++;
        (*vec)[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        (*vec)[k] = rightVec[j];
        przestawienia++;
        j++;
        k++;
    }
}

template <typename T> void mergeSort(std::vector<T>* vec, int left, int right,std::vector<T>* base) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(vec, left, mid,base);
    mergeSort(vec, mid + 1, right,base);

    if(base->size()<=bound)
    {
        cout<<"sortowana:"<<endl;
        show(vec);
        cout<<"porownanie"<<endl;
        show(base);
    }

    merge(vec, left, mid, right);
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

        mergeSort(&vec,0,vec.size()-1,&base);

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