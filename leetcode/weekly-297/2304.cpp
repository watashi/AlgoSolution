class Solution {
public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size(), n = grid[0].size();
    vector<int> cost = grid[0];
    for (int i = 0; i < m - 1; ++i) {
      vector<int> next(n, numeric_limits<int>::max());
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          next[k] = min(next[k], cost[j] + moveCost[grid[i][j]][k]);
        }
      }
      cost = std::move(next);
      for (int j = 0; j < n; ++j) {
        cost[j] += grid[i + 1][j];
      }
    }
    return *min_element(cost.begin(), cost.end());
  }
};
