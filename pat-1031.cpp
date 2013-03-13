#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s.length() + 2;
	int n1, n2, n3;
	int c = n % 3;

	if (c == 0)
		n1 = n2 = n3 = n / 3;
	else if (c == 1)
	{
		n1 = n3 = ( n - 1 ) / 3;
		n2 = (n + 2) / 3;
	}
	else if (c == 2)
	{
		n1 = n3 = (n - 2) / 3;
		n2 = (n + 4) / 3;
	}

	for (int i = 0; i < n1 - 1; i++)
	{
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++) cout << ' ';
		cout << s[s.length() - 1 - i];
		cout << endl;
	}
	for (int i = n1 - 1; i < n1 + n2 - 1; i++)
		cout << s[i];
	cout << endl;
	cin >> s;

	return 0;
}

