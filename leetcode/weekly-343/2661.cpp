class Solution {
public:
  int firstCompleteIndex(vector<int>& v, vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<pair<int, int>> w(n * m + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        w[a[i][j]] = make_pair(i, j);
      }
    }
    vector<int> r(n, 0), c(m, 0);
    for (int i = 0; i < (int)v.size(); ++i) {
      int x, y;
      tie(x, y) = w[v[i]];
      if (++r[x] == m) {
        return i;
      }
      if (++c[y] == n) {
        return i;
      }
    }
    return -1;
  }
};
