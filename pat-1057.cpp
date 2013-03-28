#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
  int n;scanf("%d",&n);
  stack<int> s; int me;
  vector<int> minheap,maxheap;
  while(n--) {
    char op[11]; scanf("%s",op);
    if (op[1]=='o') {
      if (s.size() == 0) {
        puts("Invalid");
      } else {
        printf("%d\n", s.top());
        s.pop();
      }
    } else if (op[1]=='u') {
      int num; scanf("%d",&num);
      s.push(num);
    } else {
      if (s.size()==0) {
        puts("Invalid"); continue;
      }
    }
  }
  return 0;
}
