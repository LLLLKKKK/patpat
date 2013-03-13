#include<stdio.h>
#include<algorithm>
#include<cfloat>
using namespace std;
double price[501];
int dist[501];
int index[501];
bool my(int a,int b)
{
	return dist[a]<dist[b];
}
int main()
{
	int capacity, distance,ava,N;
	scanf("%d%d%d%d", &capacity, &distance,&ava,&N);
	for(int i=0;i<N;i++)
	{scanf("%lf%d",price+i,dist+i);index[i]=i;};
	sort(index,index+N,my);
	if(dist[index[0]]>0){
		puts("The maximum travel distance = 0.00");
		return 0;
	}
	index[N]=N;
	dist[index[N]]=distance;
	price[index[N]]=0;
	double sum=0; double gas=0;
	for(int i=0;i<N;)
	{
		if(dist[index[i+1]]-dist[index[i]]>capacity*ava)
		{printf("The maximum travel distance = %.2lf\n", dist[index[i]]+capacity*ava*1.0); return 0;}
			
		double pmin=price[index[i]];
		int stat=-1;
		for(int j=i+1;j<N+1&&dist[index[j]]-dist[index[i]]<=gas*ava;j++)
			if(price[index[j]]<=pmin)
			{
				pmin=price[index[j]]; stat=j;
			}
		if(stat!=-1)
		{
			gas-=(dist[index[stat]]-dist[index[i]])*1.0/ava;
			i=stat;
			continue;
		}

		stat=-1; pmin=price[index[i]];
		for(int j=i+1;j<N+1&&dist[index[j]]-dist[index[i]]<=capacity*ava;j++)
			if(price[index[j]]<=pmin)
			{
				pmin=price[index[j]]; stat=j;break;
			}
		if(stat!=-1){
			double need=(dist[index[stat]]-dist[index[i]])*1.0/ava;
			sum+=(need-gas)*price[index[i]];
			gas=0;
			i=stat;
		}else {
			sum+=(capacity-gas)*price[index[i]];
			gas=capacity;
			gas-=(dist[index[i+1]]-dist[index[i]])*1.0/ava;
			i++;
		}
	}
	printf("%.2lf\n", sum);
	return 0;
}
