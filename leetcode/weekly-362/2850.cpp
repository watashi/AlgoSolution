class Solution {
public:
  int minimumMoves(vector<vector<int>>& grid) {
    vector<pair<int, int>> from, to;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (grid[i][j] == 0) {
          to.emplace_back(i, j);
        }
        else {
          for (int k = 1; k < grid[i][j]; ++k) {
            from.emplace_back(i, j);
          }
        }
      }
    }

    int ret = 1000;
    do {
      int tmp = 0;
      for (int i = 0; i < (int)to.size(); ++i) {
        tmp += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
      }
      ret = min(ret, tmp);
    } while (next_permutation(to.begin(), to.end()));
    return ret;
  }
};
