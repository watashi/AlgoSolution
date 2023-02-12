
class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    vector<int> v(nums.begin(), nums.end());
    sort(v.begin(), v.end());
    int64_t ret = 0;
    for (int i : v) {
      auto lo = lower_bound(v.begin(), v.end(), lower - i);
      auto hi = upper_bound(v.begin(), v.end(), upper - i);
      ret += hi - lo;
      if (lower <= i + i && i + i <= upper) {
        --ret;
      }
    }
    return ret / 2;
  }
};
