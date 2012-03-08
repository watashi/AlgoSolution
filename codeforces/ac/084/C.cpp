#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10086;

int r[MAXN], ans[MAXN];

long long sqr(long long x) {
	return x * x;
}

int main() {
	int n, m, x, y;
	map<int, int> mp;
	map<int, int>::iterator it;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &r[i]);
		mp[x] = i;
	}
	fill(ans, ans + n, -1);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		it = mp.lower_bound(x);
		if (it != mp.end()) {
			if (ans[it->second] == -1 && sqr(x - it->first) + sqr(y) <= sqr(r[it->second])) {
				ans[it->second] = i + 1;
			}
		}
		if (it != mp.begin()) {
			--it;
			if (ans[it->second] == -1 && sqr(x - it->first) + sqr(y) <= sqr(r[it->second])) {
				ans[it->second] = i + 1;
			}
		}
	}

	printf("%d\n", n - (int)count(ans, ans + n, -1));
	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//455131 	May 14, 2011 6:36:14 PM 	watashi 	84C - Biathlon 	GNU C++ 	Accepted 	160 ms 	1700 KB 
