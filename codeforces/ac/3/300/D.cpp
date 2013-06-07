#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 31, MAXM = 1024;
const llint MOD = 7340033;

void convolution(int n, const llint a[], llint ret[]) {
  llint b[MAXM];
  for (int i = 0; i < n; ++i) {
    llint t = 0;
    for (int j = 0; j <= i; ++j) {
      t += a[j] * a[i - j];
    }
    b[i] = t % MOD;
  }
  copy(b, b + n, ret);
}

llint dp[MAXN][MAXM];

int main() {
  dp[0][0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    convolution(MAXM, dp[i - 1], dp[i]);
    convolution(MAXM, dp[i], dp[i]);
    copy(dp[i], dp[i] + MAXM - 1, dp[i] + 1);
    dp[i][0] = 1;
  }

  int re, n, k;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &n, &k);
    printf("%d\n", (int)dp[min(__builtin_ctz(~n), __builtin_popcount(n) - 1)][k]);
  }

  return 0;
}

