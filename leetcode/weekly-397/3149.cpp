class Solution {
public:
  static constexpr int INF = 1000000007;

  vector<int> findPermutation(vector<int>& nums) {
    const int n = nums.size();
    const int m = 1 << n;
    vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, make_pair(INF, 0)));
    for (int i = 1; i < n; ++i) {
      dp[1LL << i][i] = make_pair(abs(i - nums[0]), -1);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][j].first == INF) {
          continue;
        }
        for (int k = 0; k < n; ++k) {
          const int ii = i | (1 << k);
          if (ii == i) {
            continue;
          }
          dp[ii][k] = min(dp[ii][k], make_pair(dp[i][j].first + abs(k - nums[j]), j));
        }
      }
    }
    vector<int> ret;
    for (auto i = make_pair(m - 1, 0); i.first > 0; ) {
      ret.push_back(i.second);
      auto tmp = dp[i.first][i.second].second;
      i.first ^= 1 << i.second;
      i.second = tmp;
    }
    return ret;
  }
};
