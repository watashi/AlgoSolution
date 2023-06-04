class Solution {
public:
  static constexpr int64_t MOD = 1000000007;
  static constexpr int MAXD = 30;
  static constexpr int MAXS = MAXD * 11;
  vector<vector<int64_t>> dp;

  Solution(): dp(MAXD, vector<int64_t>(MAXS)) {
    dp[0][0] = 1;
    for (int i = 1; i < MAXD; ++i) {
      for (int j = 0; j < MAXS; ++j) {
        for (int k = max(0, j - 9); k <= j; ++k) {
          dp[i][j] += dp[i - 1][k];
        }
        dp[i][j] %= MOD;
      }
    }
    for (int i = 0; i < MAXD; ++i) {
      for (int j = 1; j < MAXS; ++j) {
        dp[i][j] += dp[i][j - 1];
        dp[i][j] %= MOD;
      }
    }
  }

  // < n, < s
  int64_t count(string x, int s) {
    int64_t ret = 0;
    int n = x.size();
    for (int i = 0; i < n && s > 0; ++i) {
      int k = x[i] - '0';
      for (int j = 0; j < k && j < s; ++j) {
        ret += dp[n - i - 1][s - j - 1];
      }
      s -= k;
    }
    // cout << x << " " << s << ": " << ret << endl;
    return ret % MOD;
  }

  string inc(string s) {
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      if (*it == '9') {
        *it = '0';
      }
      else {
        ++*it;
        return s;
      }
    }
    return "1" + s;
  }

  int count(string num1, string num2, int min_sum, int max_sum) {
    num2 = inc(num2);
    max_sum = min(max_sum + 1, MAXS);
    if (min_sum >= max_sum) {
      return 0;
    }
    int64_t ret = 0;
    ret += count(num2, max_sum) - count(num2, min_sum);
    ret -= count(num1, max_sum) - count(num1, min_sum);
    ret = (ret % MOD + MOD) % MOD;
    return ret;
  }
};
