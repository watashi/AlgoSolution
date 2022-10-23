class Solution {
public:
  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  int subarrayGCD(vector<int>& nums, int k) {
    int ret = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
      int g = nums[i];
      for (int j = i; j < (int)nums.size() && g % k == 0; ++j) {
        g = gcd(g, nums[j]);
        if (g == k) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
