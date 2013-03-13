#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
int main()
{
	int n ; cin >> n;
	vector<string> s1, s2;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> b >> a; 
		int n = 0;
		for (int j = 0; j < a.size(); j++)
			if (a[j] == '1')
				a[j] = '@';
			else if (a[j] == 'l')
				a[j] = 'L';
			else if (a[j] == '0')
				a[j] = '%';
			else if (a[j] == 'O')
				a[j] = 'o';
			else 
				n++;
		if (n != a.size())
		{
			flag = true;
			s1.push_back(b); s2.push_back(a);
		}
	}
	if (flag == false)
	{
		if (n == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are "<< n << " accounts and no account is modified" << endl;
	}
	else
	{
		cout << s1.size() << endl;
		for (int i = 0; i < s1.size(); i++)
			cout << s1[i] << ' ' << s2[i] << endl;
	}

}

