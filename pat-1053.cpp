#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>map[100];
vector<int>path;
int cost[100];
void dfs(int start,int cc)
{
	if(map[start].size()>0){
		if (cc>0){
			path.push_back(start);
			for(int i=0;i<map[start].size();i++)
				dfs(map[start][i],cc-cost[start]);
			path.pop_back();
		}
	}else{
		//printf("%d %d \n",cc,start);
		if(cc-cost[start]==0){
			for(int i=0;i<path.size();i++)
				printf("%d ", cost[path[i]]);
			printf("%d\n", cost[start]);
		}
	}
}
bool my(int a,int b)
{
	return cost[a]>cost[b];
}
int main()
{
	int n, m, s;
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<n;i++)
		scanf("%d", cost+i);
	for(int i=0;i<m;i++)
	{
		int node, num; scanf("%d %d",&node,&num);
		for (int j=0;j<num;j++)
		{	int c;
			scanf("%d",&c); map[node].push_back(c);
		}
		sort(map[node].begin(), map[node].end(), my);
	}
	dfs(0,s);
	return 0;
}
