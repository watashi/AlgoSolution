class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
    const int64_t n = (int)nums.size();
    const auto mm = minmax_element(nums.begin(), nums.end());
    int64_t s = *mm.second * n - accumulate(nums.begin(), nums.end(), 0LL);
    int64_t ret = s * cost1;
    if (n > 2) {
      int64_t t = *mm.second - *mm.first;
      for (int extra = 0; extra < 2; s += n, ++t) {
        if (s - t < t) {
          ret = min(ret, (s - t) * cost2 + (t + t - s) * cost1);
        }
        else {
          ret = min(ret, s / 2 * cost2 + s % 2 * cost1);
          ++extra;
        }
      }
    }
    return (int)(ret % MOD);
  }
};
