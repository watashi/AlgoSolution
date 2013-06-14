#include <cstdio>

// |a b|
// |c d|

struct LT {
  int a, b, c, d;
};

const int MAXN = 32768;
const LT e = {1, 0, 0, 1};

int R;
LT a[MAXN << 1];

#define L(i) ((i) << 1)
#define R(i) (L(i) ^ 1)

inline void product(const LT& lhs, const LT& rhs, LT& ret) {
  ret.a = (lhs.a * rhs.a + lhs.b * rhs.c) % R;
  ret.b = (lhs.a * rhs.b + lhs.b * rhs.d) % R;
  ret.c = (lhs.c * rhs.a + lhs.d * rhs.c) % R;
  ret.d = (lhs.c * rhs.b + lhs.d * rhs.d) % R;
}

LT gao(int p, int pl, int pr, int l, int r) {
  if (l == pl && r == pr) {
    return a[p];
  } else {
    int pm = (pl + pr) >> 1;
    if (r <= pm) {
      return gao(L(p), pl, pm, l, r);
    } else if (pm <= l) {
      return gao(R(p), pm, pr, l, r);
    } else {
      LT ret;
      product(gao(L(p), pl, pm, l, pm), gao(R(p), pm, pr, pm, r), ret);
      return ret;
    }
  }
}

int main() {
  int n, m, s, l, r;
  bool blank = false;
  LT ans;

#ifndef __WATASHI__
  freopen("crypto.in", "r", stdin);
  freopen("crypto.out", "w", stdout);
#endif
  scanf("%d%d%d", &R, &n, &m);
  s = 1;
  while (s < n) {
    s <<= 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &a[s + i].a, &a[s + i].b, &a[s + i].c, &a[s + i].d);
  }
  for (int i = s - 1; i >= 1; --i) {
    product(a[L(i)], a[R(i)], a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &l, &r);
    ans = gao(1, 0, s, l - 1, r);
    if (blank) {
      putchar('\n');
    } else {
      blank = true;
    }
    printf("%d %d\n%d %d\n", ans.a, ans.b, ans.c, ans.d);
  }

  return 0;
}

