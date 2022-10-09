class Solution {
public:
  int hardestWorker(int n, vector<vector<int>>& v) {
    pair<int, int> ret(-1, -1);
    int s = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      int t = v[i][1] - s;
      ret = max(ret, make_pair(t, -v[i][0]));
      s += t;
    }
    return -ret.second;
  }
};
