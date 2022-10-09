class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int numberOfPaths(vector<vector<int>>& a, int m) {
    int n = a[0].size();
    vector<vector<int64_t>> dp(n, vector<int64_t>(m, 0));
    dp[0][0] = 1;
    for (const auto& ai : a) {
      vector<vector<int64_t>> pre(n, vector<int64_t>(m, 0));
      pre.swap(dp);
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
          dp[j][(k + ai[j]) % m] = pre[j][k];
        }
      }
      for (int j = 1; j < n; ++j) {
        for (int k = 0; k < m; ++k) {
          dp[j][(k + ai[j]) % m] += dp[j - 1][k];
        }
        for (int k = 0; k < m; ++k) {
          dp[j][k] %= MOD;
        }
      }
    }
    return dp[n - 1][0];
  }
};
