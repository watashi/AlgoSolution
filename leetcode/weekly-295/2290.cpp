static const int DX[] = {0, 1, 0, -1};
static const int DY[] = {1, 0, -1, 0};

class Solution {
public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> d(n, vector<int>(m, -1));
    vector<pair<int, int>> v;
    d[0][0] = grid[0][0];
    v.emplace_back(0, 0);
    while (!v.empty()) {
      int x, y, xx, yy;
      vector<pair<int, int>> w;
      while (!v.empty()) {
        tie(x, y) = v.back();
        w.push_back(v.back());
        v.pop_back();
        for (int k = 0; k < 4; ++k) {
          xx = x + DX[k];
          yy = y + DY[k];
          if (0 <= xx && xx < n && 0 <= yy && yy < m && d[xx][yy] == -1 && grid[xx][yy] == 0) {
            d[xx][yy] = d[x][y];
            v.emplace_back(xx, yy);
          }
        }
      }
      for (const auto& i : w) {
        tie(x, y) = i;
        for (int k = 0; k < 4; ++k) {
          xx = x + DX[k];
          yy = y + DY[k];
          if (0 <= xx && xx < n && 0 <= yy && yy < m && d[xx][yy] == -1 && grid[xx][yy] == 1) {
            d[xx][yy] = d[x][y] + 1;
            v.emplace_back(xx, yy);
          }
        }
      }
    }
    return d[n - 1][m - 1];
  }
};
