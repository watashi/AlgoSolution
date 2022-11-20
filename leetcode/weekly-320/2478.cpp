class Solution {
public:
  bool isPrime(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
  }

  static constexpr int MOD = 1000000007;

  void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
      a -= MOD;
    }
  }

  int beautifulPartitions(string s, int k, int minLength) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = isPrime(s[n - 1]) ? 0 : 1;
    for (int kk = 0; kk < k; ++kk) {
      vector<int> pre(n + 1, 0);
      swap(pre, dp);
      for (int i = n - 1; i >= 0; --i) {
        if (i > 0 && isPrime(s[i - 1])) {
          pre[i] = 0;
        }
        add(pre[i], pre[i + 1]);
      }
      for (int i = 0; i + minLength <= n; ++i) {
        if (isPrime(s[i])) {
          dp[i] = pre[i + minLength];
        }
      }
    }
    return dp[0];
  }
};
