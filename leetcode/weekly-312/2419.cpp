class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int ret = 0;
    const int mask = *max_element(nums.begin(), nums.end());
    auto begin = nums.begin();
    while (begin != nums.end()) {
      auto pos = find(begin, nums.end(), mask);
      if (pos == nums.end()) {
        break;
      }
      auto left = pos;
      while (left != begin && (*(left - 1) & mask) == mask) {
        --left;
      }
      auto right = pos + 1;
      while (right != nums.end() && (*right & mask) == mask) {
        ++right;
      }
      ret = max<int>(ret, right - left);
      begin = right;
    }
    return ret;
  }
};
