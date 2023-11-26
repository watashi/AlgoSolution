class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    const int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      v.emplace_back(nums[i], i);
    }
    sort(v.begin(), v.end());
    vector<int> ret(n);
    while (!v.empty()) {
      vector<int> idx, val;
      do {
        idx.push_back(v.back().second);
        val.push_back(v.back().first);
        v.pop_back();
      } while (!v.empty() && v.back().first >= val.back() - limit);
      sort(idx.rbegin(), idx.rend());
      for (int i = 0; i < (int)idx.size(); ++i) {
        ret[idx[i]] = val[i];
      }
    }
    return ret;
  }
};
