class Solution {
public:
  static vector<int> eraseRange(set<int>& st, int from, int to) {
    vector<int> ret;
    auto it = st.lower_bound(from);
    while (it != st.end() && *it <= to) {
      ret.push_back(*it);
      it = st.erase(it);
    }
    return ret;
  }

  int minimumVisitedCells(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> d(m, vector<int>(n, -1));
    vector<set<int>> xy(m), yx(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        xy[i].insert(j);
        yx[j].insert(i);
      }
    }
    queue<pair<int, int>> q;
    d[0][0] = 1;
    q.emplace(0, 0);
    while (!q.empty()) {
      int x, y, z;
      tie(x, y) = q.front();
      q.pop();
      z = d[x][y];
      for (int xx : eraseRange(yx[y], x, x + grid[x][y])) {
        if (d[xx][y] == -1) {
          d[xx][y] = z + 1;
          q.emplace(xx, y);
        }
      }
      for (int yy : eraseRange(xy[x], y, y + grid[x][y])) {
        if (d[x][yy] == -1) {
          d[x][yy] = z + 1;
          q.emplace(x, yy);
        }
      }
    }
    return d.back().back();
  }
};
