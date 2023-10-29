class Solution {
public:
  int findKOr(vector<int>& nums, int k) {
    vector<int> c(32, 0);
    for (int i : nums) {
      for (int j = 0; j < 32; ++j) {
        if ((i >> j) & 1) {
          ++c[j];
        }
      }
    }
    int ret = 0;
    for (int j = 31; j >= 0; --j) {
      ret <<= 1;
      if (c[j] >= k) {
        ret ^= 1;
      }
    }
    return ret;
  }
};
