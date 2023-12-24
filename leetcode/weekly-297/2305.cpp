class Solution {
public:
  int distributeCookies(vector<int>& cookies, int k) {
    int n = cookies.size();
    int m = 1 << n;
    vector<int> s(m, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          s[i] += cookies[j];
        }
      }
    }
    vector<vector<int>> dp(k + 1, vector<int>(m, numeric_limits<int>::max() / 2));
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
      dp[i] = dp[i - 1];
      for (int j = 0; j < m; ++j) {
        for (int k = j; k > 0; k = (k - 1) & j) {
          dp[i][j] = min(dp[i][j], max(dp[i - 1][j ^ k], s[k]));
        }
        // printf("[%d][%d] = %d\n", i, j, dp[i][j]);
      }
    }
    return dp[k][m - 1];
  }
};
