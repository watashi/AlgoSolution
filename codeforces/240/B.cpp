#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const int MAXM = MAXN * MAXN;
const int INF = 1000000007;

int dp[MAXN][MAXM][2];

inline void upd(int& lhs, int rhs) {
  lhs = min(lhs, rhs);
}

int main() {
#ifndef __WATASHI__
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, a, b, s, hl, hr;

  scanf("%d%d%d", &n, &a, &b);
  fill(dp[0][0], dp[n][a + 1], INF);
  dp[0][0][0] = dp[0][0][1] = 0;
  s = hl = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &hr);
    s += hr;
    for (int j = 0; j <= a; ++j) {
      if (j + hr <= a) {
        upd(dp[i + 1][j + hr][0], dp[i][j][0]);
        upd(dp[i + 1][j + hr][0], dp[i][j][1] + min(hl, hr));
      }
      if (s - j <= b) {
        upd(dp[i + 1][j][1], dp[i][j][1]);
        upd(dp[i + 1][j][1], dp[i][j][0] + min(hl, hr));
      }
    }
    hl = hr;
  }

  s = INF;
  for (int j = 0; j <= a; ++j) {
    s = min(s, min(dp[n][j][0], dp[n][j][1]));
  }
  printf("%d\n", s < INF ? s : -1);

  return 0;
}
