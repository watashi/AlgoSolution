class Solution {
public:
  int maximumCount(vector<int>& nums) {
    int p = 0, n = 0;
    for (int i : nums) {
      if (i > 0) {
        ++p;
      }
      else if (i < 0) {
        ++n;
      }
    }
    return max(p, n);
  }
};
