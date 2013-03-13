#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

typedef struct 
{
	int teams;
	bool known;
	long dist;
	int difp;
	int collect;
}city;

int map[500][500] = {0};
city cs[500];

class mc
{
	bool reverse;
public:
	mc(const bool& revparam = false)
	{reverse = revparam;}
	bool operator()(const int& lhs, const int& rhs)const
	{
		if (reverse) 
			return (cs[lhs].dist < cs[rhs].dist);
		else
			return (cs[lhs].dist > cs[rhs].dist);
	}
};

vector<int> pq;

int main()
{
	int citys, roads, start, end;
	cin >> citys >> roads >> start >> end;
	for (int i = 0; i < citys; i++)
	{
		cin >> cs[i].teams;
		cs[i].known = false;
		cs[i].dist = INT_MAX;
		cs[i].difp = 0;
		cs[i].collect = 0;
		pq.push_back(i);
	}
	cs[start].dist = 0;
	cs[start].difp = 1;
	cs[start].collect = cs[start].teams;

	make_heap(pq.begin(), pq.end(), mc());

	for (int i = 0; i < roads; i++)
	{
		int a, b, v; 
		cin >> a; cin >> b; cin >> v;
		map[a][b] = map[b][a] = v;
	}

	int count = 0;
	while (count < pq.size())
	{
		int tmp = INT_MAX;
		int smallest;
		bool f = false;
		
		smallest = pq[count];
		count++;
			
		cs[smallest].known = true;

		for (int i = 0; i < citys; i++)
		{
			if (cs[i].known == false && map[smallest][i] != 0)
			{
				if (cs[smallest].dist + map[smallest][i] < cs[i].dist)
				{
					cs[i].dist = cs[smallest].dist + map[smallest][i];
					cs[i].difp = cs[smallest].difp;
					cs[i].collect = cs[i].teams + cs[smallest].collect;
				}
				else if (cs[smallest].dist + map[smallest][i] == cs[i].dist)
				{
					cs[i].difp += cs[smallest].difp;
					cs[i].collect = max(cs[i].collect, cs[smallest].collect +  cs[i].teams);
				}
			}
		}
		make_heap(pq.begin() + count, pq.end(), mc());
	}

	cout <<cs[end].difp << ' '<< cs[end].collect << endl;
	return 0;
}

