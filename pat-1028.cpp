#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <cctype>

using namespace std;
typedef struct 
{
	char no[7];
	char name[9];
	int score;
}person;
vector<person> people;

bool sortid(person a, person b)
{
	if (strcmp(a.no, b.no) < 0)
		return true;
	return false;
}

bool sortname(person a, person b)
{
	int s = strcmp(a.name, b.name);
	if (s < 0)
	{
		return true;
	}
	else if (s == 0)
	{
		if (strcmp(a.no, b.no) < 0)
		{
			return true;
		}
	}
	return false;
}

bool sortgrade(person a, person b)
{
	if (a.score < b.score)
	{
		return true;
	}
	else if (b.score == a.score)
	{
		if (strcmp(a.no, b.no) < 0)
		{
			return true;
		}
	}
	return false;
}

int n, c;
int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 0;i < n ;i++ )
	{
		person p;
		scanf("%s%s%d", &p.no, &p.name, &p.score);
		people.push_back(p);
	}
	switch(c)
	{
		case 1:
			sort(people.begin(), people.end(), sortid);
			break;
		case 2:
			sort(people.begin(), people.end(), sortname);
			break;
		case 3:
			sort(people.begin(), people.end(), sortgrade);
			break;
	}
	for (int i = 0;i < n ;i++ )
		printf("%s %s %d\n", people[i].no, people[i].name, people[i].score);
}
