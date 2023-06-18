class Solution {
public:
  static constexpr int INF = 1000000007;

  int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      int c = cost[i], t = min(n, time[i] + 1);
      for (int j = n; j >= 1; --j) {
        if (j >= t) {
          dp[j] = min(dp[j], dp[j - t] + c);
        }
        dp[j - 1] = min(dp[j - 1], dp[j]);
      }
    }
    return dp.back();
  }
};
