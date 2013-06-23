#include<cstdio>
#include<vector>
#include<climits>
#include<map>
#include<cmath>
using namespace std;

int main() {	
	vector<long> pps;
	pps.reserve(5000);
	pps.push_back(2);
	pps.push_back(3);
	long num; scanf("%ld", &num);
	long p=num;
	long li = (long)sqrt(num) + 2;
	long i = 5;
	while (true) {
		bool isp = true;
		for (auto j = 1;j < pps.size(); j++) {
			if (i % pps[j] == 0) {
				isp = false;
				break;
			}
		}
		if (isp) {
			pps.push_back(i);
		}
		if (i > li) break;
		i += 2;
	}
	
	if (num == 1) {
		puts("1=1");
	} else {
		map<long, long> ppp;
		long end = 0;
		long sq = sqrt(num);
		for (end = 0; end < pps.size(); end++)
			if (pps[end] > sq) break;

		while (num != 1) {
			i = 0;
			for (i = 0; i <= end; i++)
				if (num % pps[i] == 0)
					break;
			long pnow;
			if (i <= end) {
				pnow = pps[i];
			} else {
				pnow = num;
			}
			num = num / pnow;
			
			sq = sqrt(num);
			for (end = 0; end < pps.size(); end++)
				if (pps[end] > sq) break;
			
			auto it = ppp.find(pps[i]);
			if (it == ppp.end()) {
				ppp[pnow] = 1;
			} else {
				ppp[pnow]++;
			}
		}
		printf("%ld=", p);
		for (auto it = ppp.begin(); it != ppp.end(); it++) {
			if (it != ppp.begin()) {
				printf("*");
			}
			if (it->second != 1) {
				printf("%ld^%ld", it->first, it->second);
			} else {
				printf("%ld", it->first);
			}
		}
    puts("");
	}
	return 0;
}
