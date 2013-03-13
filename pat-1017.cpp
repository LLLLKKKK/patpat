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

using namespace std;
struct c
{
	int s;
	int e;
};
const int start = 8 * 3600;
const int ende = 17 * 3600 + 1;

c cs[10000];
c* css[10000];
vector<c*> line;

bool s (c* c1, c* c2)
{
	if (c1->e > c2->e)
		return true;
	return false;
}
bool e (c* c1, c* c2)
{
	if (c1->s < c2->s)
		return true;
	return false;
}
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	int count = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		int h, m, s, cost;
		scanf("%d:%d:%d %d", &h, &m, &s, &cost);
		cs[i].s = h * 3600 + m * 60 + s;
		cs[i].e = cs[i].s + cost * 60;
		css[i] = &cs[i];
	}
	sort(css, css + n, e);
	for (int i = 0; i < n; i++)
	{
		if (css[i]->s >= ende)
			break;
		else
		{
			if (line.size() < k)
			{
				if (css[i]->s < start) 
				{
					int cost = css[i]->e - css[i]->s; 
					sum += start - css[i]->s; 
					css[i]->s = start; 
					css[i]->e = start + cost;
				}
				line.push_back(css[i]);
			}
			else if (line.size() == k)
			{
				pop_heap(line.begin(), line.end(), s);
				
				if (line[k - 1]->e > css[i]->s)
				{	
					int cost = css[i]->e - css[i]->s;
					sum += line[k - 1]->e - css[i]->s;
					css[i]->s = line[k - 1]->e;
					css[i]->e = css[i]->s + cost;
				}
				line[k - 1] = css[i];
			}
			push_heap(line.begin(), line.end(), s);
			count++;
		}		
	}
	
	printf("%.1lf\n", sum / 60 / count);

	return 0;
}
