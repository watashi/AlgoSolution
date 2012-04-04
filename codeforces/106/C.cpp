#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int main() {
	int n, m;
	int a[MAXN], b[MAXN], c[MAXN], d[MAXN], dp[MAXN];

	scanf("%d%d%d%d", &n, &m, &c[0], &d[0]);
	a[0] = n;
	b[0] = 1;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	}

	fill(dp, dp + n + 1, 0);
	for (int i = 0; i <= m; ++i) {
		a[i] /= b[i];
		for (int j = n; j >= 0; --j) {
			for (int k = 1, x = j + c[i], y = dp[j] + d[i]; k <= a[i] && x <= n; ++k, x += c[i], y += d[i]) {
				if (dp[x] < y) {
					dp[x] = y;
				} else {
					break;
				}
			}
		}
	}
	printf("%d\n", *max_element(dp, dp + n + 1));

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//627298 	Aug 23, 2011 6:13:42 PM 	watashi 	106C - Buns 	GNU C++0x 	Accepted 	30 ms 	1400 KB 
