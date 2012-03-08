#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200;
const int INF = 1000000007;

char buf[MAXN][MAXN];
int cnt[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
	int r, c, t, ans;

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", buf[i]);
	}

	t = 0;
	for (int i = 0; i < r; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < c; ++j) {
				if (buf[i][j] == 'W') {
					++t;
				}
				cnt[i][j] = t;
				dp[i][j] = INF;
			}
		} else {
			for (int j = c - 1; j >= 0; --j) {
				if (buf[i][j] == 'W') {
					++t;
				}
				cnt[i][j] = t;
				dp[i][j] = INF;
			}
		}
	}
//	printf("t = %d\n", t);

	ans = INF;
	dp[0][0] = 0;
	for (int i = 0; i < r; ++i) {
		if (i > 0) {
			for (int j = 0; j < c; ++j) {
				if (cnt[i][j] == cnt[i - 1][j] + (buf[i][j] == 'W' ? 1 : 0)) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
				}
			}
		}
		if (i % 2 == 0) {
			for (int j = 1; j < c; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
		} else {
			for (int j = c - 2; j >= 0; --j) {
				dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
			}
		}
		for (int j = 0; j < c; ++j) {
		//	printf("[%d][%d] = %d | %d\n", i, j, dp[i][j], cnt[i][j]);
			if (cnt[i][j] == t) {
				ans = min(ans, dp[i][j]);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

