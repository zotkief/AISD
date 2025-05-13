#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int bound=0;
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

void dualPivotQuickSort(std::vector<int>* arr, int low, int high,std::vector<int>* base) {
    if (low < high) {
        int leftPivot, rightPivot;

        //swp(arr,low,low+(high-low)/3);
        //swp(arr,high,low+2*(high-low)/3);
        if (cmp((*arr)[low], (*arr)[high]))
            swp(arr,low,high);
        leftPivot = (*arr)[low];
        rightPivot = (*arr)[high];

        int lt = low + 1;
        int gt = high - 1;
        int i = low + 1;

        while (i <= gt) {
            if(lt<high-gt)
            {
                if (cmp(leftPivot,(*arr)[i])) {
                    swp(arr,i,lt);
                    lt++;
                } else if (cmp((*arr)[i],rightPivot)) {
                    swp(arr,i,gt);
                    gt--;
                    i--;
                }
                i++;
            }
            else
            {
                if (cmp((*arr)[i],rightPivot)) {
                    swp(arr,i,gt);
                    gt--;
                    i--;
                } else if (cmp(leftPivot,(*arr)[i])) {
                    swp(arr,i,lt);
                    lt++;
                }
                i++;
            }
        }

        lt--;
        gt++;
        swp(arr,low,lt);
        swp(arr,high,gt);
        if(base->size()<=bound)
        {
            cout<<"tablica sortowana: ";
            show(arr);
            cout<<"tablica referencyjna: ";
            show(base);
        }
        dualPivotQuickSort(arr, low, lt - 1,base);  
        dualPivotQuickSort(arr, lt + 1, gt - 1,base);  
        dualPivotQuickSort(arr, gt + 1, high,base);
    }
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