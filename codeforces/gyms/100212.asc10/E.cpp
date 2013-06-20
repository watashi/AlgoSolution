#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int tri[10] = {
  1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683
};

map<int, int> mp;
int rp[19683];

void init(int n, int x, int y) {
  if (n == 0) {
    rp[x] = y;
    mp[y] = x;
  } else {
    --n;
    x *= 3;
    y <<= 2;
    init(n, x, y);
    init(n, x + 1, y ^ 1);
    init(n, x + 2, y ^ 3);
  }
}

long long dp[30][10][19683];

void solve(int m, int n) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      dp[0][0][0] = 1;
    } else {
      for (int k = 0; k < tri[m]; ++k) {
        dp[i][0][k] = dp[i - 1][m][k];
      }
    }
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < tri[m]; ++k) {
        int kk = rp[k];
        if (kk & (2 << (j << 1))) { // 3
          dp[i][j + 1][mp[kk ^ (2 << (j << 1))]] += dp[i][j][k];
        } else if (kk & (1 << (j << 1))) { // 1
          dp[i][j + 1][mp[kk ^ (1 << (j << 1))]] += dp[i][j][k];
        } else { // 0
          dp[i][j + 1][mp[kk ^ (3 << (j << 1))]] += dp[i][j][k];
          if (j + 3 <= m && (kk & (0x3f << (j << 1))) == 0) {
            dp[i][j + 3][k] += dp[i][j][k];
          }
        }
      }
    }
  }
}

int main() {
  int m, n;

#ifndef __WATASHI__
  freopen("dominoes.in", "r", stdin);
  freopen("dominoes.out", "w", stdout);
#endif
  cin >> m >> n;
  init(m, 0, 0);
  solve(m, n);
  cout << dp[n - 1][m][0] << endl;

  return 0;
}

