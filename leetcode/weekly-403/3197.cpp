class Solution {
public:
  struct Rect {
    int r1, c1, r2, c2;

    void upd(const Rect& rect) {
      if (rect.r1 < 0) {
      } else if (r1 < 0) {
        *this = rect;
      }
      else {
        r1 = min(r1, rect.r1);
        r2 = max(r2, rect.r2);
        c1 = min(c1, rect.c1);
        c2 = max(c2, rect.c2);
      }
    }

    int size() const {
      if (r1 < 0) {
        return 1;
      }
      else {
        return (r2 - r1 + 1) * (c2 - c1 + 1);
      }
    }
  };

  static int gao(const vector<vector<int>>& g) {
    const int R = g.size(), C = g[0].size();
    if (R <= 0 || C <= 0) {
      return 0;
    }

    static Rect rect[31][31][31][31];
    fill(rect[0][0][0], rect[R][0][0], Rect{ -1, -1, -1, -1 });
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        auto p = rect[i][j];
        for (int ii = i; ii < R; ++ii) {
          for (int jj = j; jj < C; ++jj) {
            if (ii > i) {
              p[ii][jj].upd(p[ii - 1][jj]);
            }
            if (jj > j) {
              p[ii][jj].upd(p[ii][jj - 1]);
            }
            if (g[ii][jj] == 1) {
              p[ii][jj].upd(Rect{ ii, jj, ii, jj });
            }
          }
        }
      }
    }

    int ret = R * C;
    for (int i = 1; i < R; ++i) {
      const int up = rect[0][0][i - 1][C - 1].size();
      for (int j = 1; j < C; ++j) {
        ret = min(ret, up + rect[i][0][R - 1][j - 1].size() + rect[i][j][R - 1][C - 1].size());
      }
      const int down = rect[i][0][R - 1][C - 1].size();
      for (int j = 1; j < C; ++j) {
        ret = min(ret, down + rect[0][0][i - 1][j - 1].size() + rect[0][j][i - 1][C - 1].size());
      }
      for (int ii = i + 1; ii < R; ++ii) {
        ret = min(ret, up + rect[i][0][ii - 1][C - 1].size() + rect[ii][0][R - 1][C - 1].size());
      }
    }
    return ret;
  }

  int minimumSum(vector<vector<int>>& grid) {
    const int R = grid.size(), C = grid[0].size();
    auto ret = gao(grid);
    vector<vector<int>> g(C, vector<int>(R));
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        g[j][i] = grid[i][j];
      }
    }
    return min(ret, gao(g));
  }
};
