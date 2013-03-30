#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
multiset<int> mins, maxs;
int mid=-1;
int main() {
  int n;scanf("%d",&n);
  stack<int> s; int me;
  while(n--) {
    char op[11]; scanf("%s",op);
    /*
    for(auto i=mins.begin();i!=mins.end();i++)
      printf("%d ", *i);
    puts("min");
    for(auto i=maxs.begin();i!=maxs.end();i++)
      printf("%d ", *i);
    puts("max");
    */
    if (strcmp(op,"Pop")==0) {
      if (s.size() == 0) {
        puts("Invalid");
      } else {
        int pp=s.top(); s.pop();
        printf("%d\n",pp);
        if(mid>=pp) {
          auto tt=mins.find(pp);
          //if(tt!=mins.end())
            mins.erase(tt);
        } else {
          auto tt=maxs.find(pp);
          //if(tt!=maxs.end())
            maxs.erase(tt);
        }
      if(mins.size()>maxs.size()+1) { 
        auto it=mins.end(); it--;
        auto tt=it; tt--;
        mid=*tt;
        maxs.insert(*it);
        mins.erase(it);
      } else if(maxs.size()>mins.size()) {
        auto it=maxs.begin();
        mid=*it;
        mins.insert(mid);
        maxs.erase(it);
      }
      }
    } else if (strcmp(op,"Push")==0) {
      int num; scanf("%d",&num);
      if(s.size()==0) 
      { mins.insert(num); mid=num; }
      else if(num<=mid) 
        mins.insert(num);
      else
        maxs.insert(num);
      s.push(num);
      if(mins.size()>maxs.size()+1) { 
        auto it=mins.end(); it--;
        auto tt=it; tt--;
        mid=*tt;
        maxs.insert(*it);
        mins.erase(it);
      } else if(maxs.size()>mins.size()) {
        auto it=maxs.begin();
        mid=*it;
        mins.insert(mid);
        maxs.erase(it);
      }
    } else if(strcmp(op,"PeekMedian")==0){
      if (s.size()==0) {
        puts("Invalid");
      } else {
        printf("%d\n", mid);
      }
    } else {
      puts("Invalid");
    }
  }
  return 0;
}
