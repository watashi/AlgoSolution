class Solution {
public:
  long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
    int n = nums.size();
    // SHITTY PROBLEM DESCRIPTION without clarification for **median**
    int m = n / 2;
    auto a = nums;
    sort(a.begin(), a.end());
    long long s = abs(a[m] - k);
    for (int i = 0; i < m; ++i) {
      s += max(0, a[i] - k);
    }
    for (int i = m + 1; i < n; ++i) {
      s += max(0, k - a[i]);
    }
    return s;
  }
};
