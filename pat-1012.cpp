#include <iostream>  
#include <vector>  
using namespace std;  
#include<vector>  
#include<map>  
#include<algorithm>  
  
struct Stu  
{  
    int id;  
    int C;  
    int M;  
    int E;  
    int A;  
};  
  
bool sortByC(Stu a,Stu b)  
{  
    return a.C > b.C;  
}  
  
bool sortByM(Stu a,Stu b)  
{  
    return a.M>b.M;  
}  
  
bool sortByE(Stu a,Stu b)  
{  
    return a.E>b.E;  
}  
  
bool sortByA(Stu a,Stu b)  
{  
    return a.A>b.A;  
}  
  
int main()  
{  
    vector<Stu> v;  
    map<int,char> mType;  
    map<int,int> mRank;  
    int N;  
    int M;  
    int Q;  
  
    cin>>N;  
    cin>>M;  
  
    for(int i=0;i<N;i++)  
    {  
        Stu s;  
        cin>>s.id;  
        cin>>s.C;  
        cin>>s.M;  
        cin>>s.E;  
        s.A = (s.C + s.M + s.E)/3;  
        v.push_back(s);  
    }  
  
    int score=-1;  
    int rank=0;  
    sort(v.begin(),v.end(),sortByA);  
    for(int i=0;i<v.size();i++)  
    {  
        if(v[i].A!=score)  
        {  
            rank=i+1;  
        }  
        score= v[i].A;  
        mRank[v[i].id] = rank;  
        mType[v[i].id] = 'A';     
    }  
    score=-1;  
    rank=0;  
    sort(v.begin(),v.end(),sortByC);  
    for(int i=0;i<v.size();i++)  
    {  
        if(v[i].C!=score)  
        {  
            rank=i+1;  
        }  
        score= v[i].C;  
  
        if(mRank[v[i].id]>rank)  
        {  
            mRank[v[i].id] = rank;  
            mType[v[i].id] = 'C';  
        }  
      
    }  
    score=-1;  
    rank=0;  
    sort(v.begin(),v.end(),sortByM);  
    for(int i=0;i<v.size();i++)  
    {  
        if(v[i].M!=score)  
        {  
            rank=i+1;  
        }  
        score= v[i].M;  
  
        if(mRank[v[i].id]>rank)  
        {  
            mRank[v[i].id] = rank;  
            mType[v[i].id] = 'M';  
        }  
    }  
    score=-1;  
    rank=0;  
    sort(v.begin(),v.end(),sortByE);  
    for(int i=0;i<v.size();i++)  
    {  
        if(v[i].E!=score)  
        {  
            rank=i+1;  
        }  
        score= v[i].E;  
        if(mRank[v[i].id]>rank)  
        {  
            mRank[v[i].id] = rank;  
            mType[v[i].id] = 'E';  
        }  
    }  
      
    for(int i=0;i<M;i++)  
    {  
        cin>>Q;  
        if(mType.count(Q))  
            cout<<mRank[Q]<<" "<<mType[Q]<<endl;  
        else  
            cout<<"N/A"<<endl;  
    }  
  
}  
