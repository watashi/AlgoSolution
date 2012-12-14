#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const long long MOD = 1000000007LL;

long long c[MAXN][MAXN];

void init() {
	for (int i = 0; i < MAXN; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
}

int main() {
	int re;
	int p[10], q, r;
	long long dp[MAXN], tmp, ans;

	init();
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		q = 0;
		for (int i = 1; i <= 9; ++i) {
			scanf("%d", &p[i]);
			q += p[i];
		}

		ans = 0;
		for (int i = 1; i <= 9; ++i) {
			if (p[i] == 0) {
				continue;
			}
			--p[i];
			
			r = 0;
			dp[0] = 1;
			fill(dp + 1, dp + q, 0);
			for (int j = 1; j <= 9; ++j) {
				r += p[j];
				for (int k = r; k >= 0; --k) {
					tmp = 0;
					for (int l = min(k, p[j]); l >= 0; --l) {
						tmp = (tmp + c[k][l] * dp[k - l]) % MOD;
					}
					dp[k] = tmp;
				}
			}

			tmp = 0;
			for (int j = 0; j < q; ++j) {
				tmp = (tmp * 10 + i) % MOD;
				ans = (ans + tmp * dp[j]) % MOD;
			}
			++p[i];
		}
		printf("%lld\n", ans);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//866474 	5063 	Just Sum It 	Accepted 	C++ 	0.060 	2011-08-26 05:30:03
/*
id => 1174303
pid => 5063
pname => Just Sum It
status => Accepted
lang => C++
time => 0.052
date => 2012-12-14 17:51:48
*/
