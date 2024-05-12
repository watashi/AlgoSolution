class Solution {
public:
  int maxScore(vector<vector<int>>& grid) {
    vector<vector<int>> g = grid;
    const int r = g.size();
    const int c = g[0].size();
    int ret = g[r - 1][c - 1] - g[0][0];
    for (int i = r - 1; i >= 0; --i) {
      for (int j = c - 1; j >= 0; --j) {
        const int from = g[i][j];
        int to = g[i][j];
        if (i < r - 1) {
          ret = max(ret, g[i + 1][j] - from);
          to = max(to, g[i + 1][j]);
        }
        if (j < c - 1) {
          ret = max(ret, g[i][j + 1] - from);
          to = max(to, g[i][j + 1]);
        }
        g[i][j] = to;
      }
    }
    return ret;
  }
};
