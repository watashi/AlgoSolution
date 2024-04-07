class Solution {
public:
  int gao(const vector<int>& v) {
    if (v.empty()) {
      return 0;
    }
    int ret = 1;
    for (int i = 1, tmp = 1; i < (int)v.size(); ++i) {
      if (v[i] > v[i - 1]) {
        ++tmp;
      }
      else {
        tmp = 1;
      }
      ret = max(ret, tmp);
    }
    return ret;
  }

  int longestMonotonicSubarray(vector<int>& nums) {
    int ret = gao(nums);
    for (int& i : nums) {
      i = -i;
    }
    ret = max(ret, gao(nums));
    return ret;
  }
};
