
class Solution {
public:
  int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int ret = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (__builtin_popcount(i) == k) {
        ret += nums[i];
      }
    }
    return ret;
  }
};
