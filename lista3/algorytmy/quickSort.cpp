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
template <typename T> void qsStep(std::vector<T> *vec,int beg,int end,std::vector<T> *base)
{
    if(end-beg<1)
        return;
    
    T pivot=(*vec)[(beg+end)/2];

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