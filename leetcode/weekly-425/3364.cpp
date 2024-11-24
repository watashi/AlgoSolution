class Solution {
public:
  int minimumSumSubarray(vector<int>& a, int l, int r) {
    const int n = a.size();
    int ret = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      int s = 0;
      for (int j = i; j < n && j < i + r; ++j) {
        s += a[j];
        if (s > 0 && j >= i + l - 1) {
          ret = min(ret, s);
        }
      }
    }
    if (ret == numeric_limits<int>::max()) {
      ret = -1;
    }
    return ret;
  }
};
