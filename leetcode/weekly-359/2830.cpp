class Solution {
public:
  int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    auto v = offers;
    sort(v.rbegin(), v.rend(), [](const auto& lhs, const auto& rhs) { return lhs[1] < rhs[1]; });
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      dp[i] = max(dp[i], dp[i - 1]);
      while (!v.empty() && v.back()[1] == i - 1) {
        auto start = v.back()[0];
        auto gold = v.back()[2];
        v.pop_back();
        dp[i] = max(dp[i], dp[start] + gold);
      }
    }
    return dp[n];
  }
};
