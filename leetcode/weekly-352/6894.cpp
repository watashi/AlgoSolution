class Solution {
public:
  int sumImbalanceNumbers(vector<int>& a) {
    int n = a.size();
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      int r = i + 1;
      while (r < n && a[r] != a[i] && a[r] != a[i] + 1) {
        ++r;
      }
      int l = i - 1;
      while (l >= 0 && a[l] != a[i] + 1) {
        --l;
      }
      ret += (r - i) * (i - l);
    }
    ret -= (n + 1) * n / 2;
    return ret;
  }
};
