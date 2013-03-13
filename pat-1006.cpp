#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef struct
{
	char n[16];
	char i[9];
	char o[9];
}re;

bool a1(re a, re b)
{
	if (strcmp(a.i, b.i) < 0)
		return 1;
	return 0;
}
bool a2(re a, re b)
{
	if (strcmp(a.o, b.o) < 0)
		return 1;
	return 0;
}
int main()
{
	vector<re> w;
	int n; cin >> n;
	for (int i = 0; i < n;i++)
	{
		re a;
		cin >> a.n >> a.i >> a.o;
		w.push_back(a);
	}
	sort(w.begin(), w.end(), a1);
	cout << w[0].n << ' ';
	sort(w.begin(), w.end(), a2);
	cout << w[w.size() - 1].n << endl;
	return 0;
}

