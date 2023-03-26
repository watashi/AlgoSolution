class Solution {
public:
  vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    vector<long long> a(nums.begin(), nums.end());
    sort(a.begin(), a.end());
    int n = a.size();
    vector<long long> s(n + 1, 0);
    partial_sum(a.begin(), a.end(), s.begin() + 1);
    vector<long long> ret;
    for (long long q : queries) {
      long long k = lower_bound(a.begin(), a.end(), q) - a.begin();
      ret.push_back(k * q - s[k] + s[n] - s[k] - (n - k) * q);
    }
    return ret;
  }
};
