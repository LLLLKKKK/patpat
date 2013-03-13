#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> num;
	for (int i = 0; i < n; i++){
		int a; cin >> a; num.push_back(a);
	}
	int sum = 0;
	int max = 0;
	int left = 0, right = 0;
	int ml = 0, mr = 0;

	bool f = false;
	for (int i = 0; i < n;i++)
		if (num[i] > 0)
			{f = true; break;}

	if (f == false)
	{
		for (int i = 0; i < n;i++)
			if (num[i] == 0) {cout << 0 << ' ' << 0 <<' ' << 0 << endl; return 0;}

		cout << 0 << ' ' << num[0] <<' ' << num[n-1] << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		sum += num[i];
		if (sum < 0)
		{
			sum = 0;
			left = i + 1;
		}
		else if (sum > max)
		{
			ml = left;
			mr = i;
			max = sum;
		}
	}
	cout << max << ' ' << num[ml] << ' ' << num[mr] << endl;
	return 0;
}

