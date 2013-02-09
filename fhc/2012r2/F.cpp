#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 2012;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int gao(int n, int m, const int a[]) {
  vector<pair<int, int> > v[n];
  for (int i = 0; i < n && i < m; ++i) {
    v[a[i] % n].push_back({a[i] / n, (m - i + n - 1) / n});
  }
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    sort(v[i].begin(), v[i].end());
    int end = -1;
    for (auto j: v[i]) {
      j.second += j.first;
      end = max(end, j.first);
      ret += max(0, j.second - end);
      end = max(end, j.second);
    }
  }
  return ret;
}

int main() {
  int re, n, c, s, a[MAXN + MAXN];
  long long num, den, gcd;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%d", &n, &c, &s);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      a[n + i] = n + a[i];
    }

    if (c == 1) {
      num = den = 1;
      goto OUTPUT;
    }

    num = 0;
    den = 1LL * (s + 1) * (s + 1);
    for (int i = 0; i < n; ++i) {
      int l = i + 1, r = s + 2;
      while (l < r) {
        int m = (l + r) / 2;
        if (gao(n, m - i, a + i) < c) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      r = (s + 2) - r;
      if (r > 0) {
        l = r / n;
        num += 1LL * (r + r - l * n) * (l + 1);
      }
    }
    gcd = ::gcd(num, den);
    num /= gcd;
    den /= gcd;

OUTPUT:
    printf("Case #%d: ", ri);
    printf("%I64d/%I64d\n", num, den);
    fflush(stdout);
  }

  return 0;
}
