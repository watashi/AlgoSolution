class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  static int64_t powMod(int64_t a, int64_t b) {
    int64_t ret = 1;
    while (b > 0) {
      if ((b & 1) != 0) {
        ret *= a;
        ret %= MOD;
      }
      b >>= 1;
      a *= a;
      a %= MOD;
    }
    return ret;
  }

  int minNonZeroProduct(int p) {
    if (p == 1) {
      return 1;
    }
    int64_t x = (powMod(2, p) + MOD - 2) % MOD, y = 1;
    for (int i = 1; i < p; ++i) {
      y = y * x % MOD;
      x = x * x % MOD;
    }
    y = y * (powMod(2, p) + MOD - 1) % MOD;
    return (int)y;
  }
};
