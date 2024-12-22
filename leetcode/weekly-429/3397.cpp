class Solution {
public:
  int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int pre = nums.front() - k;
    int ret = 0;
    for (int i : nums) {
      pre = max(pre, i - k);
      if (pre <= i + k) {
        ++pre;
        ++ret;
      }
    }
    return ret;
  }
};
