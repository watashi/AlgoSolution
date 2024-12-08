class Solution {
public:
  long long maxSubarraySum(vector<int>& nums, int k) {
    long long ret = numeric_limits<long long>::min();
    long long s = 0;
    vector<long long> pre(k, 0);
    pre[0] = s;
    for (int i = 0; i < k - 1; ++i) {
      s += nums[i];
      pre[i + 1] = s;
    }
    for (int i = k - 1; i < (int)nums.size(); ++i) {
      const int j = (i + 1) % k;
      s += nums[i];
      ret = max(ret, s - pre[j]);
      pre[j] = min(pre[j], s);
    }
    return ret;
  }
};
