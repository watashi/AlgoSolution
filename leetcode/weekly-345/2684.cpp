class Solution {
public:
  int maxMoves(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size();
    unordered_set<int> from;
    for (int i = 0; i < r; ++i) {
      from.insert(i);
    }
    for (int j = 0; j < c - 1; ++j) {
      unordered_set<int> to;
      for (int i : from) {
        for (int ii = i - 1; ii <= i + 1; ++ii) {
          if (0 <= ii && ii < r && grid[ii][j + 1] > grid[i][j]) {
            to.insert(ii);
          }
        }
      }
      if (to.empty()) {
        return j;
      }
      from = move(to);
    }
    return c - 1;
  }
};
