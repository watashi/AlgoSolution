class Solution {
public:
  int findNonMinOrMax(vector<int>& nums) {
    auto mm = minmax_element(nums.begin(), nums.end());
    for (int i : nums) {
      if (i != *mm.first && i != *mm.second) {
        return i;
      }
    }
    return -1;
  }
};
