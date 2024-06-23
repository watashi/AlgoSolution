
class Solution {
public:
  int minimumArea(vector<vector<int>>& grid) {
    const int R = grid.size(), C = grid[0].size();
    int rmin = R, rmax = 0, cmin = C, cmax = 0;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == 1) {
          rmin = min(rmin, i);
          rmax = max(rmax, i);
          cmin = min(cmin, j);
          cmax = max(cmax, j);
        }
      }
    }
    return (rmax - rmin + 1) * (cmax - cmin + 1);
  }
};
