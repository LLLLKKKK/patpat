#include <iostream>
#include <cmath>

using namespace std;

int isprime(int n)
{
	if (n == 1 || n == 0) return 0;
	if (n == 2) return 1;

	int a =  (int)sqrt((double)n) + 1;
	if (n % 2 == 0)
		return 0;
	else
	for (int i = 3; i < a;i+=2)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int convert(int n, int m)
{
	int s = 0;
	int nn, mm;

	do
	{
		nn = n / m;
		mm = n % m;
		s = s * m + mm;
		n = nn;
	}while (n != 0);

	return s;
}
int main()
{
	int n, m;

	while (cin>>n && n > 0){
		cin>>m;
		if (isprime(n) && isprime(convert(n,m)))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
