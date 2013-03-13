#include <iostream>
using namespace std;

int tree[101][101] = {0};
int ml = 0;

void t(int n, int l)
{
	if (l > ml) ml = l;
	if (tree[n][0] == 0)
		tree[0][l]++;
	else
		for (int i = 1; i < 101; i++)
		{
			if (tree[n][i] == 1)
				t(i, l + 1);
		}
}
int main()
{
	int n, m;
	cin >>n>>m;
	for (int i = 0; i < m; i++)
	{
		int c;
		int p, cn;
		cin >> p >> cn;
		for (int j = 0; j < cn; j++)
		{
			cin >> c;
			tree[p][c] = 1;
			tree[p][0]++;
		}
	}
	t(1, 0);
	for (int i = 0; i <= ml; i ++)
	{
		cout << tree[0][i];
		if (i != ml)
			cout << " ";
	}
	cout << endl;
	return 0;
}

