#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
vector<int> course[500001];
const long mm = 26*26*26*10+1;
long s[mm] = {0};
int main()
{
	int numS, numC; long ns = 0;
	scanf("%d%d", &numS, &numC);
	char stu[5];
	for (int i = 0; i < numC; i++)
	{
		int c, n; scanf("%d%d", &c, &n);
		for (int j = 0; j < n; j++) {
			scanf("%s", stu);
			long in = (stu[0]-'A')*26*26*10+(stu[1]-'A')*26*10
			+(stu[2]-'A')*10+stu[3]-'0';
			if(s[in] ==0){
				ns++;
				s[in] = ns;
			}
			course[s[in]-1].push_back(c);
		}
	}
	for (int i=0;i<numS;i++)
	{
		scanf("%s", stu);
		long in = (stu[0]-'A')*26*26*10+(stu[1]-'A')*26*10
			+(stu[2]-'A')*10+stu[3]-'0';
		if (s[in] == 0)
			printf("%s 0\n", stu);
		else {
			int c = s[in]-1;
			sort(course[c].begin(), course[c].end());
			printf("%s %lu", stu, course[c].size());
			for (int j=0;j<course[c].size();j++)
				printf(" %d", course[c][j]);
			printf("\n");			
		}
	}
	
	return 0;
}
