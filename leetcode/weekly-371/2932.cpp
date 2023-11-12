class Solution {
public:
  int maximumStrongPairXor(vector<int>& nums) {
    int ret = 0;
    for (int i : nums) {
      for (int j : nums) {
        if (abs(i - j) <= min(i, j)) {
          ret = max(ret, i ^ j);
        }
      }
    }
    return ret;
  }
};
