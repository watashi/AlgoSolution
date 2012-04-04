#include <cstdio>
#include <algorithm>

using namespace std;

long long u, v, MOD;

long long gao(long long a, long long b, long long n, long long l, long long r) {
	// printf("(%lld,%lld)[%lld] %lld %lld\n", a, b, n, l, r);
	if (l == 0 && r == n) {
		long long x = min(n, max(0LL, (u - b + a - 1) / a));
		long long y = min(n, max(0LL, (v - b + a - 1) / a));
	//	printf("[%lld,%lld)\n", x, y);
		if (x < y) {
			long long z = 0;
			if ((y - x) % 2 == 0) {
				z = ((y - x) / 2 % MOD) * ((x + y - 1) % MOD);
			} else {
				z = ((x + y - 1) / 2 % MOD) * ((y - x) % MOD);
			}
			z = z % MOD * (a % MOD) + (y - x) % MOD * (b % MOD);
			return z % MOD;
		} else {
			return 0LL;
		}
	} else {
		long long m = (n + 1) / 2;
		if (r <= m) {
			return gao(2 * a, b, m, l, r);
		} else if (m <= l) {
			return gao(2 * a, b + a, n - m, l - m, r - m);
		} else {
			return (gao(2 * a, b, m, l, m) + gao(2 * a, b + a, n - m, 0, r - m)) % MOD;
		}
	}
}

int main() {
	long long n, m, mod;
	long long l, r, u, v;

	scanf("%I64d%I64d%I64d", &n, &m, &mod);
	::MOD = mod;
	for (int i = 0; i < m; ++i) {
		scanf("%I64d%I64d%I64d%I64d", &l, &r, &u, &v);
		::u = u;
		::v = v + 1;
		printf("%I64d\n", gao(1, 1, n, l - 1, r));
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//735884 	Oct 3, 2011 5:04:51 PM 	watashi 	117D - Not Quick Transformation 	GNU C++0x 	Accepted 	1640 ms 	1300 KB 
