#include<stdio.h>
#include<string.h>

char a[1001];
int main(int argc, char const *argv[])
{
	gets(a);
	int max = 0;
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i - j > 0, j + i < n; j++)
		{
			if (a[i - j] != a[i + j]) break;
			if (j * 2 + 1 > max) max = j * 2 + 1;
		}

		for (int j = 0; i - j > 0, j + i + 1 < n; j++){
			if (a[i - j] != a[i + j + 1]) break;
			if (j * 2 + 2 > max) max = j * 2 + 2;
		}
	}
	printf("%d\n", max);
	return 0;
}
