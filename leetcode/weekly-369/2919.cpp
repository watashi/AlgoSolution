class Solution {
public:
  long long minIncrementOperations(vector<int>& a, int k) {
    int n = a.size();
    vector<long long> dp(n, 1LL * n * k + 1);
    for (int i = 0; i < 3; ++i) {
      dp[i] = max(0, k - a[i]);
    }
    for (int i = 3; i < n; ++i) {
      dp[i] = min({ dp[i - 1], dp[i - 2], dp[i - 3] }) + max(0, k - a[i]);
    }
    return min({ dp[n - 1], dp[n - 2], dp[n - 3] });
  }
};
