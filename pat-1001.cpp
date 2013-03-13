#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	a += b;
	if (a < 0) {cout << '-'; a = -a;}
	vector<int> c;
	if (a == 0) {cout << a << endl; return 0;}
	while (a != 0)
	{
		c.push_back(a%1000);
		a /= 1000;
	}

	for (int i = c.size() - 1;i >= 0; i--)
	{
		if (i == c.size() - 1)
			cout << c[i];
		else
		{
			if (c[i] < 10)
				cout << "00" << c[i];
			else if (c[i] < 100)
				cout << '0' << c[i];
			else if (c[i] == 0)
				cout <<  "000";
			else
				cout << c[i];
		}
		if (i != 0)
			cout << ',';
	}
	cout << endl;
	return 0;
}
