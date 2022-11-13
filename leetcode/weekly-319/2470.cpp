class Solution {
public:
  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  int subarrayLCM(vector<int>& nums, int k) {
    int n = nums.size();
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      int lcm = 1;
      for (int j = i; j < n && lcm <= k && k % lcm == 0; ++j) {
        lcm = lcm / gcd(lcm, nums[j]) * nums[j];
        if (lcm == k) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
