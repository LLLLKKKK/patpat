#include <stdio.h>
#include <climits>

int d[100000];

int main()
{
	long m;
	int n; scanf("%d %ld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", d + i);
	long sum = 0;
	long msum = LONG_MAX; bool f = false;
	int start = 0, end = -1;
	for (int i = 0; i < n || sum >= m;)
	{
		if (sum == m) {
			f = true;
			printf("%d-%d\n", start + 1, end + 1);
			sum -= d[start];
			start++;
		}else if(sum > m) {
			if (sum < msum) msum = sum;
			sum -= d[start];
			start++;
		}else{
			sum += d[i];
			end++;
			i++;
		}
	}
	m = msum;
	if (!f) {
		start = sum = 0; end = -1;
		for (int i = 0; i < n || sum >= m;)
		{
			if (sum == m) {
				printf("%d-%d\n", start + 1, end + 1);
				sum -= d[start];
				start++;
			}else if(sum > m) {
				sum -= d[start];
				start++;
			}else{
				sum += d[i];
				end++;
				i++;
			}
		}
	}
	return 0;
}
