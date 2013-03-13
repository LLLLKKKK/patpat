#include <stdio.h>

int money[1001];

int main()
{
	long n;
	int m;
	scanf("%ld %d", &n, &m);

	for (int i = 1; i <= m; i++)
		money[i] = 0;

	for (long i = 0; i < n; i++)
	{
		int c; 
		scanf("%d", &c);
		money[c]++;
	}
	int v1 = 0;

	for (int i = 1; i <= m; i++)
		if (money[i] > 0 && money[m - i] > 0)
		{
			if (i == m - i ){
				if (money[i] >= 2)
				{v1 = i; break;}
			}else{
				v1 = i; break;}
		}

	if (v1 != 0)
		printf("%d %d\n", v1, m - v1);
	else
		puts("No Solution");
	return 0;
}
