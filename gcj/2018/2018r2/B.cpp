#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
static int C2[MAXN];
static int dp[MAXN][MAXN];

void init() {
  for (int i = 0; i < MAXN; ++i) {
    C2[i] = i * (i + 1) / 2;
  }
  for (int kr = 0; C2[kr] <= MAXN - 1; ++kr) {
    for (int i = MAXN - 1; i >= 0; --i) {
      for (int j = MAXN - 1; j >= 0; --j) {
        for (int kb = 0; C2[kb] <= j; ++kb) {
          int ii = i - kr * (kb + 1);
          int jj = j - C2[kb];
          if (ii >= 0 && jj >= 0) {
            dp[i][j] = max(dp[i][j], dp[ii][jj] + kb + 1);
          }
        }
      }
    }
  }
}


int main() {
  int re;

  init();
  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int r, b;
    scanf("%d%d", &r, &b);
    printf("Case #%d: %d\n", ri, dp[r][b] - 1);
  }

  return 0;
}
