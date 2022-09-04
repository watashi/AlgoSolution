class Solution {
public:
  // a * x + b * y = gcd(a, b) >= 0
  long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
      x = a >= 0 ? 1 : -1;
      y = 0;
      return abs(a);
    }
    else {
      int g = extGcd(b, a % b, y, x);
      y -= a / b * x;
      return g;
    }
  }

  // ASSUME: gcd(a, m) == 1
  long long modInv(long long a, long long m) {
    long long x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
  }

  long long choose(int n, int k) {
    static constexpr long long MOD = 1000000007;
    long long ret = 1;
    for (int i = 1; i <= k; ++i) {
      ret *= n + 1 - i;
      ret %= MOD;
      ret *= modInv(i, MOD);
      ret %= MOD;
    }
    ret += MOD;
    ret %= MOD;
    return ret;
  }

  int numberOfWays(int startPos, int endPos, int k) {
    int d = abs(endPos - startPos);
    if (k < d || (k - d) % 2 != 0) {
      return 0;
    }
    else {
      return choose(k, (k - d) / 2);
    }
  }
};
