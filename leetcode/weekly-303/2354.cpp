class Solution {
public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    vector<int> v = nums;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> c(40);
    for (int i : v) {
      ++c[__builtin_popcount(i)];
    }
    long long ans = 0;
    for (int i = 0; i < (int)c.size(); ++i) {
      for (int j = 0; j < (int)c.size(); ++j) {
        if (i + j >= k) {
          ans += (long long)c[i] * c[j];
        }
      }
    }
    return ans;
  }
};
