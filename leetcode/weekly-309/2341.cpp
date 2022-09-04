class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    static constexpr int BITS = 30;
    int start = 0, ret = 0;
    vector<int> pos(BITS, -1);
    for (int i = 0; i < (int)nums.size(); ++i) {
      for (int j = 0; j < BITS; ++j) {
        if (((nums[i] >> j) & 1) != 0) {
          start = max(start, pos[j] + 1);
          pos[j] = i;
        }
      }
      ret = max(ret, i - start + 1);
    }
    return ret;
  }
};
