#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

long long dp[100][10];

int main() {
	int re, rid, n;

	dp[0][0] = 1;
	for (int i = 1; i <= 64; ++i) {
		for (int j = 0; j < 10; ++j) {
			dp[i][j] = accumulate(dp[i - 1], dp[i - 1] + j + 1, 0LL);
		}
	}
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &rid, &n);
		printf("%d %lld\n", rid, accumulate(dp[n], dp[n] + 10, 0LL));
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881217 	4877 	Non-Decreasing Digits 	Accepted 	C++ 	0.024 	2011-09-13 13:40:37
/*
id => 1174167
pid => 4877
pname => Non-Decreasing Digits
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:32:45
*/
