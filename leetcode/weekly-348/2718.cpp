class Solution {
public:
  long long matrixSumQueries(int n, vector<vector<int>>& queries) {
    vector<bool> r(n, true), c(n, true);
    int64_t nr = n, nc = n;
    int64_t ret = 0;
    for (auto it = queries.crbegin(); it != queries.crend(); ++it) {
      int t = (*it)[0], i = (*it)[1], v = (*it)[2];
      if (t == 0) {
        if (r[i]) {
          r[i] = false;
          --nr;
          ret += v * nc;
        }
      }
      else {
        if (c[i]) {
          c[i] = false;
          --nc;
          ret += v * nr;
        }
      }
    }
    return ret;
  }
};
