class Solution {
public:
  int countOfPairs(vector<int>& nums) {
    static const int MAXN = 1001;
    static constexpr int64_t MOD = 1000000007;
    vector<int64_t> dp(MAXN, 0);
    vector<int64_t> ps(MAXN, 0);
    fill(dp.data(), dp.data() + nums[0] + 1, 1);

    for (int i = 1; i < (int)nums.size(); ++i) {
      const int pre = nums[i - 1], cur = nums[i];
      partial_sum(dp.begin(), dp.end(), ps.begin());
      for (auto& j : ps) {
        j %= MOD;
      }
      fill(dp.begin(), dp.end(), 0);
      for (int i = 0; i <= cur; ++i) {
        // j <= i
        // pre - j >= cur - i ==> j <= pre - cur + i
        const int j = min(i, pre - cur + i);
        dp[i] = j < 0 ? 0 : ps[j];
      }
    }

    int64_t ret = accumulate(dp.begin(), dp.end(), 0LL);
    ret %= MOD;
    return (int)ret;
  }
};
