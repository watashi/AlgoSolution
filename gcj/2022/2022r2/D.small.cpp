#include <bits/stdc++.h>

using namespace std;

long long gao(long long c, vector<int> x, vector<int> y) {
  static constexpr auto INF = numeric_limits<long long>::max() / 2;
  int nx = (int)x.size(), ny = (int)y.size();
  vector<vector<long long>> dp(nx + 1, vector<long long>(ny + 1, INF));
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  dp[0][0] = 0;
  for (int i = 0; i <= nx; ++i) {
    for (int j = 0; j <= ny; ++j) {
      auto& k = dp[i][j];
      if (i > 0) {
        k = min(k, dp[i - 1][j] + 2 * x[i - 1]);
        if (i > 1) {
          k = min(k, dp[i - 2][j] + 2 * x[i - 1] + c);
        }
      }
      if (j > 0) {
        k = min(k, dp[i][j - 1] + 2 * y[j - 1]);
        if (j > 1) {
          k = min(k, dp[i][j - 2] + 2 * y[j - 1] + c);
        }
      }
      if (i > 0 && j > 0) {
        k = min(k, dp[i - 1][j - 1] + 2 * max(x[i - 1], y[j - 1]));
      }
    }
  }
  return dp[nx][ny];
}

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n, c;
    scanf("%d%d", &n, &c);
    vector<int> left[2], right[2];
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (x < 0) {
        left[y].push_back(-x);
      } else {
        right[y].push_back(x);
      }
    }
    long long ans = gao(c, left[0], left[1]) + gao(c, right[0], right[1]);
    printf("Case #%d: %lld\n", ri, ans);
  }

  return 0;
}
