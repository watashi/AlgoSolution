class Solution {
  static constexpr int64_t MOD = 1000000007;

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

public:
  int countBalancedPermutations(string num) {
    vector<int64_t> fac(800), inv(800);
    fac[0] = inv[0] = 1;
    for (int i = 1; i < inv.size(); ++i) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = modInv(fac[i], MOD);
    }

    int s = 0;
    vector<int> c(10, 0);
    for (char ch : num) {
      ++c[ch - '0'];
      s += ch - '0';
    }
    if (s % 2 != 0) {
      return 0;
    }

    int n = num.length();
    int m = n / 2;
    s /= 2;
    vector<vector<int64_t>> dp(m + 1, vector<int64_t>(s + 1, 0));
    dp[0][0] = fac[m] * fac[n - m] % MOD;
    for (int x = 0; x < 10; ++x) {
      vector<vector<int64_t>> pre(m + 1, vector<int64_t>(s + 1, 0));
      pre.swap(dp);
      for (int y = 0; y <= c[x]; ++y) { // 80
        for (int i = y; i <= m; ++i) {
          for (int j = x * y; j <= s; ++j) {
            dp[i][j] += pre[i - y][j - x * y] * inv[y] % MOD * inv[c[x] - y] % MOD;
          }
        }
      }
      for (auto& i : dp) {
        for (auto& j : i) {
          j %= MOD;
        }
      }
    }

    return (int)dp[m][s];
  }
};
