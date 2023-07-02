class Solution {
public:
  int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int ret = 0, cnt = 0, rem = 0;
    for (int i : nums) {
      if (i > threshold) {
        cnt = rem = 0;
      }
      else if (i % 2 == rem) {
        ++cnt;
        rem = 1 - rem;
      }
      else {
        cnt = rem = 1 - i % 2;
      }
      ret = max(ret, cnt);
    }
    return ret;
  }
};
