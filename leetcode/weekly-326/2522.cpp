class Solution {
public:
  int minimumPartition(string s, int k) {
    int n = s.length();
    vector<int> dp(n + 1, n + 1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      int64_t t = 0;
      for (int j = i; j < n; ++j) {
        t = t * 10 + (s[j] - '0');
        if (t > k) {
          break;
        }
        else {
          dp[i] = min(dp[i], dp[j + 1] + 1);
        }
      }
    }
    return dp[0] > n ? -1 : dp[0];
  }
};
