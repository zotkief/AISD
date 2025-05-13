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

template <typename T>
void merge(std::vector<T>* vec1, std::vector<T>* vec2, std::vector<T>* res)
{
    while (vec1->size()!=0 && vec2->size()!=0)
    {
        if (cmp(vec1->front(),vec2->front()))
        {
            prz(res, vec2);
        }
        else
        {
            prz(res, vec1);
        }
    }

    while (vec1->size()>0)
    {
        prz(res, vec1);
    }

    while (vec2->size()>0)
    {
        prz(res, vec2);
    }
}


template <typename T> vector<int>* subsort(std::vector<T> *vec,std::vector<T> *base)
{
    vector<vector<T>*> runs;
    while(!vec->empty())
    {
        vector<T>* run=new vector<T>();
        prz(run,vec);
        while(!vec->empty() && cmp2(vec->front(),run->back()))
            prz(run,vec);
        runs.insert(runs.begin(),run);
    }

    if(base->size()<=bound)
    {
        cout<<"kolejny krok:"<<endl;
        for(int i=0;i<runs.size();i++)
            show(runs.at(i));
        cout<<"porównanie:"<<endl;
        show(base);
    }
    while(runs.size()>1)
    {
        //for(int i=0;i<runs.size();i++)
            //show(runs.at(i));
        int i=0;
        while(i+1<runs.size())
        {
            vector<T>* res=new vector<T>();
            vector<T>* v1=runs.at(i);
            vector<T>* v2=runs.at(i+1);
            runs.erase(runs.begin()+i+1);
            merge(v1,v2,res);
            delete v1;
            delete v2;
            runs[i]=res;
            i++;
        }
        if(base->size()<=bound)
        {
            cout<<"kolejny krok:"<<endl;
            for(int i=0;i<runs.size();i++)
                show(runs.at(i));
            cout<<"porównanie:"<<endl;
            show(base);
        }
    }
    return runs.at(0);
    //for(int i=0;i<runs.size();i++)
        //show(runs.at(i));
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

        vector<int>* sorted=subsort(&vec,&base);

        cout<<"posortowana:";

        if(n<=bound)
            show(sorted);

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