#include <stdio.h>

enum { MAXN = 10086, MAXM = 16 };

int e[MAXN];
int rmq[MAXM][MAXN];

inline int lg2(int i) { return 31 - __builtin_clz(i); }
inline int bin(int i) { return 1 << i; }
inline int cmp(int i, int j) { return e[i] >= e[j] ? i : j; }

void build(int n) {
  for (int i = 0; i < n; ++i) {
    rmq[0][i] = i;
  }
  for (int i = 0; bin(i + 1) <= n; ++i) {
    for (int j = 0; j + bin(i + 1) <= n; ++j) {
      rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + bin(i)]);
    }
  }
}

int index(int l, int r) {
  int b = lg2(r - l);
  return cmp(rmq[b][l], rmq[b][r - bin(b)]);
}

typedef long long llint;

llint cap, gain;

llint gao(int l, int r, llint s, llint t) {
  if (l >= r) {
    return 0;
  } else {
    int m = index(l, r);
    llint from = s + (m - l) * gain;
    llint to = t - (r - m) * gain;
    llint ret = 0;

    if (from > cap) {
      from = cap;
    }
    if (to < 0) {
      to = 0;
    }
    ret += (from - to) * e[m];
    ret += gao(l, m, s, from);
    ret += gao(m + 1, r, to + gain, t);

    return ret;
  }
}

int main() {
  int re, n;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%lld%lld%d", &cap, &gain, &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &e[i]);
    }
    build(n);
    printf("Case #%d: %lld\n", ri, gao(0, n, cap, 0));
  }

  return 0;
}

