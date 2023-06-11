class Solution {
public:
  long long minCost(vector<int>& nums, int x) {
    int n = nums.size();
    vector<long long> a(nums.begin(), nums.end());
    vector<long long> b(nums.begin(), nums.end());
    a.insert(a.end(), nums.begin(), nums.end());
    long long ret = accumulate(b.begin(), b.end(), 0LL);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        b[j] = min(b[j], a[j + i]);
      }
      long long tmp = accumulate(b.begin(), b.end(), 0LL) + 1LL * x * i;
      ret = min(ret, tmp);
    }
    return ret;
  }
};
