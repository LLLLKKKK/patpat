#include <iostream>
#include <stdio.h>
#include <queue>
#define	INF	0x6fffffff
using namespace std;

struct Customer
{
	int pTime, sTime, fTime;//所需服务时间，开始服务时间，结束服务时间
};

struct Window
{
	int ftime;//窗口黄线以内最后一个客户的服务接受时间
	queue <int> q;//在窗口排队的客户，队列中是当天所有在该窗口接受服务的客户，不仅仅是黄线以内的客户
};

Customer cus[1005];
Window wins[25];
const int seventeen = 17 * 60;//17:00
const int eight = 8 * 60;

int main()
{
	int n, m, k, q, ii, jj, mTime, fro, pos, hour, min, que;

	scanf("%d %d %d %d", &n, &m, &k, &q);

	for(ii = 1; ii <= k; ii++)
	{
		scanf("%d", &cus[ii].pTime);
	}
	for(ii = 1, jj = 0; ii <= n * m && ii <= k; ii++)
	{
		cus[ii].fTime = wins[jj].ftime + cus[ii].pTime;
		cus[ii].sTime = wins[jj].ftime;
		wins[jj].ftime += cus[ii].pTime;
		wins[jj].q.push(ii);
		jj = (jj + 1) % n;
	}
	for(; ii <= k; ii++)
	{
		mTime = INF;
		for(jj = 0; jj < n; jj++)
		{
			fro = wins[jj].q.front();
			if(cus[fro].fTime < mTime)
			{
				mTime = cus[fro].fTime;
				pos = jj;
			}
		}
		cus[ii].fTime = wins[pos].ftime + cus[ii].pTime;
		cus[ii].sTime = wins[pos].ftime;
		wins[pos].ftime += cus[ii].pTime;
		wins[pos].q.push(ii);
		wins[pos].q.pop();
	}
	
	while(q--)
	{
		scanf("%d", &que);
		if(cus[que].sTime + eight >= seventeen)
			printf("Sorry\n");
		else
		{
			hour = (cus[que].fTime + eight) / 60;
			min = (cus[que].fTime + eight) % 60;

			hour >= 10 ? printf("%d:", hour) : printf("0%d:", hour);
			min >= 10 ? printf("%d\n", min) : printf("0%d\n", min);
		}
	}
	return 0;
}
