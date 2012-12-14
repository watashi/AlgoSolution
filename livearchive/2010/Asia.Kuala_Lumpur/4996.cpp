#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const long long INF = 1000000007LL * 1000000007LL;

long long x, y, z;
long long dp[MAXN][2];

long long gao(int n, int f) {
	if (dp[n][f] != -INF) {
		return dp[n][f];
	} else if (n == 1) {
		return dp[n][f] = f == 0 ? 0 : -x / 2;
	} else {
		dp[n][f] = INF;
		for (int m = 1; m < n; ++m) {
			dp[n][f] = min(dp[n][f], max(gao(m, 0), gao(n - m, 1)));
		}
		dp[n][f] += f == 0 ? x + y : z;
		return dp[n][f];
	}
}

int main() {
	int re, n;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%lld%lld%lld", &n, &x, &y, &z);
		fill(dp[0], dp[n + 1], -INF);
		printf("Case %d: %lld\n", ri, gao(n, 0));
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//868538 	4996 	Scientefic Experiment 	Accepted 	C++ 	0.380 	2011-08-28 06:29:03
/*
id => 1174106
pid => 4996
pname => Scientific Experiment
status => Accepted
lang => C++
time => 0.192
date => 2012-12-14 17:22:58
*/
