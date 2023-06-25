class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int numberOfGoodSubarraySplits(vector<int>& nums) {
    int pre = -1;
    int64_t ret = 1;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (nums[i] == 1) {
        if (pre >= 0) {
          ret *= i - pre;
          ret %= MOD;
        }
        pre = i;
      }
    }
    return pre >= 0 ? ret : 0;
  }
};
