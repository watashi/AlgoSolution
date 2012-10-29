#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

const int SIGMA = 26;
const int MAXN = 128;
const int INF = 1000000007;

static int c[SIGMA][SIGMA];
static int dp[MAXN][MAXN][SIGMA];

int main() {
	int n, m, ans;
	char x, y, s[1024];

	scanf("%s%d%d", s, &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c %c", &x, &y);
		scanf("%d", &c[x - 'a'][y - 'a']);
	}
	n = strlen(s);

	fill(dp[0][0], dp[n][0], -INF);
	for (int k = 0; k < SIGMA; ++k) {
		dp[0]['a' + k == s[0] ? 0 : 1][k] = 0;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int kk = 0; kk < SIGMA; ++kk) {
				int jj = j + ('a' + kk == s[i] ? 0 : 1);
				for (int k = 0; k < SIGMA; ++k) {
					dp[i][jj][kk] = max(dp[i][jj][kk], dp[i - 1][j][k] + c[k][kk]);
				}
			}
		}
	}

	ans = -INF;
	for (int j = 0; j <= m; ++j) {
		for (int k = 0; k < SIGMA; ++k) {
			ans = max(ans, dp[n - 1][j][k]);
		}
	}
	printf("%d\n", ans);

	return 0;
}

