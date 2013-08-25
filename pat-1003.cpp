#include <cstdio>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>
using namespace std;
const int N = 500;
bool known[N] = {0};
long dist_now[N];
long hand_now[N] = {0};

int counts[N] = {0};
int map[N][N] = {0};
int hand[N] = {0};

bool comp(int a, int b) {
  if (dist_now[a] < dist_now[b])
	return true;
  return false;
}

int main() {
  int n, m, c1, c2;
  scanf("%d %d %d %d", &n, &m, &c1, &c2);
  for (int i=0;i<n;i++) {
	scanf("%d", hand + i);
	dist_now[i] = numeric_limits<long>::max();
  }
  for (int i=0;i<m;i++) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	map[a][b] = map[b][a] = c;
  }
  deque<int> q;
  dist_now[c1] = 0;
  counts[c1] = 1;
  hand_now[c1] = hand[c1];
  q.push_back(c1);
  for (int i=0;i<n;i++) {
	if (i != c1) q.push_back(i);
  }
  while (!q.empty()) {
	int now = q.front();
   	if (dist_now[now] > dist_now[c2]) break;
	q.pop_front();
	known[now] = true;
	for (int i = 0; i < n; i++) {
	  if (!known[i] && map[now][i] != 0) {
		int dis = dist_now[now] + map[now][i];
		int han = hand_now[now] + hand[i];
		if (dis < dist_now[i]) {
		  dist_now[i] = dis;
		  hand_now[i] = han;
		  counts[i] = counts[now];
		}
		else if (dis == dist_now[i]) {
		  counts[i] += counts[now];
		  if (hand_now[i] < han)
			hand_now[i] = han;
		}
	  }
   	}
	sort(q.begin(), q.end(), comp);
  }
  printf("%d %ld\n", counts[c2], hand_now[c2]); 
  return 0;
}
