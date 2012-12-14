#include <cstdio>

int main() {
	int ri = 0, n;
	long long dp[100];

	dp[0] = dp[1] = dp[2] = 1;
	for (int i = 3; i < 100; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (scanf("%d", &n) != EOF && n > 0) {
		printf("Case %d: %lld\n", ++ri, dp[n - 1]);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//868540 	5001 	Making Quadrilaterals 	Accepted 	C++ 	0.016 	2011-08-28 06:30:16
/*
id => 1174109
pid => 5001
pname => Making Quadrilaterals
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:23:27
*/
