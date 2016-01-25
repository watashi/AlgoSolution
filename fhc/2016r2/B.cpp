#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 3030;

int main() {
  int re = 0;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n, k;
    double p, q;
    static double dp[MAXN], e[MAXN];
    static double a[MAXN][MAXN];

    scanf("%d%d%lf", &n, &k, &p);
    q = 1.0 - p;

    a[0][0] = 1.0;
    for (int i = 1; i <= n; ++i) {
      e[i] = 0;
      a[i][0] = a[i - 1][0] * q;
      for (int j = 1; j <= i; ++j) {
        a[i][j] = a[i - 1][j - 1] * p + a[i - 1][j] * q;
        if (j >= k) {
          e[i] += a[i][j];
        }
      }
    }

    for (int i = 0; i <= n; ++i) {
      dp[i] = 0;
      for (int j = k; j <= i; ++j) {
        dp[i] = max(dp[i], dp[i - j] + e[j]);
      }
    }
    printf("Case #%d: %.9f\n", ri, dp[n]);
  }

  return 0;
}
