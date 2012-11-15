#include <cstdio>

using namespace std;

const int MAXN = 12;

long long ten[MAXN], fact[MAXN], perm[MAXN][MAXN], base[MAXN];

void init() {
  ten[0] = 1;
  fact[0] = 1;
  perm[0][0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    ten[i] = ten[i - 1] * 10;
    fact[i] = fact[i - 1] * i;
    perm[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      perm[i][j] = perm[i][j - 1] * (i - j + 1);
    }
  }
  base[0] = base[1] = 0;
  for (int i = 2; i < MAXN; ++i) {
    base[i] = base[i - 1] + 9 * perm[9][i - 2];
  }
}

int digit(long long n, int k) {
  return n / ten[k] % 10;
}

long long gao(long long n) {
  int m = 1;
  while (m < MAXN && n >= ten[m]) {
    ++m;
  }
  if (m == MAXN) {
    return base[MAXN - 1];
  } else {
    long long ret = base[m] + (digit(n, m - 1) - 1) * perm[9][m - 1];
    int d = ((1 << 10) - 1) ^ (1 << digit(n, m - 1));
    for (int i = m - 2; i >= 0; --i) {
      int t = digit(n, i);
      ret += __builtin_popcount(((1 << t) - 1) & d) *
        perm[__builtin_popcount(d) - 1][i];
      if (d & (1 << t)) {
        d ^= 1 << t;
      } else {
        break;
      }
    }
    return ret;
  }
}

int main() {
  int re;
  long long l, r;

  init();
  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", gao(r + 1) - gao(l));
  }

  return 0;
}

//Correct Answer
//Execution Time: 0.75

