#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <climits>
#include <deque>
#include <cassert>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <memory>
using namespace std;

map<int, int> p;
vector<int> aa, bb;

int main()
{
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 0; i < n; i++)
	{ int c, d; char x; scanf("%d %c %d\n", &c, &x, &d);
	p.insert(pair<int, int>(c, d)); /*cp.insert(pair<int, char>(c, x));*/ }

	if (a == -1 || b == -1)
	{
		puts("-1"); return 0;
	}
	while (a != -1)
	{	
		aa.push_back(a);
//		aac.push_back(cp.find(a)->second);
		a = p.find(a)->second;
	}
	while(b != -1)
	{
		bb.push_back(b);
//		bbc.push_back(cp.find(b)->second);
		b = p.find(b)->second;
	}
	int i, j;
	for (i = aa.size() - 1, j = bb.size() - 1; i >= 0, j >= 0; i--, j--)
		if (aa[i] != bb[j])
			break;
	if (aa.size() - 1 == i) 
		puts("-1");
	else
	{

		i++; j++;
		//assert (aa[j] == bb[i]);
		printf("%05d\n", aa[i]);
	}
	return 0;
}
