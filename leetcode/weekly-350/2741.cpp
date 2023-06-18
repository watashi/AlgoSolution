class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int specialPerm(vector<int>& a) {
    int n = (int)a.size();
    vector<basic_string<bool>> d(n, basic_string<bool>(n, false));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && (a[i] % a[j] == 0 || a[j] % a[i] == 0)) {
          d[i][j] = true;
        }
      }
    }

    vector<vector<int64_t>> dp(n, vector<int64_t>(1 << n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][1 << i] = 1;
    }

    vector<int> v;
    v.reserve(n);
    for (int i = 1; i < (1 << n); ++i) {
      v.clear();
      for (int j = 0; j < n; ++j) {
        if ((i & (1 << j)) != 0) {
          v.push_back(j);
        }
      }
      for (int j: v) {
        int ii = i ^ (1 << j);
        for (int k: v) {
          if (d[j][k]) {
            dp[j][i] += dp[k][ii];
          }
        }
        dp[j][i] %= MOD;
      }
    }

    int64_t ret = 0;
    for (int j = 0; j < n; ++j) {
      ret += dp[j].back();
    }
    return ret % MOD;
  }
};
