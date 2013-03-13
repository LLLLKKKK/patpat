#include <stdio.h>
#include <vector>

using namespace std;
int color[10000] = {0};
int length[10000] = {0};
vector<int> s;
int M[200] = {0};
int main()
{
int order = 1;
	int N; scanf("%d", &N);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++)
		{int c; scanf("%d", &c); M[c-1] = order++;}
	int n; scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		{int c; scanf("%d", &c); if(M[c-1] != 0) s.push_back(c);}

	for (int i = 0; i < s.size(); i++) {
		color[i] = M[s[i]-1]; length[i] = 1;

		for (int j = 0; j < i; j++)
			if (color[j] <= color[i]
				&& length[j] + 1 > length[i])
			{
				length[i] = length[j] + 1;
			}
	}
	//for (int i = 0; i < s.size(); i++)
		//printf("%d %d\n", color[i], length[i]);
	printf("%d\n", length[s.size() - 1]);
	return 0;
}
