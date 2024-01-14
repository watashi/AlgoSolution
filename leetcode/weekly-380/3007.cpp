class Solution {
public:
  static const int MAXB = 52;

  // [0, n)
  static long long total(long long n, int x) {
    long long ret = 0, pre = 0;
    for (int i = MAXB - 1; i >= 0; --i) {
      if (((n >> i) & 1) == 0) {
        continue;
      }
      ret += pre << i;
      if (i > 0) {
        ret += (1LL * i / x) << (i - 1);
      }
      if ((i + 1) % x == 0) {
        ++pre;
      }
      // cout << "\t" << i << " " << ret << endl;
    }
    return ret;
  }

  long long findMaximumNumber(long long k, int x) {
    long long lo = 0, hi = 1LL << MAXB;
    while (lo < hi) {
      auto mi = (lo + hi) / 2;
      // cout << mi << " " << total(mi, x) << endl;
      if (total(mi, x) <= k) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi - 2;
  }
};
