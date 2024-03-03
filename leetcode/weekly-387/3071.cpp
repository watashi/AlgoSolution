class Solution {
public:
  int minimumOperationsToWriteY(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> x(3, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ++x[g[i][j]];
      }
    }
    int m = n / 2;
    vector<int> y(3, 0);
    ++y[g[m][m]];
    for (int i = 0; i < m; ++i) {
      ++y[g[i][i]];
      ++y[g[i][n - 1 - i]];
      ++y[g[m + 1 + i][m]];
    }

    int sx = 0, sy = 0;
    for (int i = 0; i < 3; ++i) {
      x[i] -= y[i];
      sx += x[i];
      sy += y[i];
    }

    int ret = n * n + 1;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i != j) {
          ret = min(ret, sx - x[i] + sy - y[j]);
        }
      }
    }
    return ret;
  }
};
