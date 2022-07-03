class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    static const int MOD = 1000000007;
    vector<int64_t> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = delay; j < forget && j <= i; ++j) {
        dp[i] += dp[i - j];
      }
      dp[i] %= MOD;
    }
    int64_t ans = 0;
    for (int i = 1; i <= forget && i <= n; ++i) {
      ans += dp[n - i];
    }
    return ans % MOD;
  }
};
