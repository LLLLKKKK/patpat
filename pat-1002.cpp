#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
typedef struct 
{
	int a;
	double b;
}Po;

int main()
{
	vector<Po> a, b, c;
	int n; 
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		Po w; cin >> w.a >> w.b; a.push_back(w);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m;i++)
	{
		Po w; cin >> w.a >> w.b; b.push_back(w);
	}

	int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i].a == b[j].a)
		{
			a[i].b += b[j].b;
			if (a[i].b != 0)
				c.push_back(a[i]);
			i++; j++;
		}
		else if (a[i].a > b[j].a)
		{
			if (a[i].b != 0)
			c.push_back(a[i]);
			i++;	
		}
		else
		{
			if (b[j].b != 0)
			c.push_back(b[j]);
			j++;
		}
	}
	if (i < a.size())
	{
		for (int k = i; k < a.size();k++)
			if(a[k].b != 0)c.push_back(a[k]);
	}
	if (j < b.size())
	{
		for (int k = j; k < b.size();k++)
			if(b[k].b != 0)c.push_back(b[k]);
	}

	cout << c.size();
	for (int i = 0; i < c.size(); i++)
		printf(" %d %.1lf", c[i].a, c[i].b);
	cout << endl;
	return 0;
}

