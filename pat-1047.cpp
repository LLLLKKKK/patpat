
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cstring>

using namespace std;
char CC[40000][5];
vector<int> Cs[2500];
bool my(int a, int b)
{
	if (strcmp(CC[a], CC[b]) < 0)
		return true;
	return false;
}

int main()
{	
	int numS, numC;
	scanf("%d %d", &numS, &numC);
	for (int i = 0; i < numS; i++)
	{
		int nc; scanf("%s %d", CC + i, &nc);
		for (int j = 0; j < nc; j++)
		{
			int c; scanf("%d", &c);
			Cs[c - 1].push_back(i);
		}
	}
	for (int i = 0; i < numC; i++)
		sort(Cs[i].begin(), Cs[i].end(), my);
	
	for (int i = 0; i < numC; i++) {
		printf("%d %lu\n", i + 1, Cs[i].size());
		for (int j = 0; j < Cs[i].size(); j++)
			printf("%s\n", CC[Cs[i][j]]);
	}
	
	return 0;
}
