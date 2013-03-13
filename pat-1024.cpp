#include<string.h>
#include<cmath>
#include<cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string sum (string a, string b)
{
	string res;
	int r = 0, c = 0;
	for (int i = 0; i < a.length();i++)
	{
		r = a[i] - '0' + b[i] - '0' + c;
		c = r / 10;
		r = r % 10;
		res.push_back( r  +'0');
	}
	if (c) res.push_back('1');
	// cout << "res:" << res << endl;
	return res;
}
string rev(const string& nn)
{
	string n = nn;
	char t;
	for (int i = 0; i < n.length(); i++){
		n[i] = nn[nn.length()-1-i];
	}
	return n;
}

int p(string s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
			return 0;
	}
	return 1;
}
int main()
{
	string n;
	int k;
	cin >> n >> k;
	n = rev(n);
	// cout << n << endl;

	if (p(n))
	{
		cout << n << endl << 0 <<endl;
		return 0;
	}

	for (int i = 0 ; i < k; i++)
	{
		string nn = rev(n);
		// cout << "nn:" << nn << endl;
		n = sum(n, nn);
		// cout << "n:" << n << endl;
		if (p(n)){
			cout << rev(n) << endl << i + 1<< endl;
			return 0;
		}
		else if (i == k - 1)
		{
			cout << rev(n) << endl << i + 1 << endl;
		}
	}
	return 0;
}

