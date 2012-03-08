#include <cstdio>

const int MAXN = 707;

typedef int Mat[MAXN][MAXN];

// (long long => int: 5s->1.5s)
void mul(int n, const int a[MAXN][MAXN], const int b0[MAXN][MAXN], int c[MAXN][MAXN]) {
	static int b[MAXN][MAXN];
//	for (int i = 1; i <= n; ++i) {	// (transpose: 8s->5s) (when int: no change)
//		for (int j = 1; j <= n; ++j) {
//			b[i][j] = b0[j][i];
//		}
//	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {	// (half: 16s->8s)
			for (int k = 1; k <= n; ++k) {
				c[i][j] += a[i][k] * b[j][k];
			}
			c[j][i] = c[i][j];
		}
	}
}

int c[MAXN];
Mat e, e2, e3;

int main() {
	int n, m, a, b;
	long long ans;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
		++c[a];
		++c[b];
	}

	ans = 0;
	mul(n, e, e, e2);
	mul(n, e, e2, e3);
//	mul2(n, e, e4, e5); (1.5s->0.8s)
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			ans += (long long)e3[i][k] * e2[k][i];
		}
	}
	ans /= 10;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (e[i][j] == 0) {
				continue;
			}
			a = c[i] + c[j];
			for (int k = j + 1; k <= n; ++k) {
				if (e[i][k] == 0 || e[j][k] == 0) {
					continue;
				}
				ans -= a + c[k] - 3;
			}
		}
	}
//	printf("%lld\n", ans);
	printf("%I64d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//235305 	Dec 30, 2010 9:32:57 AM 	watashi 	E - Pentagon 	GNU C++ 	Accepted 	5010 ms 	28684 KB 
//235309 	Dec 30, 2010 9:38:18 AM 	watashi 	E - Pentagon 	GNU C++ 	Accepted 	1450 ms 	14988 KB 
//235313 	Dec 30, 2010 9:51:46 AM 	watashi 	E - Pentagon 	GNU C++ 	Accepted 	890 ms 	9120 KB 
