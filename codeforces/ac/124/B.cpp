#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, ans;
	int a[10][10], b[10], p[10];

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < m; ++i) {
		p[i] = i;
	}
	ans = 1000000007;
	do {
		for (int i = 0; i < n; ++i) {
			b[i] = 0;
			for (int j = 0; j < m; ++j) {
				b[i] *= 10;
				b[i] += a[i][p[j]];
			}
		}
		ans = min(ans, *max_element(b, b + n) - *min_element(b, b + n));
	} while (next_permutation(p, p + m));
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//863507 	Nov 14, 2011 7:13:58 PM 	watashi 	124B - Permutations 	GNU C++0x 	Accepted 	30 ms 	1300 KB 
