class Solution {
public:
  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  int countBeautifulPairs(vector<int>& a) {
    vector<int> first(10, 0), last(10, 0);
    int n = a.size();
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      int ii = a[i];
      while (ii >= 10) {
        ii /= 10;
      }
      for (int j = i + 1; j < n; ++j) {
        int jj = a[j] % 10;
        if (gcd(ii, jj) == 1) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
