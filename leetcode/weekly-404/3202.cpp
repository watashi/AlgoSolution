class Solution {
public:
  int maximumLength(vector<int>& nums, int k) {
    const int N = nums.size();
    vector<vector<int>> dp(N, vector<int>(k, 0));
    int ret = 0;
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        const int r = (nums[i] + nums[j]) % k;
        dp[i][r] = max(dp[i][r], dp[j][r] + 1);
        ret = max(ret, dp[i][r]);
      }
    }
    return ret + 1;
  }
};

