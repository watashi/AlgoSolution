#include <cstdio>
#include <limits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 100100;
const llint INF = 0x123456789ABCDEFLL;

llint mul(llint a, llint b) {
  if (a == 0 || b == 0) {
    return 0;
  } else if (a > INF / b) {
    return INF;
  } else {
    return min(INF, a * b);
  }
}

llint a[MAXN], b[MAXN];

int main() {
  int n, u, v;
  llint lo, hi, x, y, s;

  scanf("%d%d%d", &n, &u, &v);
  x = u;
  y = v;
  s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &u);
    a[i] = u;
    s += a[i];
    if (x > 0) {
      b[i] = a[i] % x;
      a[i] /= x;
    } else {
      a[i] = b[i] = 0;
    }
  }
  sort(b, b + n);
  reverse(b, b + n);

  lo = 0;
  hi = INF;
  while (lo < hi) {
    // cout << lo << " " << hi << endl;
    llint mi = (lo + hi) / 2;
    llint cx = mi, sx = 0;
    for (int i = 0; i < n; ++i) {
      llint dx = min(cx, a[i]);
      cx -= dx;
      sx += dx * x;
    }
    for (int i = 0; i < n; ++i) {
      if (cx > 0) {
        --cx;
        sx += b[i];
      }
    }
    if (mul(y, mi) < s - sx) {
      lo = mi + 1;
    } else {
      hi = mi;
    }
  }
  cout << hi << endl;

  return 0;
}

