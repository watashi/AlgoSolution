class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    pair<int, int> ret(0, 0);
    for (const auto& i : dimensions) {
      int x = i[0], y = i[1];
      ret = max(ret, make_pair(x * x + y * y, x * y));
    }
    return ret.second;
  }
};
