#include <stdio.h>
#include <cmath>

long long ns[13];
long nss[13];
int digits[13];

int main()
{
	ns[0] = 0;
	for (int i = 1; i < 13; i++)
	{

		ns[i] = 10 * ns[i - 1] + (long long)pow(10, i - 1);
	}

	long n; scanf("%ld", &n);
	long nn = n;
	int count = 0;
	do
	{
		digits[count] = n % 10;
		n = n / 10;
		count++;
	}while(n > 0);

	nss[0] = 0;
	for (int i = 0; i < count; i++)
		nss[i + 1] = digits[i] * pow(10, i) + nss[i];

	long long sum = 0;
	for (int i = count - 1; i >= 0; i--)
	{
		if (digits[i] > 0)
			sum += digits[i] * ns[i];
		if (digits[i] == 1)
			sum += nss[i] + 1;
		else if (digits[i] > 1)
			sum += pow(10, i);
	}
	printf("%lld\n", sum);
	return 0;
}
