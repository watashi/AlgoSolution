class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> e;
    e.resize(n);
    for (int i = 1; i < n; ++i) {
      e[i].push_back(i - 1);
    }
    vector<int> ret;
    for (const auto& q : queries) {
      e[q[1]].push_back(q[0]);
      vector<int> dp(n, n);
      dp[0] = 0;
      for (int i = 1; i < n; ++i) {
        for (int j : e[i]) {
          dp[i] = min(dp[i], dp[j]);
        }
        ++dp[i];
      }
      ret.push_back(dp.back());
    }
    return ret;
  }
};
