#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int m,n,k;
	scanf("%d %d %d", &m, &n,&k);
	vector<int>ss;
	int num[1000];
	for (int i=0;i<k;i++)
	{	bool fail=false;
		int nnn=n;
		if (m<1) fail=true;
		for(int j=0;j<n;j++)
			scanf("%d", num+j);
		for(int j=n-1;j>=0;j--)
			if(ss.empty()){
				ss.push_back(num[j]);
			}
			else if(ss.size()<=m){
				while (num[j]<ss[ss.size()-1]) {
					if(ss[ss.size()-1]!=nnn) {
						fail=true;break;}
					nnn--;
					ss.pop_back();
				}
				if(ss.size()<m)ss.push_back(num[j]);
				else {
						fail=true;
						break;
					}
			}else{
				fail=true;
				break;
			}
		if(ss.size()>1)for(int i=0;i<ss.size()-1;i++)if(ss[i]-ss[i+1]!=-1){fail=true;break;}
		if(!fail)puts("YES");
		else puts("NO");
		ss.clear();
	}
	return 0;
}
