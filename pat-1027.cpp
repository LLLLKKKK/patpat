#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <cctype>

using namespace std;

int r, g, b;
char d[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
void f(int a)
{
	putchar(d[a / 13]);
	putchar(d[a % 13]);
}
int main()
{
	scanf("%d%d%d", &r, &g, &b);
	putchar('#');
	f(r);
	f(g);
	f(b);
	putchar('\n');

	return 0;
}
