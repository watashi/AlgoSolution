class Solution {
public:
  int buttonWithLongestTime(vector<vector<int>>& events) {
    pair<int, int> ret(0, 0);
    int s = 0;
    for (const auto& e : events) {
      int k = e[0], t = e[1];
      int v = s - t;
      s = t;
      ret = min(ret, make_pair(v, k));
    }
    return ret.second;
  }
};
