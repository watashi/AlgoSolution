class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int waysToReachTarget(int target, vector<vector<int>>& types) {
    vector<int64_t> dp(target + 1, 0);
    dp[0] = 1;
    for (const auto& i : types) {
      int c = i[0];
      int m = i[1];
      vector<int64_t> tmp = dp;
      for (int i = m; i <= target; ++i) {
        tmp[i] = (tmp[i] + tmp[i - m]) % MOD;
      }
      for (int i = target; i >= (c + 1) * m; --i) {
        tmp[i] = (tmp[i] - tmp[i - (c + 1) * m]) % MOD;
      }
      dp = move(tmp);
    }
    return (dp[target] + MOD) % MOD;
  }
};
