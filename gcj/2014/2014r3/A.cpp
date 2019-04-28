#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

int64_t a[MAXN];

int main() {
  int re, n;
  int64_t p, q, r, s;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%lld%lld%lld%lld", &n, &p, &q, &r, &s);
    for (int i = 0; i < n; ++i) {
      a[i] = (p * i + q) % r + s;
    }

    s = accumulate(a, a + n, 0LL);
    p = q = 0;
    r = s;
    for (int i = 0, j = 0; i < n; ++i) {
      q += a[i];
      while (j <= i && p + a[j] <= q - a[j]) {
        p += a[j];
        q -= a[j];
        ++j;
      }
      int64_t d = max(p, q);
      if (j <= i) {
        d = min(d, max(p + a[j], q - a[j]));
      }
      d = max(d, s - p - q);
      r = min(r, d);
    }
    r = s - r;
    printf("Case #%d: %.10Lf\n", ri, (long double)r / (long double)s);
  }

  return 0;
}

// -ftrapv -g
