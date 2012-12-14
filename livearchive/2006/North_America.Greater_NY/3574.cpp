#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int re, n, d, ans;
	static int v[32], dp[1024];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ri++) {
		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		sort(v, v + n);
		ans = v[0] <= d ? 1 : 0;
		for (int i = 0; i < n && d > 0; i++) {
			fill(dp + 1, dp + d + 1, 0);
			dp[0] = 1;
			for (int j = i + 1; j < n; j++) {
				for (int k = d; k >= v[j]; k--) {
					dp[k] += dp[k - v[j]];
				}
			}
			for (int j = 0; j < v[i] && j < d; j++) {
				ans += dp[d - j];
			}
			d -= v[i];
		}
		printf("%d %d\n", ri, ans);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805981 	3574 	Margaritas on the River Walk 	Accepted 	C++ 	0.012 	2011-05-23 16:33:32
/*
id => 1174171
pid => 3574
pname => Margaritas on the River Walk
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:33:16
*/
