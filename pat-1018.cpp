#include<cstdio>
#include<vector>
#include<deque>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> road[501];
vector<int> pprev[501];
vector<int> nnext[501];
vector<vector<int> >paths;
deque<int> q;
int cost[501][501];
int dist[501];
int cond[501];
bool my(int a,int b)
{
	return dist[a]<dist[b];
}
vector<int>fp;
vector<int>path;
int take = INT_MAX;
int back = 0;
int take_now=0;
int carry=0;
int caps,stations,pstat,m;
void dfs(int s,int e)
{
	fp.push_back(s);
	int tmp_carry=carry,tmp_take=take_now;
	if(s!=0){
	if(cond[s]>=caps)
		carry+=cond[s]-caps;
	else if(carry>(caps-cond[s]))
		carry-=(caps-cond[s]);
	else
		{take_now+=(caps-cond[s])-carry;carry=0;}
	}
		
	if (s==e){
	if(take_now<take){
		take=take_now;
		back=carry;
		path=vector<int>(fp.begin(),fp.end());
	}else if(take_now==take&&carry<back)
	{
		back=carry;
		path=vector<int>(fp.begin(),fp.end());
	}
	}else{	
	for(int i=0;i<nnext[s].size();i++)
		dfs(nnext[s][i],e);
	}
	carry=tmp_carry;
	take_now=tmp_take;
	fp.pop_back();
}
int main()
{
	scanf("%d%d%d%d",&caps,&stations,&pstat,&m);
	stations++;
	caps/=2;
	for(int i=1;i<stations;i++)
		scanf("%d", cond+i);
	for(int i=0;i<m;i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		road[a].push_back(b);
		road[b].push_back(a);
		cost[a][b]=cost[b][a]=c;
	}
	for(int i=0;i<stations;i++)
	{q.push_back(i);dist[i]=INT_MAX;}
	dist[0]=0;
	while(q.size()!=0)
	{
		int now=q[0];q.pop_front();
		if(dist[now]==INT_MAX)break;
		for(int i=0;i<road[now].size();i++)
		{
			int in=road[now][i];
			int nd=dist[now]+cost[in][now];
			if(nd<dist[in])
			{
				dist[in]=nd;
				pprev[in].clear();
				pprev[in].push_back(now);
			}
			else if(nd==dist[in])
				pprev[in].push_back(now);
		}
		sort(q.begin(),q.end(),my);
	}
	for(int i=1;i<stations;i++)
		for(int j=0;j<pprev[i].size();j++)
			nnext[pprev[i][j]].push_back(i);
	dfs(0,pstat);
	printf("%d ", take);
	for(int i=0;i<path.size();i++)
		if(i==0)
			printf("%d", path[i]);
		else
			printf("->%d", path[i]);
	printf(" %d\n", back);
	return 0;
}
