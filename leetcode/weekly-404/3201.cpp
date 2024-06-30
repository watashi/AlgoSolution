
class Solution {
public:
  static int gao(const vector<int> v, int cur, int next) {
    int ret = 0;
    for (int i : v) {
      if (i == cur) {
        ++ret;
        swap(cur, next);
      }
    }
    return ret;
  }

  int maximumLength(vector<int>& nums) {
    int ret = 0;
    vector<int> v = nums;
    for (int& i : v) {
      i %= 2;
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        ret = max(ret, gao(v, i, j));
      }
    }
    return ret;
  }
};
