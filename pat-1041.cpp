#include<stdio.h>
#include<string.h>

int bets[100000];
int r[10001] = {0};
int main(int argc, char const *argv[])
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", bets + i);
		r[bets[i]]++;
	}
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		if (r[bets[i]] == 1) {printf("%d\n", bets[i]); f=1; break;} 
	}
	if (f == 0) printf("None\n");
	return 0;
}
