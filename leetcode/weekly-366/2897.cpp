class Solution {
public:
  static constexpr int BITS = 30;
  static constexpr int64_t MOD = 1000000007;

  static inline bool test(int i, int j) {
    return (i >> j) & 1;
  }

  int maxSum(vector<int>& nums, int k) {
    constexpr int BITS = 30;
    vector<int> v(BITS, 0);
    for (int i : nums) {
      for (int j = 0; j < BITS; ++j) {
        if (test(i, j)) {
          ++v[j];
        }
      }
    }
    int64_t ret = 0;
    for (int i = 0; i < k; ++i) {
      int64_t m = 0;
      for (int j = 0; j < BITS; ++j) {
        if (v[j] > i) {
          m |= 1LL << j;
        }
      }
      ret += m * m % MOD;
    }
    return ret % MOD;
  }
};
