class Solution {
public:
  int unequalTriplets(vector<int>& nums) {
    map<int, int> m;
    for (int i : nums) {
      ++m[i];
    }
    int n = nums.size();
    int ret = n * (n - 1) * (n - 2) / 6;
    for (const auto& i : m) {
      int c = i.second;
      if (c >= 2) {
        ret -= c * (c - 1) / 2 * (n - c);
        ret -= c * (c - 1) * (c - 2) / 6;
      }
    }
    return ret;
  }
};
