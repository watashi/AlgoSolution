#include <cstdio>
#include <algorithm>

using namespace std;

int a[64];
double c[64][64];
double dp[64][64][64];

int main() {
	int n, m;
	double x, s;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i <= n; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}

	dp[0][0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= n; ++k) {
				for (int jj = j; jj <= n; ++jj) {
					dp[i + 1][jj][max(k, (jj - j + a[i] - 1) / a[i])] += c[jj][j] * dp[i][j][k];
				}
			}
		}
	}
	
	x = s = 0;
	for (int k = 0; k <= n; ++k) {
		x += k * dp[m][n][k];
		s += dp[m][n][k];
	}
	printf("%.10lf\n", x / s);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//309487 	Feb 28, 2011 5:38:15 PM 	watashi 	28C - Bath Queue 	GNU C++ 	Accepted 	50 ms 	3400 KB 
