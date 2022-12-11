class Solution {
public:
  int deleteGreatestValue(vector<vector<int>>& grid) {
    for (auto& i : grid) {
      sort(i.begin(), i.end());
    }
    int ret = 0;
    while (!grid[0].empty()) {
      int tmp = grid[0].back();
      for (auto& i : grid) {
        tmp = max(tmp, i.back());
        i.pop_back();
      }
      ret += tmp;
    }
    return ret;
  }
};
