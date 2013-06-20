#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
  int l, n;
  int a[108];
  int t[26][26];
  int dp[108][26];
  int pre[108][26];
  char ans[108];

#ifndef __WATASHI__
  freopen("ssh.in", "r", stdin);
  freopen("ssh.out", "w", stdout);
#endif
  scanf("%d%d", &l, &n);
  for (int i = 1; i < l; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &t[i][j]);
    }
  }
  fill(dp[0], dp[0] + n, 0);
  for (int i = 1; i < l; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j] = 0x7fffffff;
      for (int k = 0; k < n; ++k) {
        if (dp[i][j] > dp[i - 1][k] + abs(a[i] - t[k][j])) {
          dp[i][j] = dp[i - 1][k] + abs(a[i] - t[k][j]);
          pre[i][j] = k;
        }
      }
    }
  }
  int k = min_element(dp[l - 1], dp[l - 1] + n) - dp[l - 1];
  fprintf(stderr, "%d\n", dp[l - 1][k]);
  ans[l] = '\0';
  for (int i = l - 1; i >= 0; --i) {
    ans[i] = (char)('a' + k);
    k = pre[i][k];
  }
  puts(ans);

  return 0;
}

