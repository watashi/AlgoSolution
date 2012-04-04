#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 16;

int from[MAXN], to[MAXN], p[MAXN], q[MAXN];
bool w[MAXN][MAXN];
long long dp[1 << MAXN];

int main() {
	int n, m, a, b;
	long long y;

	cin >> n >> y >> m;
	fill(from, from + n, 0);
	fill(to, to + n, 0);
	fill(w[0], w[m], false);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a;
		--b;
		w[a][b] = true;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] |= w[i][k] && w[k][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (w[i][j]) {
				from[j] |= 1 << i;
				to[i] |= 1 << j;
			}
		}
	}

	fill(dp, dp + (1 << n), 0);
	dp[0] = 1;
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0 && (i & from[j]) == 0) {
				dp[i] += dp[i ^ (1 << j)];
			}
		//	if (i == 1) {
		//		printf("??? %d\n", i & from[j]);
		//	}
		}
	//	if (dp[i] > 0) {
	//		printf("[%d] = %lld\n", i, dp[i]);
	//	}
	}

	y -= 2001;
	m = (1 << n) - 1;
	if (y >= dp[m]) {
		cout << "The times have changed" << endl;
		return 0;
	}

	fill(p, p + n, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (p[j] != -1) {
				continue;
			}
			p[j] = i;
{
	fill(dp, dp + (1 << n), 0);
	dp[0] = 1;
	for (int i = 1; i < (1 << n); ++i) {
		int k = n - __builtin_popcount(i);
		if (p[k] != -1) {
			int j = p[k];
			if ((i & (1 << j)) != 0 && (i & from[j]) == 0) {
				dp[i] += dp[i ^ (1 << j)];
			}
		} else {
			for (int j = 0; j < n; ++j) {
				if ((i & (1 << j)) != 0 && (i & from[j]) == 0) {
					dp[i] += dp[i ^ (1 << j)];
				}
			}
		}
	}
}
		//	printf("%d %d %lld\n", i, j, dp[m]);
			if (y < dp[m]) {
				q[i] = j;
				break;
			} else {
				p[j] = -1;
				y -= dp[m];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d%c", q[i] + 1, i == n - 1 ? '\n' : ' ');
	}

	return 0;
}

