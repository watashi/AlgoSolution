#include <cstdio>

static long long c[12][12];
static long long dp[12];

struct RunBeforeMain
{
	RunBeforeMain()
	{
		c[0][0] = 1;
		for (int i = 1; i <= 11; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}
		dp[0] = 1;
		for (int i = 1; i <= 11; i++) {
			dp[i] = 1;
			for (int j = 1; j <= i; j++) {
				dp[i] += c[i][j] * dp[i - j];
			}
		}
		//puts("gao");
	}
} __run_me;

int main(void)
{
	int re, n;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ri++) {
		scanf("%d", &n);
		printf("%d %d %lld\n", ri, n, dp[n] - 1);
	}

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805979 	3498 	Push Button Lock 	Accepted 	C++ 	0.008 	2011-05-23 16:29:50
/*
id => 1174172
pid => 3498
pname => Push Button Lock
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:33:28
*/
