class Solution {
public:
  vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
    static constexpr int MAXN = 64;
    int m = g.size(), n = g[0].size();
    vector<vector<int>> ret(m);
    for (int i = 0; i < m; ++i) {
      ret[i].resize(n);
      for (int j = 0; j < n; ++j) {
        bitset<MAXN> tl, br;
        int ii = i - 1, jj = j - 1;
        while (ii >= 0 && jj >= 0) {
          tl.set(g[ii][jj]);
          --ii;
          --jj;
        }
        ii = i + 1;
        jj = j + 1;
        while (ii < m && jj < n) {
          br.set(g[ii][jj]);
          ++ii;
          ++jj;
        }
        ret[i][j] = abs((int)tl.count() - (int)br.count());
      }
    }
    return ret;
  }
};
