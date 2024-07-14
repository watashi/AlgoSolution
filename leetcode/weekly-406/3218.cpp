class Solution {
public:
  int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
    static int dp[21][21][21][21];
    memset(dp, 0x7f, sizeof(dp));
    for (int dx = 0; dx < m; ++dx) {
      for (int dy = 0; dy < n; ++dy) {
        for (int x2 = dx; x2 < m; ++x2) {
          for (int y2 = dy; y2 < n; ++y2) {
            const int x1 = x2 - dx;
            const int y1 = y2 - dy;
            auto& cur = dp[x1][y1][x2][y2];
            if (x1 == x2 && y1 == y2) {
              cur = 0;
            }
            for (int x3 = x1; x3 < x2; ++x3) {
              cur = min(cur, dp[x1][y1][x3][y2] + dp[x3 + 1][y1][x2][y2] + hc[x3]);
            }
            for (int y3 = y1; y3 < y2; ++y3) {
              cur = min(cur, dp[x1][y1][x2][y3] + dp[x1][y3 + 1][x2][y2] + vc[y3]);
            }
          }
        }
      }
    }
    return dp[0][0][m - 1][n - 1];
  }
};
