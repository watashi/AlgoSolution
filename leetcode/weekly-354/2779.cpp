class Solution {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    vector<int> v = nums;
    sort(v.begin(), v.end());
    int ret = 0;
    for (int i = 0, j = 0; i < (int)v.size(); ++i) {
      while (j < (int)v.size() && v[j] - v[i] <= 2 * k) {
        ++j;
      }
      ret = max(ret, j - i);
    }
    return ret;
  }
};
