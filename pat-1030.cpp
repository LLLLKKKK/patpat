#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <climits>
#include <deque>

#define N 500

int cost[N][N];
int dis[N][N];
int costsum[N] = {0};
int dissum[N];
int path[N];

using namespace std;

bool s (int a, int b)
{
	if (dissum[a] > dissum[b])
		return true;
	return false;
}

void ppath(int a)
{
	if (a != -1)
	{
		ppath(path[a]);
		printf("%d ", a);
	}
}

int main()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			dis[i][j] = -1;
			cost[i][j] = -1;
		}
	int citys, highs, start, end;
	scanf("%d%d%d%d", &citys, &highs, &start, &end);
	for (int i = 0; i < highs; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		dis[a][b] = dis[b][a] = c;
		cost[a][b] = cost[b][a] = d;
	}

	for (int i = 0; i < citys; i++)
		dissum[i] = INT_MAX;
	dissum[start] = 0;
	costsum[start] = 0;
	path[start] = -1;
	deque<int> q; 
	for (int i = 0; i < citys; i++)
		q.push_back(i);
	make_heap(q.begin(), q.begin() + citys - 1, s);

	while (q.size() != 0)
	{
		int a = q[0]; 
		q.pop_front();
		for (int i = 0; i < citys; i++)
			if (dis[a][i] != -1)
			{
				if (dissum[a] + dis[a][i] < dissum[i])
				{
					dissum[i] = dissum[a] + dis[a][i];
					costsum[i] = costsum[a] + cost[a][i];
					path[i] = a;
				}
				else if (dissum[a] + dis[a][i] ==  dissum[i] && costsum[a] + cost[a][i] < costsum[i])
				{
					costsum[i]  = costsum[a] + cost[a][i];
					path[i] = a;
				}
			}
		make_heap(q.begin(), q.end(), s);
	}
	ppath(end);
	printf("%d %d\n", dissum[end], costsum[end]);
	return 0;
}

