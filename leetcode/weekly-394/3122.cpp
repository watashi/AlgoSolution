class Solution {

  static constexpr int MAXL = 10;
  static constexpr int INF = 1000000007;

public:
  int minimumOperations(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> dp(MAXL, 0);
    for (int i = 0; i < n; ++i) {
      vector<int> c(MAXL, 0);
      for (int j = 0; j < m; ++j) {
        ++c[grid[j][i]];
      }
      vector<int> pre(MAXL, INF);
      swap(pre, dp);
      for (int j = 0; j < MAXL; ++j) {
        for (int k = 0; k < MAXL; ++k) {
          if (j != k) {
            dp[j] = min(dp[j], pre[k] + m - c[j]);
          }
        }
      }
    }
    return *min_element(dp.begin(), dp.end());
  }
};
