#include <cstdio>
#include <string>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10;
const int INF = 1000;

int na, nb, nc;
int a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN][MAXN][MAXN][2];
pair<string, string> ans[MAXN][MAXN][MAXN][2];

void read(int& n, int a[]) {
	int x;
	scanf("%*[^0-9]");
	scanf("%d", &x);
	n = 0;
	while (x > 0) {
		a[n++] = x % 10;
		x /= 10;
	}
	a[n] = -1;
}

int main() {
	read(na, a);
	read(nb, b);
	read(nc, c);
	for (int i = 0; i <= na + 1; ++i) {
		for (int j = 0; j <= nb + 1; ++j) {
			for (int k = 0; k <= nc; ++k) {
				dp[i][j][k][0] = dp[i][j][k][1] = INF;
			}
		}
	}

	dp[0][0][0][0] = 0;
	for (int i = 0; i <= na + 1; ++i) {
		for (int j = 0; j <= nb + 1; ++j) {
			for (int k = 0; k <= nc; ++k) {
				for (int l = 0; l <= 1; ++l) {
					if (dp[i][j][k][l] == INF) {
						continue;
					}
					if (i == na && dp[i + 1][j][k][l] > dp[i][j][k][l]) {
						dp[i + 1][j][k][l] = dp[i][j][k][l];
						ans[i + 1][j][k][l] = ans[i][j][k][l];
					}
					if (j == nb && dp[i][j + 1][k][l] > dp[i][j][k][l]) {
						dp[i][j + 1][k][l] = dp[i][j][k][l];
						ans[i][j + 1][k][l] = ans[i][j][k][l];
					}
					//	if (k == nc && dp[i][j][k + 1][l] > dp[i][j][k][l]) {
					//		dp[i][j][k + 1][l] = dp[i][j][k][l];
					//		ans[i][j][k + 1][l] = ans[i][j][k][l];
					//	}
					for (int x = 0; x < (i <= na ? 10 : 1); ++x) {
						for (int y = 0; y < (j <= nb ? 10 : 1); ++y) {
							int ii = i + (i <= na && x == a[i] ? 1 : 0);
							int jj = j + (j <= nb && y == b[j] ? 1 : 0);
							int kk = k + ((x + y + l) % 10 == c[k] ? 1 : 0);
							int ll = (x + y + l) / 10;
							if (dp[ii][jj][kk][ll] > dp[i][j][k][l] + (i <= na ? 1 : 0) + (j <= nb ? 1 : 0) + 1) {
								dp[ii][jj][kk][ll] = dp[i][j][k][l] + (i <= na ? 1 : 0) + (j <= nb ? 1 : 0) + 1;
								ans[ii][jj][kk][ll] = ans[i][j][k][l];
								if (i <= na) {
									ans[ii][jj][kk][ll].first += '0' + x;
								}
								if (j <= nb) {
									ans[ii][jj][kk][ll].second += '0' + y;
								}
							}
						}
					}
				}
			}
		}
	}

	pair<string, string> ab = ans[na + 1][nb + 1][nc][0];
	reverse(ab.first.begin(), ab.first.end());
	long long va = strtoll(ab.first.c_str(), NULL, 0);
	reverse(ab.second.begin(), ab.second.end());
	long long vb = strtoll(ab.second.c_str(), NULL, 0);
//	printf("%lld+%lld=%lld\n", va, vb, va + vb);
	printf("%I64d+%I64d=%I64d\n", va, vb, va + vb);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//422808 	May 3, 2011 12:59:08 PM 	watashi 	58E - Expression 	GNU C++ 	Accepted 	30 ms 	1500 KB 
