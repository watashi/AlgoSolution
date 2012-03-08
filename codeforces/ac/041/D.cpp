#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int MAXM = 12;
const int INF = 1000000000;

int a[MAXN][MAXN], dp[MAXN][MAXN][MAXM], pre[MAXN][MAXN][MAXM];

void print(int i, int j, int k, int r) {
	if (i == 0) {
		printf("%d\n", j + 1);
	} else if (pre[i][j][k] == 1) {
		print(i - 1, j + 1, (dp[i][j][k] - a[i - 1][j + 1]) % r, r);
		putchar('L');
	} else {
		print(i - 1, j - 1, (dp[i][j][k] - a[i - 1][j - 1]) % r, r);
		putchar('R');
	}
}

int main() {
	int n, m, r, p;

	scanf("%d%d%d", &n, &m, &r);
	++r;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	fill(dp[0][0], dp[n + 1][0], -INF);
	for (int j = 0; j < m; ++j) {
		dp[0][j][0] = 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < r; ++k) {
				if (dp[i][j][k] == -INF) {
					continue;
				}
				int vv = dp[i][j][k] + a[i][j];
				int kk = vv % r;
				if (j > 0 && vv > dp[i + 1][j - 1][kk]) {
					dp[i + 1][j - 1][kk] = vv;
					pre[i + 1][j - 1][kk] = 1;
				}
				if (j < m - 1 && vv > dp[i + 1][j + 1][kk]) {
					dp[i + 1][j + 1][kk] = vv;
					pre[i + 1][j + 1][kk] = -1;
				}
			}
		}
	}

	p = 0;
	for (int j = 0; j < m; ++j) {
		if (dp[n][j][0] > dp[n][p][0]) {
			p = j;
		}
	}
	if (dp[n][p][0] >= 0) {
		printf("%d\n", dp[n][p][0]);
		print(n - 1, p + pre[n][p][0], (dp[n][p][0] - a[n - 1][p + pre[n][p][0]]) % r, r);
		puts("");
	} else {
		puts("-1");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//213435 	Dec 11, 2010 8:09:43 PM 	watashi 	D - Pawn 	GNU C++ 	Accepted 	30 ms 	2900 KB 

