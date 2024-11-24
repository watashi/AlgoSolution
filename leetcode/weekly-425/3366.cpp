class Solution {
public:
  int minArraySum(vector<int>& nums, int k, int op1, int op2) {
    vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, 0));
    for (int x : nums) {
      vector<vector<int>> pre(op1 + 1, vector<int>(op2 + 1, 0));
      dp.swap(pre);
      for (int i = 0; i <= op1; ++i) {
        for (int j = 0; j <= op2; ++j) {
          dp[i][j] = pre[i][j] + x;
          if (i > 0) {
            dp[i][j] = min(dp[i][j], pre[i - 1][j] + (x + 1) / 2);
          }
          if (j > 0 && x >= k) {
            dp[i][j] = min(dp[i][j], pre[i][j - 1] + x - k);
            if (i > 0) {
              int y = (x - k + 1) / 2;
              if ((x + 1) / 2 >= k) {
                y = min(y, (x + 1) / 2 - k);
              }
              dp[i][j] = min(dp[i][j], pre[i - 1][j - 1] + y);
            }
          }
        }
      }
    }
    return dp[op1][op2];
  }
};
