class Solution {
public:
  static constexpr long long MOD = 1000000007;
  
  // a * x + b * y = gcd(a, b) >= 0
  static long long extGcd(long long a, long long b, long long& x, long long& y) {
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
  static long long modInv(long long a, long long m) {
    long long x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
  }

  int numberOfSequence(int n, vector<int>& sick) {
    long long ans = 1;
    vector<int> v;
    v.push_back(sick.front());
    v.push_back(n - 1 - sick.back());
    for (int i = 1; i < (int)sick.size(); ++i) {
      int gap = sick[i] - sick[i - 1] - 1;
      for (int j = 1; j < gap; ++j) {
        ans = ans * 2 % MOD;
      }
      v.push_back(gap);
    }
    int s = 0;
    for (int i : v) {
      // choose(s, i);
      for (int j = 1; j <= i; ++j) {
        ans = ans * (s + j) % MOD;
        ans = ans * modInv(j, MOD) % MOD;
      }
      s += i;
    }
    return ans;
  }
};
