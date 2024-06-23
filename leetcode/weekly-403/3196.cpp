class Solution {
public:
  long long maximumTotalCost(vector<int>& nums) {
    const int n = nums.size();
    long long pre2 = 0, pre1 = nums.front();
    for (int i = 1; i < n; ++i) {
      long long cur = max(pre1 + nums[i], pre2 + nums[i - 1] - nums[i]);
      pre2 = pre1;
      pre1 = cur;
    }
    return pre1;
  }
};
