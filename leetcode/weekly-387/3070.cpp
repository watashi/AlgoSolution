class Solution {
public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int k1 = k + 1;
    int ret = 0;
    auto g = grid;
    for (int i = 0; i < (int)g.size(); ++i) {
      for (int j = 1; j < (int)g[i].size(); ++j) {
        g[i][j] = min(k1, g[i][j - 1] + g[i][j]);
      }
      for (int j = 0; j < (int)g[i].size(); ++j) {
        g[i][j] = min(k1, (i == 0 ? 0 : g[i - 1][j]) + g[i][j]);
        if (g[i][j] <= k) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
