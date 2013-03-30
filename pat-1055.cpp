#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char name[100000][9];
int age[100000];
int net[100000];
struct pp{
  char name[9];
  int age;
  int net;
};
pp inde3[100000];
int inde[100000];
int inde2[100000];
int index1[100000];
bool my(pp a,pp b) {
  if(a.net!=b.net) {
    return a.net>b.net;
  } else if(a.age!=b.age) {
    return a.age<b.age;
  } else {
    return strcmp(a.name,b.name)<0;
  }
}
bool my2(int a,int b) {
  if(net[a]!=net[b]) {
    return net[a]>net[b];
  }else if(age[a]!=age[b]) {
    return age[a]<age[b];
  }else {
    return strcmp(name[a],name[b])<0;
  }
}
int agecount[201]={0};
int main()
{
  int k,n;scanf("%d %d", &n,&k);
  for(int i=0;i<n;i++) {
    inde[i]=i;
    scanf("%s %d %d",name[i],age+i,net+i);
    //scanf("%s %d %d",inde3[i].name,&inde3[i].age,&inde3[i].net);
  }
  sort(inde,inde+n,my2);
  //sort(inde3,inde3+n,my);
  int n2=0;
  //for(int i=0;i<n;i++)
   // if(++agecount[inde3[i].age]<=100) inde3[n2++]=inde3[i];
  for(int i=0;i<n;i++)
    if(++agecount[age[inde[i]]]<=100) inde[n2++]=inde[i];

  for(int i=0;i<k;i++) {
    int num,start,end;scanf("%d %d %d",&num,&start,&end);
    printf("Case #%d:\n",i+1);
    bool flag=false;
    for(int j=0;j<n2;j++) {
      if(age[inde[j]]>=start&&age[inde[j]]<=end) {
        printf("%s %d %d\n", name[inde[j]],age[inde[j]],net[inde[j]]);
      //if(inde3[j].age>=start&&inde3[j].age<=end) {
      //  printf("%s %d %d\n", inde3[j].name,inde3[j].age,inde3[j].net);
        flag=true;
        num--; if(!num)break;
      }
    }
    if(!flag) {
      puts("None");
    }
  }
  return 0;
}

