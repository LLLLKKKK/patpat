#include <cstdio>
#include <vector>
#include <deque>
using namespace std;
vector<int> children[100];
int main() {
  int n, in;
  scanf("%d%d", &n, &in);
  for (int i=0;i<in;i++) {
	int rt, k;
	scanf("%d%d", &rt, &k);
	for (int j=0;j<k;j++) {
	  int c;
	  scanf("%d", &c);
	  children[rt].push_back(c);
	}
  }
  bool flag=false;
  deque<int> level;
  deque<int> level_next;
  level.push_back(1);
  do {
	int count = 0;
	for (auto i=0;i<level.size();i++) {
	  if (children[level[i]].size() != 0) {
		for (auto j=0;j<children[level[i]].size();j++) {
		  level_next.push_back(children[level[i]][j]);
		}
	  }
	  else {
		count++;
	  }
	}
	level.clear();
	level.swap(level_next);
	if (flag)
	  printf(" %d", count);
	else {
	  printf("%d", count);
	  flag = true;
	}
  } while (level.size() != 0);
  putchar('\n');
  return 0;
}
