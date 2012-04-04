#include <cstdio>
#include <algorithm>

using namespace std;

long long extGcd(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

long long modInv(long long a, long long m) {
	long long x, y;
	extGcd(a, m, x, y);
	x %= m;
	while (x < 0) {
		x += m;
	}
	return x;
}

const int MAXN = 1024;
const long long MOD = 1000000007LL;

long long r[MAXN], f[MAXN], c[MAXN][MAXN];

void init() {
	for (int i = 0; i < MAXN; ++i) {
		r[i] = i == 0 ? 0LL : modInv(i, MOD);
		f[i] = i == 0 ? 1LL : f[i - 1] * i % MOD;
		c[i][0] = c[i][i] = 1LL;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}

long long choose(int n, int m) {
	if (n < m) {
		return 0;
	}
	long long ret = 1;
	for (int i = 0; i < m; ++i) {
		ret = ret * (n - i) % MOD;
		ret = ret * r[i + 1] % MOD;
	}
	return ret;
}

long long power(long long a, long long b) {
	long long c = 1;
	while (b > 0) {
		if (b & 1) {
			c = c * a % MOD;
		}
		b >>= 1;
		a = a * a % MOD;
	}	
	return c;
}

long long ch[MAXN][MAXN];

int main() {
	int n, m, k;
	long long dp[MAXN], tmp, ans;

	init();
	scanf("%d%d%d", &n, &m, &k);
	fill(dp, dp + MAXN, 0);
	dp[0] = 1LL;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j >= 0; --j) {
			dp[j] = (j * dp[j] + (j > 0 ? dp[j - 1] : 0)) % MOD;
		}
	}

	ans = 0;

	if (m == 1) {
		ans = power(k, n);
	} else {
		fill(ch[0], ch[MAXN], 0);
		for (int i = 0; i <= n; ++i) {	// k - i
			for (int j = 0; j <= n && j <= n; ++j) {	// j
				if (j > k - i) {
					ch[i][j] = 0;
				} else if (j == 0) {
					ch[i][j] = 1;
				} else {
					ch[i][j] = ch[i][j - 1];
					ch[i][j] = ch[i][j] * (k - i + 1 - j) % MOD;
					ch[i][j] = ch[i][j] * r[j] % MOD;
				}
			}
		}
		for (int same = 0; same <= n && same <= k; ++same) {
			for (int diff = 0; same + diff <= n && same + diff <= k; ++diff) {
				tmp = 1LL;
				tmp = tmp * ch[0][same] % MOD;
				tmp = tmp * ch[same][diff] % MOD;
				tmp = tmp * ch[same + diff][diff] % MOD;
				tmp = tmp * f[same + diff] % MOD;
				tmp = tmp * f[same + diff] % MOD;
				tmp = tmp * dp[same + diff] % MOD;
				tmp = tmp * dp[same + diff] % MOD;
				if (m > 2) {
					if (same == 0) {
						tmp = 0;
					} else {
						tmp = tmp * power(same, n * (m - 2)) % MOD;
					}
				}
			//	printf("<%d,%d> + %lld\n", same, diff, tmp);
				ans = (ans + tmp) % MOD;
			}
		}
	}
	printf("%d\n", (int)ans);

	return 0;
}

/*
   2 3 2
   18

   3 3 3
   1839
   */
