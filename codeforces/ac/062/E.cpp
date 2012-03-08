#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 6;
const int MAXM = 100100;
const long long INF = 1234567890123456789LL;

int h[MAXM][MAXN], v[MAXM][MAXN];
long long pre[1 << MAXN], cur[1 << MAXN], sh[1 << MAXN], sv[1 << MAXN];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i = 1; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &h[i][j]);
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &v[i][j]);
		}
	}

	fill(cur, cur + (1 << n), INF);
	cur[0] = 0;
	for (int i = 1; i < m; ++i) {
		copy(cur, cur + (1 << n), pre);
		fill(cur, cur + (1 << n), INF);
		cur[0] = 0;
		
		sh[0] = sv[0] = 0;
		for (int j = 1; j < (1 << n); ++j) {
			int k = __builtin_ctz(j);
			sh[j] = sh[j ^ (1 << k)] + h[i][k];
			sv[j] = sv[j ^ (1 << k)] + v[i][k];
		}
		for (int j = 0; j < (1 << n); ++j) {
			for (int k = 0; k < (1 << n); ++k) {
				cur[j] = min(cur[j], pre[k] + sh[j ^ k]);
			}
			cur[j] += sv[j ^ (j >> 1) ^ ((j & 1) << (n - 1))];
		}
	}
//	printf("%lld\n", cur[(1 << n) - 1]);
	printf("%I64d\n", cur[(1 << n) - 1]);

	return 0;
}

// GOOD PROBLEM !!!
// GREAT PROBLEM!!!

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//431947 	May 4, 2011 9:22:03 PM 	watashi 	62E - World Evil 	GNU C++ 	Accepted 	630 ms 	6000 KB 

/*
cha

3 4
0 0 2
2 1 2
2 0 0
0 0 0
2 0 0
0 2 0
0 0 0
*/

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1218775 	Feb 23, 2012 12:01:25 PM 	watashi 	62E - World Evil 	GNU C++ 	Accepted 	830 ms 	6000 KB
