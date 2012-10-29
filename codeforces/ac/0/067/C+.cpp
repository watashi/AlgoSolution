#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 4096;
int ti, td, tr, te, na, nb, nexta, nextb;
char sa[MAXN], sb[MAXN];
int lasta[MAXN][26], lastb[MAXN][26];
int dp[MAXN][MAXN];
const int INF = 1000000007;

int main() {
	scanf("%d%d%d%d", &ti, &td, &tr, &te);
	scanf("%s%s", sa, sb);
	na = strlen(sa);
	nb = strlen(sb);
	fill(dp[0], dp[MAXN], INF);

	for (int j = 0; j < 26; ++j) {
		lasta[na][j] = na;
		for (int i = na - 1; i >= 0; --i) {
			lasta[i][j] = sa[i] - 'a' == j ? i : lasta[i + 1][j];
		}
	}
	for (int j = 0; j < 26; ++j) {
		lastb[nb][j] = nb;
		for (int i = nb - 1; i >= 0; --i) {
			lastb[i][j] = sb[i] - 'a' == j ? i : lastb[i + 1][j];
		}
	}

	dp[0][0] = 0;
	for (int i = 0; i <= na; ++i) {
		for (int j = 0; j <= nb; ++j) {
			// replace
			if (i < na && j < nb) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (sa[i] == sb[j] ? 0 : tr));
			}
			// insert
			if (j < nb) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + ti);
			}
			// delete
			if (i < na) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + td);
			}
			// exchange + delete + insert
			if (i + 2 <= na && j + 2 <= nb &&
					(nexta = lasta[i + 1][sb[j] - 'a'] + 1) <= na &&
					(nextb = lastb[j + 1][sa[i] - 'a'] + 1) <= nb) {
				dp[nexta][nextb] = min(dp[nexta][nextb], dp[i][j] + te +
						(nexta - i - 2) * td + (nextb - j - 2) * ti);
			}
			// exchange + replace1
			if (i + 2 <= na && j + 2 <= nb && sa[i] == sb[j + 1]) {
				dp[i + 2][j + 2] = min(dp[i + 2][j + 2], dp[i][j] + te + tr);
			}
			// exchange + replace2
			if (i + 2 <= na && j + 2 <= nb && sa[i + 1] == sb[j]) {
				dp[i + 2][j + 2] = min(dp[i + 2][j + 2], dp[i][j] + te + tr);
			}
		}
	}
	printf("%d\n", dp[na][nb]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//336052 	Mar 13, 2011 11:19:29 PM 	watashi 	67C - Sequence of Balls 	GNU C++ 	Accepted 	610 ms 	67800 KB 
