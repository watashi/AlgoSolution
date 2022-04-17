class Solution {
public:
  int maxTrailingZeros(vector<vector<int>>& grid) {
    int ret = 0;
    int r = grid.size(), c = grid[0].size();
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        vector<pair<int, int>> v(c, make_pair(0, 0));
        for (int x = 0; x < r; ++x) {
          pair<int, int> w(0, 0);
          for (int y = 0; y < c; ++y) {
            pair<int, int> p(0, 0);
            int z = grid[x][y];
            while (z % 2 == 0) {
              ++p.first;
              z /= 2;
            }
            while (z % 5 == 0) {
              ++p.second;
              z /= 5;
            }
            w.first += p.first;
            w.second += p.second;
            ret = max(ret, min(w.first + v[y].first, w.second + v[y].second));
            v[y].first += p.first;
            v[y].second += p.second;
          }
        }
        for (auto& k : grid) {
          reverse(k.begin(), k.end());
        }
      }
      reverse(grid.begin(), grid.end());
    }
    return ret;
  }
};
