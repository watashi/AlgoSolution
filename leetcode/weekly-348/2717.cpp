class Solution {
public:
  int semiOrderedPermutation(vector<int>& nums) {
    auto mm = minmax_element(nums.begin(), nums.end());
    int n = nums.size();
    int x = mm.first - nums.begin();
    int y = mm.second - nums.begin();
    int ret = 0;
    if (x > y) {
      ret += 2 * (x - y) - 1;
      swap(x, y);
    }
    ret += x;
    ret += (n - 1) - y;
    return ret;
  }
};
