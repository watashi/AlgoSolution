#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000007;

int x[MAXN];
int y[MAXN];
int z[MAXN];

int main() {
	int n, m, ans;

	scanf("%d%d%*d%*d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
	}
	y[0] = -INF;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &y[i]);
	}
	y[m + 1] = INF;
	m += 2;
	fill(z, z + m, INF);

	ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = lower_bound(y, y + m, x[i]) - y;
		int d = min(x[i] - y[j - 1], y[j] - x[i]);
		if (y[j] - x[i] > d || (x[i] - y[j - 1] == d &&
				(z[j - 1] == INF || z[j - 1] == d))) {
			--j;
		}
		if (z[j] == INF || z[j] == d) {
			++ans;
		}
		z[j] = min(z[j], d);
	}
	printf("%d\n", n - ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//444011 	May 9, 2011 11:23:16 PM 	watashi 	76B - Mice 	GNU C++ 	Accepted 	90 ms 	2500 KB 
