#include<cstdio>
#include<vector>
#include<climits>
#include<map>
#include<cmath>
using namespace std;
int main() {
	int a[2], b[2];
	long long a1, b1;
	scanf("%lld.%d.%d.", &a1, a, a+1);
	scanf("%lld.%d.%d.", &b1, b, b+1);
  int d = a[1] + b[1];
	a[0] += d / 29;
	a[1] = d % 29;
	d = a[0] + b[0];
	a1 += d / 17 + b1;
	a[0] = d % 17;
	printf("%lld.%d.%d\n", a1, a[0], a[1]);
  return 0;
}

