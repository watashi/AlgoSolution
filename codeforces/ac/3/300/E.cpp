#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 10001000;

llint a[MAXN];
bool b[MAXN];

llint gao(llint n, llint p) {
  llint m = 0;
  while (n >= p) {
    n /= p;
    m += n;
  }
  return m;
}

llint gao(llint l, llint r, llint p, llint q) {
  while (l < r) {
    llint m = (l + r) / 2;
    if (gao(m, p) < q) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return r;
}

int main() {
  int n, x;
  long long ans;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x > 1) {
      ++a[2];
      --a[x + 1];
    }
  }
  partial_sum(a, a + MAXN, a);

  for (int i = 2; i < MAXN; ++i) {
    if (!b[i]) {
      llint c = 0;
      for (llint j = i; j < MAXN; j *= i) {
        for (llint k = j; k < MAXN; k += j) {
          b[k] = true;
          c += a[k];
        }
      }
      a[i] = c;
    } else {
      a[i] = 0;
    }
  }

  ans = 1;
  for (int i = MAXN - 1; i >= 2; --i) {
    if (a[i] > 0 && gao(ans, i) < a[i]) {
      ans = gao(ans + 1, i * a[i], i, a[i]);
    }
  }
  printf("%I64d\n", ans);

  return 0;
}

