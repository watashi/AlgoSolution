class Solution {
public:
  bool canSplitArray(vector<int>& nums, int m) {
    int n = (int)nums.size();
    if (n <= 2) {
      return true;
    }
    for (int i = 1; i < n; ++i) {
      if (nums[i - 1] + nums[i] >= m) {
        return true;
      }
    }
    return false;
  }
};
