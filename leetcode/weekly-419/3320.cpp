class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  int countWinningSequences(string s) {
    static constexpr char fwe[] = "FWE";
    const int n = s.length();
    vector<array<int64_t, 3>> dp(n * 2 + 1, { 0, 0, 0 });
    fill(dp[n].begin(), dp[n].end(), (MOD + 1) / 2);
    for (int i = 0; i < n; ++i) {
      const int alice = find(fwe, fwe + 3, s[i]) - fwe;
      vector<array<int64_t, 3>> pre(n * 2 + 1, { 0, 0, 0 });
      pre.swap(dp);
      for (int j = 0; j < 3; ++j) {
        const int j1 = (j + 1) % 3;
        const int j2 = (j + 2) % 3;
        const int win = j2 == alice ? 1 : (j1 == alice ? -1 : 0);
        for (int k = 0; k <= n + n; ++k) {
          if (0 <= k + win && k + win <= n + n) {
            dp[k + win][j] += pre[k][j1] + pre[k][j2];
            dp[k + win][j] %= MOD;
          }
        }
      }
    }
    int64_t ret = 0;
    for (int i = n + 1; i <= n + n; ++i) {
      for (int j = 0; j < 3; ++j) {
        ret += dp[i][j];
      }
    }
    return (int)(ret % MOD);
  }
};
