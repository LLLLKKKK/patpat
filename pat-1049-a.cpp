#include <stdio.h>

int main()
{
	long n;
	long total = 0;
	scanf("%ld", &n);
	long x = 1;
	while (n / x != 0)
	{
		long right = n % x;
		long left = n / (x * 10);
		int current = (n / x) % 10;
		if (current == 0)
			total += left * x;
		else if (current == 1)
			total += left * x + right + 1;
		else
			total += (left + 1) * x;
		x *= 10;

	}
	printf("%ld", total);
	return 0;
}
