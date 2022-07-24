class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        bool f = true;
        for (int k = 0; k < n; ++k) {
          if (grid[i][k] != grid[k][j]) {
            f = false;
            break;
          }
        }
        if (f) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
