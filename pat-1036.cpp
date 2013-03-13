#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
int main()
{
	int n; cin >> n;
	string m1, m3;
	char m2;
	int m4;

	string low_name, high_name, lows, highs;
	int low = 101, high = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> m1 >> m2 >> m3 >> m4;
		if (m2 == 'M')
		{
			if (m4 < low)
			{
				low = m4;
				low_name = m1;
				lows = m3;
			}
		}
		else
		{
			if (m4 > high)
			{
				high = m4;
				high_name = m1;
				highs = m3;
			}
		}

	}

	if (high == -1)
		cout << "Absent" << endl;
	else cout << high_name << ' ' << highs << endl;

	if (low == 101)
		cout << "Absent" << endl;
	else cout << low_name << ' ' << lows << endl;

	if (low == 101 || high == -1)
		cout << "NA" << endl;
	else
		cout << high - low << endl;
	

}

