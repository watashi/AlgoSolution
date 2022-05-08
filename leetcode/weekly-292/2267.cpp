class Solution {
public:
  bool hasValidPath(vector<vector<char>>& g) {
    static constexpr int MAXN = 210;
    if (g[0][0] != '(') {
      return false;
    }
    int r = g.size();
    int c = g[0].size();
    vector<vector<bitset<MAXN>>> dp(r, vector<bitset<MAXN>>(c));
    dp[0][0].set(1);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (i > 0) {
          dp[i][j] |= dp[i - 1][j];
        }
        if (j > 0) {
          dp[i][j] |= dp[i][j - 1];
        }
        if (i > 0 || j > 0) {
          if (g[i][j] == '(') {
            dp[i][j] <<= 1;
          }
          else {
            dp[i][j] >>= 1;
          }
        }
      }
    }
    return dp[r - 1][c - 1].test(0);
  }
};
