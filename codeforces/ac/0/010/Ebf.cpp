#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

int a[MAXN];
int dp[MAXN];

int main() {
	int n, m;

	while (true) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		reverse(a, a + n);
		dp[0] = 0;
		for (int i = 1; i < m; ++i) {
			dp[i] = MAXN;
			for (int j = 0; j < n; ++j) {
				if (a[j] <= i) {
					dp[i] = min(dp[i], dp[i - a[j]] + 1);
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			int c = 0, r = i;
			for (int j = 0; j < n; ++j) {
				c += r / a[j];
				r %= a[j];
			}
			if (dp[i] < c) {
				printf("%d: %d %d\n", i, dp[i], c);
			}
		}
	}

	return 0;
}

