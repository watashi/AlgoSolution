class Solution {
public:
  int differenceOfSum(vector<int>& nums) {
    int ret = 0;
    for (int i : nums) {
      ret += i;
      while (i > 0) {
        ret -= i % 10;
        i /= 10;
      }
    }
    return ret;
  }
};
