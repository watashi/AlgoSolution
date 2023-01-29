class Solution {
public:
  long long countQuadruplets(vector<int>& a) {
    int n = a.size();
    int64_t ret = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> lt(n + 1, 0);
      for (int j = 0; j < i; ++j) {
        ++lt[a[j]];
      }
      for (int j = 0; j < n; ++j) {
        lt[j + 1] += lt[j];
      }
      int gt = 0;
      for (int j = i + 1; j < n; ++j) {
        if (a[j] > a[i]) {
          ++gt;
        }
      }
      for (int j = i + 1; j < n; ++j) {
        if (a[i] > a[j]) {
          ret += lt[a[j]] * gt;
        }
        else {
          --gt;
        }
      }
    }
    return ret;
  }
};
