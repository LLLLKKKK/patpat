#include <stdio.h>

int N[100000];

int main()
{
	int n; scanf("%d", &n);
	int total = 0;
	for (int i = 0; i < n; i++)
		{ scanf("%d", N + i); total += N[i]; N[i] = total;}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, xy; scanf("%d%d", &x, &y);
		if (x > y) {xy = x; x = y; y = xy;}
		int sum1, sum2;
		if (x==1)
		sum1 = N[y-2];
		else
		sum1 = N[y-2] - N[x-2];
			
		sum2 = total - sum1;
		if (sum1 > sum2)
			printf("%d\n", sum2);
		else
			printf("%d\n", sum1);
	}	
	return 0;
}
