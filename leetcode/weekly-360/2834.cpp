class Solution {
public:
  long long minimumPossibleSum(int nn, int target) {
    long long s = 0;
    long long n = nn;
    long long t = target / 2;
    if (n <= t) {
      s += (1 + n) * n / 2;
    }
    else {
      s += (1 + t) * t / 2;
      n -= t;
      s += (target + target + n - 1) * n / 2;
    }
    return s;
  }
};
