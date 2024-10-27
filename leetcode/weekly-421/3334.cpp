class Solution {
public:
  static long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  static long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
  }

  long long maxScore(vector<int>& nums) {
    long long ret = 0;
    for (int i = 0; i <= (int)nums.size(); ++i) {
      long long g = 0, l = 1;
      for (int j = 0; j < (int)nums.size(); ++j) {
        if (j != i) {
          g = gcd(g, nums[j]);
          l = lcm(l, nums[j]);
        }
      }
      ret = max(ret, g * l);
    }
    return ret;
  }
};
