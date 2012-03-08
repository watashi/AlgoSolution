#include <cstdio>
#include <algorithm>

using namespace std;
	
int a[64][64];

int main() {
	int n, m, r, c, ans;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);		
			a[i][j] += a[i][j - 1];
		}
		for (int j = 1; j <= m; ++j) {
			a[i][j] += a[i - 1][j];
		}
	}

	scanf("%d%d", &r, &c);
	ans = r * c;
	for (int i = r; i <= n; ++i) {
		for (int j = c; j <= m; ++j) {
			ans = min(ans, a[i][j] - a[i - r][j] - a[i][j - c] + a[i - r][j - c]);
		}
	}
	swap(r, c);
	for (int i = r; i <= n; ++i) {
		for (int j = c; j <= m; ++j) {
			ans = min(ans, a[i][j] - a[i - r][j] - a[i][j - c] + a[i - r][j - c]);
		}
	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218379 	Dec 12, 2010 3:45:49 PM 	watashi 	B - Land Lot 	GNU C++ 	Accepted 	30 ms 	1308 KB
