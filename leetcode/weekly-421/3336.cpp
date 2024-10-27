class Solution {
public:
  static constexpr int MAXN = 201;
  static constexpr int64_t MOD = 1000000007;

  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  int subsequencePairCount(vector<int>& nums) {
    static int g[MAXN][MAXN];
    for (int i = 0; i < MAXN; ++i) {
      for (int j = 0; j < MAXN; ++j) {
        g[i][j] = gcd(i, j);
      }
    }
    static int64_t dp[MAXN][MAXN];
    fill(dp[0], dp[MAXN], 0);
    dp[0][0] = 1;
    for (int x : nums) {
      for (int ii = 1; ii <= MAXN; ++ii) {
        const int i = ii == MAXN ? 0 : ii;
        for (int jj = 1; jj <= MAXN; ++jj) {
          const int j = jj == MAXN ? 0 : jj;
          dp[i][j] %= MOD;
          if (dp[i][j] > 0) {
            const int64_t k = dp[i][j];
            dp[g[i][x]][j] += k;
            dp[i][g[j][x]] += k;
          }
        }
      }
    }

    int64_t ret = 0;
    for (int i = 1; i < MAXN; ++i) {
      ret += dp[i][i];
    }
    ret %= MOD;
    return (int)ret;
  }
};
