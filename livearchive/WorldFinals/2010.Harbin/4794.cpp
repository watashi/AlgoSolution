#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[16], s[1 << 16];
map<pair<pair<int, int>, int>, bool> dp;

bool gao(int x, int y, int z) {
	if (__builtin_popcount(z) == 1) {
		return true;
	} else if (x > y) {
		return gao(y, x, z);
	} else if (dp.count(make_pair(make_pair(x, y), z)) > 0) {
		return dp[make_pair(make_pair(x, y), z)];
	} else {
		bool &ret = dp[make_pair(make_pair(x, y), z)];
		for (int u = (z - 1) & z; u > 0; u = (u - 1) & z) {
			if (s[u] + s[u] > s[z]) {
				continue;
			}
			if (s[u] % x == 0 && gao(x, s[u] / x, u) && gao(x, y - s[u] / x, z ^ u)) {
				ret = true;
				break;
			}
			if (s[u] % y == 0 && gao(s[u] / y, y, u) && gao(x - s[u] / y, y, z ^ u)) {
				ret = true;
				break;
			}
		}
		return ret;
	}
}

int main() {
	int ri = 0, n, m, x, y;

	while (scanf("%d", &n) != EOF && n > 0) {
		scanf("%d%d", &x, &y);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		s[0] = 0;
		for (int i = 1; i < (1 << n); ++i) {
			int j = __builtin_ctz(i);
			s[i] = s[i ^ (1 << j)] + a[j];
		}
		dp.clear();
		m = (1 << n) - 1;
		printf("Case %d: %s\n", ++ri, s[m] == x * y && gao(x, y, m) ? "Yes" : "No");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806021 	4794 	Sharing Chocolate 	Accepted 	C++ 	1.036 	2011-05-23 17:41:15
/*
id => 1174054
pid => 4794
pname => Sharing Chocolate
status => Accepted
lang => C++
time => 0.705
date => 2012-12-14 17:15:57
*/
