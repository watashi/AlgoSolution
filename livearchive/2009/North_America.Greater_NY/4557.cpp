#include <cstdio>

const int MAXN = 128;

long long dp[MAXN][MAXN][2];

void init() {
	dp[1][0][0] = dp[1][0][1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + (j > 0 ? dp[i - 1][j - 1][1] : 0LL);
		}
	}
}

int main() {
	int re;
	int m, n, k;

	init();
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d", &m, &n, &k);
		printf("%d %lld\n", m, k < MAXN ? (dp[n][k][0] + dp[n][k][1]) : 0LL);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714984  	2011-01-04 06:16:15 	Accepted	0.004	Minimum	26909	C++	4557 - Adjacent Bit Counts
/*
id => 1174220
pid => 4557
pname => Adjacent Bit Counts
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:40:34
*/
