#include <cstdio>
#include <algorithm>
using namespace std;
int ll[100000];
int data[100000];
int all[100000];
bool my(int a, int b)
{
	return data[a]<data[b];
}
int main()
{
	int n, s; scanf("%d %d", &n, &s);
	for (int i=0;i<n;i++)
	{	int now, next, da;
		scanf("%d %d %d", &now, &da, &next);
		ll[now]=next;
		data[now]=da;
	}
	int ne = s;
	int cc=0;
	while(ne !=-1)
	{
		all[cc++]=ne;
		ne=ll[ne];
	}
	sort(all, all+cc, my);
	if (s!=-1){
	printf("%d %05d\n", cc, all[0]);
	for (int i=0;i<cc-1;i++)
		printf("%05d %d %05d\n", all[i],data[all[i]],all[i+1]);
	printf("%05d %d -1\n", all[cc-1],data[all[cc-1]]);
	}else
		printf("0 -1\n");
	return 0;
}
