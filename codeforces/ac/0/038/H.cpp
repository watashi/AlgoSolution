#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 52;
const int INF = 1000000000;

vector<int> w[MAXN];
long long dp[MAXN][MAXN][MAXN];

int main() {
	int n, m, a, b, c;
	int g1, g2, s1, s2;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		w[i].resize(n, INF);
		w[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		w[a][b] = w[b][a] = c;
	}
	scanf("%d%d%d%d", &g1, &g2, &s1, &s2);

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		w[i][i] = INF;
		sort(w[i].begin(), w[i].end());
		w[i].erase(unique(w[i].begin(), w[i].end()), w[i].end());
		w[i].pop_back();
		for (vector<int>::iterator j = w[i].begin(); j != w[i].end(); ++j) {
			*j = (*j << 8) + i;
		}
	}

	long long ans = 0;
	for (int g = 0; g < n; ++g) {
		for (int s = 0; s < n; ++s) {
			if (g == s || w[g].front() >= w[s].back()) {
				continue;
			}
			memset(dp, 0, sizeof(dp));
			dp[0][0][0] = 1;
			for (int k = 0; k < n; ++k) {
				bool fg = false, fs = false, ff = false;
				if (k == g) {
					fg = true;
				} else if (k == s) {
					fs = true;
				} else {
					fg = w[k].front() <= w[g].front();
					fs = w[k].back() >= w[s].back();
					ff = upper_bound(w[k].begin(), w[k].end(), w[g].front()) < lower_bound(w[k].begin(), w[k].end(), w[s].back());
				}
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (fg) {
							dp[k + 1][i + 1][j] += dp[k][i][j];
						}
						if (fs) {
							dp[k + 1][i][j + 1] += dp[k][i][j];
						}
						if (ff) {
							dp[k + 1][i][j] += dp[k][i][j];
						}
					}
				}
			}
			for (int i = g1; i <= g2; ++i) {
				for (int j = s1; j <= s2; ++j) {
					ans += dp[n][i][n - i - j];
				}
			}
		}
	}
//	printf("%lld\n", ans);	// WA80
	printf("%I64d\n", ans);

	return 0;
}

// 1y, orz myself
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235946 	Jan 2, 2011 2:42:13 PM 	watashi 	H - The Great Marathon 	GNU C++ 	Accepted 	1560 ms 	2424 KB 
