class neighborSum {
  int sz;
  vector<vector<int>> val;
  vector<pair<int, int>> pos;

  int sumImpl(int value, int d) {
    int ret = 0;
    int x, y;
    tie(x, y) = pos[value];
    for (int i = x - 1; i <= x + 1; ++i) {
      for (int j = y - 1; j <= y + 1; ++j) {
        if (0 <= i && i < sz && 0 <= j && j < sz && abs(i - x) + abs(j - y) == d) {
          ret += val[i][j];
        }
      }
    }
    return ret;
  }

public:
  neighborSum(vector<vector<int>>& grid) {
    sz = grid.size();
    val = grid;
    pos.clear();
    pos.resize(sz * sz);
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        pos[val[i][j]] = make_pair(i, j);
      }
    }
  }

  int adjacentSum(int value) {
    return sumImpl(value, 1);
  }

  int diagonalSum(int value) {
    return sumImpl(value, 2);
  }
};
