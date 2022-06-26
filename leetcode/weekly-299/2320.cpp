class Solution {
public:
  int countHousePlacements(int n) {
    static constexpr int MOD = 1000000007;
    int64_t pre[4], dp[4];
    fill(dp, dp + 4, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      copy(dp, dp + 4, pre);
      for (int i = 0; i < 4; ++i) {
        dp[i] = 0;
        for (int j = 0; j < 4; ++j) {
          if ((i & j) == 0) {
            dp[i] += pre[j];
          }
          dp[i] %= MOD;
        }
      }
    }
    int64_t ans = accumulate(dp, dp + 4, 0LL);
    return ans % MOD;
  }
};
