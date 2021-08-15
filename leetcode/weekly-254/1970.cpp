struct DisjointSet {
  vector<int> p;

  void init(int n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    p[i] = j;
    return i != j;
  }
};


class Solution {
public:
  static constexpr int dx[] = {1, 0, -1, 0};
  static constexpr int dy[] = {0, 1, 0, -1};

  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    const int top = row * col, bot = top + 1;
    vector<vector<bool>> x(row, vector<bool>(col, false));
    DisjointSet ds;
    ds.init(bot + 1);
    for (int day = row * col - 1; day >= 0; --day) {
      int i = cells[day][0] - 1, j = cells[day][1] - 1;
      x[i][j] = true;
      if (i == 0) {
        ds.setp(j, top);
      }
      if (i == row - 1) {
        ds.setp(i * col + j, bot);
      }
      for (int k = 0; k < 4; ++k) {
        int ii = i + dx[k];
        int jj = j + dy[k];
        if (0 <= ii && ii < row && 0 <= jj && jj < col && x[ii][jj]) {
          ds.setp(i * col + j, ii * col + jj);
        }
      }
      if (ds.getp(top) == ds.getp(bot)) {
        return day;
      }
    }
    return -1;
  }
};
