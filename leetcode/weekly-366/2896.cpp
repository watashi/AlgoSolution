
class Solution {
public:
  int minOperations(string s1, string s2, int x) {
    vector<int> v;
    for (int i = 0; i < (int)s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        v.push_back(i);
      }
    }
    int n = v.size();
    if (n == 0) {
      return 0;
    }
    else if (n % 2 != 0) {
      return -1;
    }
    vector<int> dp(n + 1, n * x + 100);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
      int cost = min(x, v[i - 1] - v[i - 2]);
      if (i % 2 == 0) {
        dp[i] = min(dp[i - 1] + x, dp[i - 2] + cost);
      }
      else {
        dp[i] = min(dp[i - 1], dp[i - 2] + cost);
      }
    }
    return dp[n];
  }
};
