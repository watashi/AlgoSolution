#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2012;
const long long MOD = 1000000007LL;

long long dp[MAXN][MAXN][2];

int main() {
  int n, m;
  long long x, y, ans;

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      dp[i][j][0] = 1;
    }
  }
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    // 0->0
    y = x = 0;
    for (int j = 2; j <= m; ++j) {
      x = (x + dp[i - 1][j][0]) % MOD;
      y = (y + x) % MOD;
      dp[i][j][0] += y;
    }
    // 0->1
    y = x = 0;
    for (int j = m; j >= 2; --j) {
      dp[i][j][1] += (y + x) % MOD;
      x = (x + dp[i - 1][j][0] * (m + 1 - j)) % MOD;
      y = (y + x) % MOD;
    }
    // 1->1
    y = x = 0;
    for (int j = m; j >= 2; --j) {
      x = (x + dp[i - 1][j][1]) % MOD;
      y = (y + x) % MOD;
      dp[i][j][1] += y;
    }
    // ans
    for (int j = 2; j <= m; ++j) {
      ans = (ans + dp[i][j][0] * (m + 1 - j) + dp[i][j][1]) % MOD;
    }
  }
  ans = (ans + MOD) % MOD;
  printf("%d\n", (int)ans);

  return 0;
}

