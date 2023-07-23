class Solution {
public:
  int maxIncreasingGroups(vector<int>& x) {
    int n = x.size();
    vector<int> c(n + 2, 0);
    for (int i: x) {
      ++c[min(n, i)];
    }
    for (int i = n - 1; i >= 0; --i) {
      c[i] += c[i + 1];
    }
    int lo = 1, hi = c[0] + 1;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      long long extra = 0;
      for (int i = mi, j = 1; i >= 1 && extra >= 0; --i, ++j) {
        extra += c[j] - i;
      }
      if (extra >= 0) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi - 1;
  }
};
