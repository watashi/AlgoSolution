class Solution {
public:
  double minimumAverage(vector<int>& nums) {
    auto v = nums;
    sort(v.begin(), v.end());
    auto ret = v.front() + v.back();
    for (int i = 0, j = (int)v.size() - 1; i < j; ++i, --j) {
      ret = min(ret, v[i] + v[j]);
    }
    return ret / 2.0;
  }
};
