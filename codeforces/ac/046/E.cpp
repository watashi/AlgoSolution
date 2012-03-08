#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	long long p, t, a[1600], dp[1600];

	scanf("%d%d", &n, &m);
	fill(dp + 1, dp + m + 1, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%I64d", &a[j]);
		}
		partial_sum(a + 1, a + 1 + m, a + 1);
		t = -0x123456789ABCDEFLL;
		if (i & 1) {
			for (int j = 1; j <= m; ++j) {
				p = t;
				t = max(t, dp[j]);
				dp[j] = p + a[j];
			}
		} else {
			for (int j = m; j >= 1; --j) {
				p = t;
				t = max(t, dp[j]);
				dp[j] = p + a[j];
			}
		}
	}
	printf("%I64d\n", *max_element(dp + 1, dp + m + 1));

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208614 	Dec 5, 2010 7:51:51 PM 	watashi 	E - Comb 	GNU C++ 	Accepted 	770 ms 	1316 KB 
