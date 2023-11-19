class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int maximumXorProduct(long long a, long long b, int n) {
    bitset<64> bs(a ^ b);
    long long m = (1LL << n) - 1;
    long long x = a | m;
    long long y = b | m;
    if (x < y) {
      swap(x, y);
    }
    bool eq = x == y;
    for (int i = n - 1; i >= 0; --i) {
      if (bs[i]) {
        if (eq) {
          y ^= 1LL << i;
          eq = false;
        }
        else {
          x ^= 1LL << i;
        }
      }
    }
    return (x % MOD) * (y % MOD) % MOD;
  }
};
