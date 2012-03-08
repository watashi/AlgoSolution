#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 100000000;
const int MAXN = 128;
const int MAXK = 12;

int dp[MAXN][MAXN][MAXK][MAXK];

inline void add(int& lhs, int rhs) {
	lhs += rhs;
	if (lhs >= MOD) {
		lhs -= MOD;
	}
}

int main() {
	int n1, n2, k1, k2;
	int ans = 0;

	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	dp[0][0][0][0] = 1;
	for (int i1 = 0; i1 <= n1; ++i1) {
		for (int i2 = 0; i2 <= n2; ++i2) {
			for (int j1 = 0; j1 <= k1; ++j1) {
				for (int j2 = 0; j2 <= k2; ++j2) {
					if (dp[i1][i2][j1][j2] == 0) {
						continue;
					}
					if (i1 + 1 <= n1 && j1 + 1 <= k1) {
						add(dp[i1 + 1][i2][j1 + 1][0], dp[i1][i2][j1][j2]);
					}
					if (i2 + 1 <= n2 && j2 + 1 <= k2) {
						add(dp[i1][i2 + 1][0][j2 + 1], dp[i1][i2][j1][j2]);
					}
					if (i1 == n1 && i2 == n2) {
						add(ans, dp[i1][i2][j1][j2]);
					}
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

