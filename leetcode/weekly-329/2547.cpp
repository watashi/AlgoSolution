class Solution {
public:
  int minCost(vector<int>& a, int k) {
    int n = a.size();
    vector<int> dp(n + 1, k + n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      unordered_map<int, int> m;
      int d = k;
      for (int j = i; j < n; ++j) {
        int c = ++m[a[j]];
        if (c == 2) {
          d += 2;
        }
        else if (c > 2) {
          ++d;
        }
        dp[j + 1] = min(dp[j + 1], dp[i] + d);
      }
    }
    return dp[n];
  }
};
