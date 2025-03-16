class Solution {
public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    const int n = nums.size();
    int r = n - count(nums.begin(), nums.end(), 0);
    if (r == 0) {
      return 0;
    }

    vector<bitset<1001>> dp(n, bitset<1001>(1));
    for (int k = 0; k < (int)queries.size(); ++k) {
      const int from = queries[k][0], to = queries[k][1], val = queries[k][2];
      for (int i = from; i <= to; ++i) {
        if (dp[i][nums[i]]) {
          continue;
        }
        dp[i] |= dp[i] << val;
        if (dp[i][nums[i]]) {
          --r;
        }
      }
      if (r == 0) {
        return k + 1;
      }
    }
    return -1;
  }
};
