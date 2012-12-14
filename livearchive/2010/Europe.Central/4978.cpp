#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;
const int MOD = 1000000007;
const int a[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int b[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int x[MAXN], y[MAXN], z[8], c[1 << 8], dp[1 << 8];

int powmod(int a, int b) {
	int c = 1;
	while (b > 0) {
		if (b & 1) {
			c = 1LL * a * c % MOD;
		}
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return c;
}

int main() {
	int re, n;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		fill(z, z + 8, 0x80000000);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			for (int j = 0; j < 8; ++j) {
				z[j] = max(z[j], a[j] * x[i] + b[j] * y[i]);
			}
		}
		fill(c, c + (1 << 8), 0);
		for (int i = 0; i < n; ++i) {
			int k = 0;
			for (int j = 0; j < 8; ++j) {
				if (z[j] == a[j] * x[i] + b[j] * y[i]) {
					k |= 1 << j;
				}
			}
			++c[k];
		}
		fill(dp, dp + (1 << 8), 0);
//		dp[0] = powmod(2, c[0]);
		dp[0] = 1;
		for (int i = 0; i < (1 << 8); ++i) {
			int d = (powmod(2, c[i]) - 1 + MOD) % MOD;
			for (int j = (1 << 8) - 1; j >= 0; --j) {
				dp[j | i] = (1LL * d * dp[j] + dp[j | i]) % MOD;
			}
		}
		printf("%d\n", dp[(1 << 8) - 1]);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722953  	2011-01-20 14:56:42 	Accepted	1.066	8592	26909	C++	4978 - Fields and Farmers

/*
id => 1174059
pid => 4978
pname => Fields and Farmers
status => Accepted
lang => C++
time => 0.459
date => 2012-12-14 17:17:04
*/
