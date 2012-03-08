#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int dp[1 << 24];
int pre[1 << 24];

int sqr(int x) {
	return x * x;
}

int main() {
	int n, m, x0, y0, x[32], y[32], d[32][32];

	scanf("%d%d%d", &x0, &y0, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	x[n] = x0;
	y[n] = y0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
		}
	}

	fill(dp, dp + (1 << n), INF);
	dp[0] = 0;
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				continue;
			}
			if (dp[i ^ (1 << j)] > dp[i] + d[n][j] + d[j][n]) {
				dp[i ^ (1 << j)] = dp[i] + d[n][j] + d[j][n];
				pre[i ^ (1 << j)] = i;
			}
			for (int k = j + 1; k < n; ++k) {
				if (i & (1 << k)) {
					continue;
				}
				if (dp[i ^ (1 << j) ^ (1 << k)] > dp[i] + d[n][j] + d[j][k] + d[k][n]) {
					dp[i ^ (1 << j) ^ (1 << k)] = dp[i] + d[n][j] + d[j][k] + d[k][n];
					pre[i ^ (1 << j) ^ (1 << k)] = i;
				}
			}
			break;	// else TLE
		}
	}

	m = (1 << n) - 1;
	printf("%d\n0", dp[m]);
	while (m != 0) {
		for (int i = 0; i < n; ++i) {
			if ((m ^ pre[m]) & (1 << i)) {
				printf(" %d", i + 1);
			}
		}
		m = pre[m];
		printf(" 0");
	}
	puts("");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//272541 	Feb 1, 2011 2:52:57 PM 	watashi 	8C - Looking for Order 	GNU C++ 	Accepted 	2380 ms 	132600 KB 
