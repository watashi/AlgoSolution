#include <cstdio>

const int MAXN = 108;
const int MAXM = MAXN * MAXN;
const long long MOD = 1000000007LL;

long long c[MAXM][MAXN], dp[MAXN][MAXM];

void init() {
	for (int i = 0; i < MAXM; ++i) {
		c[i][0] = 1;
		for (int j = 1; j < MAXN; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= MOD) {
				c[i][j] -= MOD;
			}
		}
	}
}

int main() {
	int n, m, x[MAXN], y[MAXN];
	long long ans;

	init();
	scanf("%d", &n);
	m = 0;
	ans = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		m += x[i];
		ans = ans * c[m][x[i]] % MOD;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &y[i]);
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = x[i]; j <= m; ++j) {
			if (dp[i][j - x[i]] == 0) {
				continue;
			}
			for (int k = 0; k <= j && k <= y[i]; ++k) {
				dp[i + 1][j - k] += dp[i][j - x[i]] * c[j][k];
				dp[i + 1][j - k] %= MOD;
			}
		}
	}

	ans = ans * dp[n][0] % MOD;	
//	printf("%lld\n", ans);
	printf("%I64d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235966 	Jan 2, 2011 4:32:07 PM 	watashi 	D - Lesson Timetable 	GNU C++ 	Accepted 	90 ms 	21012 KB

