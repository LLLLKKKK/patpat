#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char name[100000][9];
int age[100000];
int net[100000];
vector<int> inde;
int index1[100000];
int agee[200];
int agecount[200]={0};
bool my(int a,int b) {
  if(age[a]<age[b])
    return true;
  else if(age[a]==age[b]&&strcmp(name[a],name[b])<0)
    return true;
  return false;
}
bool my1(int a,int b) {
  if(net[a]>net[b])
    return true;
  return false;
}
int n;
int main()
{
  inde.reserve(100000);
  int k;scanf("%d %d", &n,&k);
  for(int i=0;i<n;i++) {
    inde.push_back(i);
    scanf("%s %d %d",name[i],age+i,net+i);
  }
  sort(inde.begin(),inde.end(),my);
  for(int i=0;i<inde.size();i++) {
    agecount[age[inde[i]]]++;
    if(agecount[age[inde[i]]]>100)
      inde.erase(inde.begin()+i);
  }
  for(int i=0;i<200;i++)
    agee[i]=-1;
  for(int i=1;i<inde.size();i++)
    if(age[inde[i]]>age[inde[i-1]])agee[age[inde[i-1]]]=i-1;
  agee[age[inde[inde.size()-1]]]=inde.size()-1;
  int prev=-1;
  for(int i=0;i<200;i++)
    if(agee[i]==-1)agee[i]=prev;
    else prev=agee[i];
  for(int i=0;i<k;i++) {
    int num,start,end;scanf("%d %d %d",&num,&start,&end);
    start=max(age[inde[0]],start);
    printf("Case #%d:\n",i+1);
    int first=agee[start-1]+1,last1=agee[end];
    if (first>last1||(first==end&&age[inde[first]]<start&&age[inde[end]]>end)) {
      puts("None");
    } else {
      last1++;
      int ss=min(first+num,last1);
      
      int bound=first;
      index1[first]=inde[first];
      for(int j=first+1;j<last1;j++) {
        int temp=inde[j]; int k=bound;
        while((k>=first)&&(net[index1[k]]<net[temp])) {
          index1[k+1]=index1[k];
          k--;
        }
        if(bound<ss-1)bound++;
        index1[k+1]=temp;
      }
      
      for (int j=first;j<ss;j++) {
        printf("%s %d %d\n", name[index1[j]],age[index1[j]],net[index1[j]]);
      }
    }
  }
  return 0;
}

