class Solution {
public:
  long long maximumStrength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= k; ++i) {
      long long mul = k + 1 - i;
      if (mul % 2 == 0) {
        mul = -mul;
      }
      long long best = numeric_limits<long long>::min() / 10;
      vector<long long> pre(n + 1, best);
      dp.swap(pre);
      for (int j = i; j <= n; ++j) {
        best = max(best, pre[j - 1]) + nums[j - 1] * mul;
        dp[j] = max(dp[j - 1], best);
      }
    }
    return dp[n];
  }
};
