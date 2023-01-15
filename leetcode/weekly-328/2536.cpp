class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> x(n, vector<int>(n, 0));
    for (const auto& q : queries) {
      int r1 = q[0], c1 = q[1], r2 = q[2] + 1, c2 = q[3] + 1;
      x[r1][c1] += 1;
      if (c2 < n) {
        x[r1][c2] -= 1;
      }
      if (r2 < n) {
        x[r2][c1] -= 1;
        if (c2 < n) {
          x[r2][c2] += 1;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        x[i][j] += x[i][j - 1];
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        x[i][j] += x[i - 1][j];
      }
    }
    return x;
  }
};
