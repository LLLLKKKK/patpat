#include <stdio.h>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;
int arrive[10000];
int p[10000];
int vip[10000]={0};
int serve[10000]={0};

int index[10000];
int viptable[100]={0};
int endtime[100];
int tindex[100];
int snum[100]={0};
int s = 8*60*60;
int e = 21*60*60;
bool my(int a,int b)
{
	return arrive[a]<arrive[b];
}
bool tt(int a,int b)
{
	if(endtime[a]<endtime[b])
		return false;
	else if(endtime[a]==endtime[b]&&a<b)
		return false;
	return true;
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0;i<n;i++)
	{
		int h,m,s; int pt;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &pt,vip+i);
		if(pt>120)pt=120;
		p[i]=pt;
		arrive[i]=h*60*60+m*60+s; 
		index[i]=i;
	}
	int tables, m;
	scanf("%d%d", &tables, &m);
	for (int i=0;i<m;i++)
		{int t;scanf("%d", &t);viptable[t-1]=1;}
	for(int i=0;i<tables;i++){endtime[i]=s;tindex[i]=i;}
	sort(index, index+n,my);
	int nowt=s;

	deque<int> qq;
	int pnow=0,qnow=0;
	sort(tindex,tindex+tables,tt);
	while(nowt<e)
	{
		while(qnow<n&&arrive[index[qnow]]<=nowt) qq.push_back(qnow++);
		if(qq.size()==0)
		{if(qnow<n&&arrive[index[qnow]]<e)
		{nowt=arrive[index[qnow]];qq.push_back(qnow++);}else break;}
		
		int i=0; bool vv=false; bool tv = false;
		int tablenow;
		
		for(i=0;i<qq.size();i++)
			if(vip[index[qq[i]]])
				{vv=true;break;}
	
		int j=tables-1;
		if(vv){
			while(j>=0&&endtime[tindex[j]]==endtime[tindex[tables-1]])
				{if(viptable[tindex[j]]){tv=true;break;}j--;}
		}
		if(tv){pnow=qq[i];qq.erase(qq.begin()+i);tablenow=tindex[j];}
		else{ pnow=qq[0];qq.erase(qq.begin()); tablenow=tindex[tables-1];}
		
		serve[index[pnow]]=nowt;
		snum[tablenow]++;
		endtime[tablenow]=nowt+p[index[pnow]]*60;
		int a=arrive[index[pnow]];
		int s=serve[index[pnow]];
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", a/60/60,a/60%60,a%60,s/60/60,s/60%60,s%60,(int)(floor((s-a)/60.0+0.5)));
		sort(tindex,tindex+tables,tt);
		nowt=max(endtime[tindex[tables-1]],nowt);
	}
	for(int i=0;i<tables;i++)
		if (i!=tables-1)
			printf("%d ", snum[i]);
		else
			printf("%d\n",snum[i]);
	return 0;
}
