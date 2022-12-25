class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int countPartitions(vector<int>& nums, int k) {
    int64_t sum = accumulate(nums.begin(), nums.end(), 0LL);
    vector<int64_t> dp(k, 0);
    int64_t ret = 1;
    dp[0] = 1;
    for (int i : nums) {
      ret = ret * 2 % MOD;
      for (int j = k - 1; j >= i; --j) {
        dp[j] += dp[j - i];
        if (dp[j] >= MOD) {
          dp[j] -= MOD;
        }
      }
    }
    for (int i = 0; i < k; ++i) {
      int64_t j = sum - i;
      if (j < k) {
        ret -= dp[i];
      }
      else {
        ret -= 2 * dp[i];
      }
    }
    ret = (ret % MOD + MOD) % MOD;
    return ret;
  }
};
