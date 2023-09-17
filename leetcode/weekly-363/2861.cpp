class Solution {
public:
  static int gao(int n, int m, const vector<int>& u, const vector<int>& s, const vector<int>& c) {
    int64_t lo = 0, hi = 1000000007;
    while (lo < hi) {
      int64_t mi = (lo + hi) / 2;
      int64_t rest = m;
      for (int i = 0; i < n && rest >= 0; ++i) {
        rest -= max<int64_t>(0LL, (u[i] * mi - s[i]) * c[i]);
      }
      if (rest >= 0) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi - 1;
  }

  int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
    int ret = 0;
    for (int i = 0; i < k; ++i) {
      ret = max(ret, gao(n, budget, composition[i], stock, cost));
    }
    return ret;
  }
};
