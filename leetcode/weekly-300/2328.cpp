class Solution {
public:
  int countPaths(vector<vector<int>>& grid) {
    static constexpr int64_t MOD = 1000000007;
    static const int DX[] = { 0, 1, 0, -1 };
    static const int DY[] = { 1, 0, -1, 0 };
    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, pair<int, int>>> cells;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cells.emplace_back(grid[i][j], make_pair(i, j));
      }
    }
    sort(cells.begin(), cells.end());

    vector<vector<int64_t>> dp(m, vector<int64_t>(n, 1));
    int64_t ans = 0;
    for (const auto& cell : cells) {
      int x = cell.second.first;
      int y = cell.second.second;
      for (int i = 0; i < 4; ++i) {
        int xx = x + DX[i];
        int yy = y + DY[i];
        if (0 <= xx && xx < m && 0 <= yy && yy < n && grid[xx][yy] < grid[x][y]) {
          dp[x][y] += dp[xx][yy];
        }
      }
      dp[x][y] %= MOD;
      ans += dp[x][y];
    }
    ans %= MOD;
    return ans;
  }
};
