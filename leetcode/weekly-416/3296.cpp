class Solution {
public:
  static constexpr long long MAXN = 1000000007;

  long long revC2(long long n) {
    long long lo = 0, hi = MAXN;
    while (lo < hi) {
      long long mi = (lo + hi) / 2;
      if (mi * (mi + 1) / 2 <= n) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi - 1;
  }

  long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long lo = 0, hi = MAXN * MAXN;
    while (lo < hi) {
      long long mi = (lo + hi) / 2;
      long long r = mountainHeight;
      for (int i : workerTimes) {
        r -= revC2(mi / i);
        if (r <= 0) {
          break;
        }
      }
      if (r <= 0) {
        hi = mi;
      }
      else {
        lo = mi + 1;
      }
    }
    return hi;
  }
};
