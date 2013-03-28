#include <cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int mice[1000];
int ranking[1000];
vector<int> now;
vector<int> tmp;
int main()
{
  now.reserve(1000);
  tmp.reserve(1000);
  int np,ng; scanf("%d %d",&np,&ng);
  for(int i=0;i<np;i++) scanf("%d",mice+i);
  for(int i=0;i<np;i++) { int in;scanf("%d",&in); now.push_back(in); }
  while(now.size() != 1) {
    int ranknow=now.size()/ng+1;
    if(now.size()%ng!=0)ranknow++;
    for(int i=0;i<now.size();i+=ng) {
      int maxp=now[i]; int fat=mice[maxp];
      for(int j=i;j<min((int)now.size(),i+ng);j++) {
        ranking[now[j]]=ranknow;
        if(mice[now[j]]>fat) {
          maxp=now[j]; fat=mice[maxp];
        }
      }
      tmp.push_back(maxp);
    }
    tmp.swap(now);
    tmp.clear();
  }
  ranking[now[0]]=1;
  for(int i=0;i<np-1;i++)
    printf("%d ", ranking[i]);
  printf("%d\n", ranking[np-1]);
  return 0;
}

