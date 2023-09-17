class Solution {
public:
  int countWays(vector<int>& a) {
    sort(a.begin(), a.end());
    int ret = 0;
    int n = a.size();
    for (int i = 0; i <= n; ++i) {
      if (i == 0 || i > a[i - 1]) {
        if (i == n || i < a[i]) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
