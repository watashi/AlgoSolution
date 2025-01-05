class Solution {
public:
  static int64_t gcd(int64_t a, int64_t b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  static int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
  }

  int maxLength(vector<int>& nums) {
    for (int i = (int)nums.size(); i > 2; --i) {
      for (int j = 0; j + i <= (int)nums.size(); ++j) {
        int gg = nums[j], ll = nums[j], pp = nums[j];
        for (int k = j + 1; k < j + i; ++k) {
          gg = gcd(gg, nums[k]);
          ll = lcm(ll, nums[k]);
          pp = pp * nums[k];
          if (pp != gg * ll) {
            goto NEXT;
          }
        }
        return i;
      NEXT:
        continue;
      }
    }
    return 2;
  }
};
