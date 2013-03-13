#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char num[101];
char p[100];
int pos = 0;

char *c[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
	scanf("%s", num);
	int n = 0;
	int l = strlen(num);
	for (int i = 0; i < l;i++)
	{
		n += num[i] - '0';
	}
	while (n != 0)
	{
		p[pos] = n % 10;
		n /= 10;
		pos++;
	}
	for (int i = pos - 1; i > 0; i--)
		printf("%s ", c[p[i]]);
	puts(c[p[0]]);

	return 0;
}
