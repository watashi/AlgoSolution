#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const long long MOD = 1000000007LL;

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
	return (x % m + m) % m;
}

long long a[MAXN];

int main() {
  int re, n, k;
  long long tmp, ans;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    tmp = 1;
    ans = 0;
    for (int i = k - 1; i < n; ++i) {
      if (i >= k) {
        tmp = tmp * i % MOD * modInv(i - (k - 1), MOD) % MOD;
      }
      ans += a[i] * tmp % MOD;
    }
    printf("Case #%d: %lld\n", ri, ans % MOD);
    fflush(stdout);
  }

  return 0;
}

