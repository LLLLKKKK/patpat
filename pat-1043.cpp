#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ptree;
int t[1000];

bool j(int root, int length)
{
	if (length == 1) {
		ptree.push_back(t[root]);
		return true;
	}
	
	int left = 0;
	for (left = root + 1; left < length + root; left++)
		if (t[left] >= t[root]) break;
		
	for (int i = left + 1; i < length + root; i++)
		if (t[i] < t[root]) return false;
			
	bool r;
	
	if (left == root + 1 || left == root + length) {
		r = j(root + 1, length - 1);
	} else {
		r = j(root + 1, left - root - 1) &&
				j(left, length - (left - root));
	}

	ptree.push_back(t[root]);
	return r;
}
bool rj(int root, int length)
{
	if (length == 1) {
		ptree.push_back(t[root]);
		return true;
	}
	
	int left = 0;
	for (left = root + 1; left < length + root; left++)
		if (t[left] < t[root]) break;
	
	for (int i = left + 1; i < length + root; i++)
		if (t[i] >= t[root]) return false;
	bool r;
	
	if (left == root + 1 || left == root + length) {
		r = rj(root + 1, length - 1);
	} else {
		r = rj(root + 1, left - root - 1) &&
				rj(left, length - (left - root));
	}

	ptree.push_back(t[root]);
	return r;
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", t + i);
	bool r = j(0, n);
	if (!r) {ptree.clear(); r = rj(0, n);}
	if (r) {
		puts("YES");
		for (int i = 0; i < ptree.size(); i++)
			if (i != ptree.size() - 1)
				printf("%d ", ptree[i]);
			else
				printf("%d\n", ptree[i]);
	}else
		puts("NO");
		
	return 0;
}
