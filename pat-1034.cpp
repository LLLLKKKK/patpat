#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;
struct Edge
{
  string s;
  string e;
  int time;
};
int findroot(int index,int* p)
{
  while(p[index] != -1)
    index = p[index];
  return index;
}
void unin(const Edge& edge,map<string,int>& Map,int* p,int* time,int* count)
{
  int index1 = Map[edge.s];
  int index2 = Map[edge.e];
  int r1 = findroot(index1,p);
  int r2 = findroot(index2,p);
  if(r1 != r2)
  {
    if(time[r1] > time[r2])
    {
      count[r1] += count[r2];
      p[r2] = r1;
    }
    else
    {
      count[r2] += count[r1];
      p[r1] = r2;
    }
  }
}
int main()
{
  int n,k;
  cin >> n >> k;
  map<string,int> Map;
  Edge* edge = new Edge[n];
  int vetexnum(0);
  for (int i = 0;i < n;++ i)
  {
    string a,b;
    int t;
    cin >> a >> b >> t;
    edge[i].s = a;
    edge[i].e = b;
    edge[i].time = t;
    if (Map.count(a) == 0)
    {
      Map.insert(make_pair(a,vetexnum));
      ++ vetexnum;
    }
    if (Map.count(b) == 0)
    {
      Map.insert(make_pair(b,vetexnum));
      ++ vetexnum;
    }
  }
  int* p = new int[vetexnum];
  int* time = new int[vetexnum];
  int* count = new int[vetexnum];
  int* total = new int[vetexnum];
  for (int i = 0;i < vetexnum;++ i)
  {
    p[i] = -1;
    time[i] = 0;
    total[i] = 0;
    count[i] = 1;
  }
  for (int i = 0;i < n;++ i)
  {
    time[Map[edge[i].s]] += edge[i].time;
    time[Map[edge[i].e]] += edge[i].time;
  }
  for (int i = 0;i < n;++ i)
    unin(edge[i],Map,p,time,count);
  for (int i = 0;i < n;++ i)
  {
    int r = findroot(Map[edge[i].s],p);
    total[r] += edge[i].time;
  }
  set< pair<string,int> > result;
  for (map<string,int>::iterator it = Map.begin();it != Map.end();++ it)
    if (p[it->second] == -1 && total[it->second] > k && count[it->second] > 2)
      result.insert(make_pair(it->first,count[it->second]));
  cout << result.size() << endl;
  for (set< pair<string,int> >::iterator it = result.begin();it != result.end();++ it)
    cout << it->first << " " << it->second << endl;
}
