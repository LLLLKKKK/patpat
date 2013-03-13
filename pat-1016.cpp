#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int rate[24];
char names[1000][21];
int ttime[1000];
int onoff[1000]={0};
int iindex[1000];
#define online "on-line"
#define offline "off-line"
bool my(int a,int b)
{
	int c=strcmp(names[a],names[b]);
	if(c<0)
		return true;
	else if(c==0&&ttime[a]<ttime[b])
		return true;
	return false;
}
long billm(long t)
{
	int h=t/60,m=t%60;
	long sum=0;
	for(int i=0;i<h;i++)
		sum+=rate[i%24]*60;
	sum+=rate[h%24]*m;
	return sum;
}
double bill(long s,long e)
{
	return (billm(e)-billm(s))/100.0;
}
int main()
{
	for(int i=0;i<24;i++)scanf("%d", rate+i);
	int n;scanf("%d", &n);
	int mon;
	for(int i=0;i<n;i++)
	{
		char of[9];
		int d,h,m;scanf("%s %d:%d:%d:%d %s",names[i],&mon,&d,&h,&m,of);
		if(strcmp(of,offline)==0)onoff[i]=1;
		ttime[i]=d*24*60+h*60+m;
		iindex[i]=i;
	}
	sort(iindex,iindex+n,my);
				
	char *namenow=NULL;
	for(int pnow=0;pnow<n;)
	{
		bool nameflag=false;
		double total=0;
		namenow=names[iindex[pnow]];
		while(pnow+1<n&&strcmp(namenow,names[iindex[pnow+1]])==0)
		{
			if(onoff[iindex[pnow]]==0)
			{
				if(onoff[iindex[pnow+1]]!=1){pnow++;continue;}
				if(!nameflag)
					printf("%s %02d\n",names[iindex[pnow]],mon);
				nameflag=true;
				double costnow=bill(ttime[iindex[pnow]],ttime[iindex[pnow+1]]);
				total+=costnow;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
				ttime[iindex[pnow]]/60/24,ttime[iindex[pnow]]/60%24,ttime[iindex[pnow]]%60,
				ttime[iindex[pnow+1]]/60/24,ttime[iindex[pnow+1]]/60%24,ttime[iindex[pnow+1]]%60, (ttime[iindex[pnow+1]]-ttime[iindex[pnow]]),costnow);
				pnow+=2;
			}else pnow++;
		}
		if(nameflag)printf("Total amount: $%.2lf\n", total);
		else pnow++;
	}
	return 0;
}
