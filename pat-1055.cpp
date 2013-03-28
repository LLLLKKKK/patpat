#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char name[100000][9];
int age[100000];
int net[100000];
int inde[100000];
int index1[100000];
int agee[200];
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
int mtemp[100000];
void butmerge(int* from, int ileft, int iright,int iend,int* to) {
  int i0=ileft,i1=iright;
  for (int j=ileft;j<iend;j++) {
    if(i0<iright&&(i1>=iend||net[from[i0]]>=net[from[i1]])) {
      to[j]=from[i0];
      i0++;
    } else {
      to[j]=from[i1];
      i1++;
    }
  }
}
int* merges(int n, int* sort, int* work)
{
  for (int width=1;width<n;width=2*width) {
    for (int i=0;i<n;i=i+2*width) {
      butmerge(sort,i,min(i+width,n),min(i+2*width,n),work);
    }
    int *tmp=work; work=sort; sort=tmp;
  }
  return sort;
}
int n;
int main()
{
  int k;scanf("%d %d", &n,&k);
  for(int i=0;i<n;i++) {
    inde[i]=i;
    scanf("%s %d %d",name[i],age+i,net+i);
  }
  sort(inde,inde+n,my);
  for(int i=0;i<200;i++)
    agee[i]=-1;
  for(int i=1;i<n;i++)
    if(age[inde[i]]>age[inde[i-1]])agee[age[inde[i-1]]]=i-1;
  agee[age[inde[n-1]]]=n-1;
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
      /*
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
      */
        for(int j=first;j<last1;j++)
          index1[j]=inde[j];
        int* xx=merges(last1-first,index1+first,mtemp+first);
      for (int j=0;j<ss-first;j++) {
        printf("%s %d %d\n", name[xx[j]],age[xx[j]],net[xx[j]]);
      }
    }
  }
  return 0;
}
