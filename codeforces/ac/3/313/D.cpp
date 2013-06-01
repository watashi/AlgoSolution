#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 320;
const llint INF = 0x0123456789ABCDEFLL;

llint d[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
  int n, m, k, a, b, c;
  llint ans;

  scanf("%d%d%d", &n, &m, &k);

  fill(d[0], d[n + 1], INF);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    --a;
    d[a][b] = min<llint>(d[a][b], c);
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      d[j][i] = min(d[j][i], d[j - 1][i]);
    }
  }

  fill(dp[0], dp[n + 1], INF);
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 0;
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] == INF) {
        continue;
      }
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      for (int k = i + 1; k <= n; ++k) {
        dp[k][j + (k - i)] = min(dp[k][j + (k - i)], dp[i][j] + d[i][k]);
      }
    }
  }

  ans = *min_element(dp[n] + k, dp[n + 1]);
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;

  return 0;
}

