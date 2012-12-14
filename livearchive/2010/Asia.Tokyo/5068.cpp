#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 256;
const int INF = 1000000007;

int p[MAXN], t[MAXN];
int dp[MAXN][MAXN];

int main() {
	int n, ans;

	while (scanf("%d", &n) != EOF && n > 0) {
		p[0] = t[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &p[i], &t[i]);
		}
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= 4; ++j) {
				dp[i][j] = INF;
			}
		}
	
		ans = dp[0][1] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 4; ++j) {
				if (dp[i - 1][j] < INF) {
					if (t[i] - t[i - 1] >= abs(p[i] - p[i - 1]) * j) {
						dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + abs(p[i] - p[i - 1]));
					}
					if (t[i] - t[i - 1] >= abs(p[i - 1]) * j + abs(p[i])) {
						dp[i][2] = min(dp[i][2], dp[i - 1][j] + abs(p[i - 1]) + abs(p[i]));
					}
				}
			}
			ans = INF;
			for (int j = 1; j <= 4; ++j) {
			//	if (dp[i][j] < INF) {
			//		printf("[%d][%d] = %d\n", i, j, dp[i][j]);
			//	}
				ans = min(ans, dp[i][j]);
			}
			if (ans == INF) {
				ans = -i;
				break;
			}
		}

		if (ans < 0) {
			printf("NG %d\n", -ans);
		} else {
			printf("OK %d\n", ans + abs(p[n]));
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//771949  	2011-04-28 12:03:45 	Accepted	0.002	Minimum	26909	C++	5068 - Balloon Collecting
/*
id => 1174084
pid => 5068
pname => Balloon Collecting
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:20:16
*/
