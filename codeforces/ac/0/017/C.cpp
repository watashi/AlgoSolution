#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 160;
const int MAXM = MAXN / 3;
const int MOD = 51123987;

int next[MAXN][3];
int dp[MAXN][MAXM][MAXM][MAXM];

int main() {
	int n, m, l, ans;
	char s[MAXN];

	scanf("%d%s", &n, s);
	l = (n + 2) / 3;
	m = unique(s, s + n) - s;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 3; ++j) {
			next[i][j] = find(s + i, s + n, 'a' + j) - s;
		}
	}

	ans = 0;
	dp[0][0][0][0] = 1;
	for (int k = 0; k < m; ++k) {
		int i[3];
		for (i[0] = 0; i[0] <= l; ++i[0]) {
			for (i[1] = 0; i[1] <= l; ++i[1]) {
				for (i[2] = 0; i[2] <= l; ++i[2]) {
					int s = dp[k][i[0]][i[1]][i[2]];
					if (s == 0) {
						continue;
					} else if (i[0] + i[1] + i[2] == n && *max_element(i, i + 3) - *min_element(i, i + 3) <= 1) {
						ans = (ans + s) % MOD;
					} else {
						for (int j = 0; j < 3; ++j) {
							++i[j];
							int& t = dp[next[k][j]][i[0]][i[1]][i[2]];
							t = (t + s) % MOD;
							--i[j];
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//423228 	May 3, 2011 8:57:44 PM 	watashi 	17C - Balance 	GNU C++ 	Accepted 	360 ms 	94600 KB 
