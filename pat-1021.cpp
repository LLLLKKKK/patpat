#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <climits>
#include <deque>
#include <cassert>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <memory>
using namespace std;

//int p_time[1000];
//int f_time[1000];
//int request[1000];
//int finish = 60 * (17 - 8);
//int finish_time[20] = {0};
//int wins[20];
//int cous[20];
//vector<int> wait[20];
//bool ss(int a, int b)
//{
//	if (finish_time[a] > finish_time[b])
//		return true;
//	return false;
//}
//int main()
//{
//	int windows, capacity, k, q;
//	for (int i = 0; i < k; i++)
//		scanf("%d", p_time + i);
//	for (int i = 0; i < q; i++)
//		scanf("%d", request + i);
//
//	for (int i = 0; i < windows; i++)
//		wins[i] = i;
//	for (int i = 0; i < k; i++)
//	{
//		pop_heap(wins, wins + windows - 1, ss);
//		if (finish_time[windows - 1] != 0)
//		{
//			f_time[wins[windows]] = finish_time[windows - 1];
//			cous[windows - 1] = i;
//			
//		}
//		
//	}
//}
int u[10001];
int dist[10001];
vector<int> p[10001];
set<int> s;
int findset(int a)
{
	if (u[a] == a)
		return a;
	return u[a] = findset(u[a]);
}
void un(int a, int b)
{
	int ra = findset(a);
	int rb = findset(b);
	if (ra != rb)
		u[ra] = rb;
}
int bfs(int start)
{
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	int dmax = 0;
	while (!q.empty())
	{
		int n = q.front(); q.pop();
		int d = dist[n];
		for (int i = 0; i < p[n].size(); i++)
			if (dist[p[n][i]] == -1)
			{	dist[p[n][i]] = d + 1; q.push(p[n][i]);}
		if (d > dmax)
			dmax = d;
	}
	return dmax;
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) u[i] = i;
	for (int i = 0; i < n - 1; i++)
	{int a,b; scanf("%d %d", &a, &b); un(a, b); p[a].push_back(b); p[b].push_back(a);}
	int count = 0;
	for (int i = 0; i < n;i++)
		if (u[i] == i)
			count++;
	if (count != 1)
	{
		printf("Error: %d components\n", count); return 0;
	}
	int m = bfs(1);
	for (int i = 1; i <= n; i++)
		if (dist[i] == m)
			s.insert(i);
	m = bfs(*s.begin());
	for (int i = 1; i <= n; i++)
		if (dist[i] == m) s.insert(i);
	for (set<int>::iterator i = s.begin(); i != s.end(); i++)
		printf("%d\n", *i);

	return 0;
}
