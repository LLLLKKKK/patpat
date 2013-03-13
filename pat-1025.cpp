#include<string.h>
#include<cmath>
#include<cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef struct 
{
	string id;
	int s;
	int rn;
	int rf;
	int rl;
}man;

int my(man m1, man m2)
{
	if (m1.s > m2.s)
	{
		return 1 ;
	}
	return 0;
}

int ma(man m1, man m2)
{
	if (m1.s > m2.s)
	{
		return 1;
	}
	else if (m2.s == m1.s && m1.id < m2.id)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int loc; cin >> loc;
	vector<man> sum;
	for (int i = 0;i < loc ;i++ )
	{
		int N;
		cin >> N;
		vector<man> locn;

		for (int j = 0;j < N ;j++ )
		{
			man man1;
			cin >> man1.id >> man1.s;
			man1.rn = i + 1;
			locn.push_back(man1);
		}

		sort(locn.begin(), locn.end(), my);

		int n = 1; locn[0].rl = 1;
		for (int j=1;j < N ;j++ )
		{
			if (locn[j].s == locn[j-1].s)
			{
				locn[j].rl = locn[j-1].rl;
				n++;
			}
			else
				locn[j].rl = ++n;
		}
		sum.insert(sum.begin(), locn.begin(), locn.end());
	}

	sort(sum.begin(), sum.end(), ma);

		int n = 1; sum[0].rf = 1;
		for (int j=1;j < sum.size() ;j++ )
		{
			if (sum[j].s == sum[j-1].s)
			{
				sum[j].rf = sum[j-1].rf;
				n++;
			}
			else
				sum[j].rf = ++n;
		}

	cout << sum.size() << endl;
	for (int i = 0;i < sum.size() ;i++ )
	{
		cout << sum[i].id << ' '
		<<  sum[i].rf <<' '
		<< sum[i].rn << ' ' 
			<<sum[i].rl << endl;
	}
	return 0;
}

