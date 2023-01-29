class Solution {
public:
  int monkeyMove(int n) {
    static constexpr int64_t MOD = 1000000007;
    int64_t a = 2, b = n, c = 1;
    while (b > 0) {
      if (b % 2 != 0) {
        c = c * a % MOD;
      }
      a = a * a % MOD;
      b /= 2;
    }
    c += MOD - 2;
    c %= MOD;
    return c;
  }
};
