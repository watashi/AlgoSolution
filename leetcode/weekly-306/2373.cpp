class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& a) {
    int n = a.size();
    vector<vector<int>> ret(n - 2, vector<int>(n - 2, 0));
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        auto& k = ret[i - 1][j - 1];
        k = a[i][j];
        for (int ii = i - 1; ii <= i + 1; ++ii) {
          for (int jj = j - 1; jj <= j + 1; ++jj) {
            k = max(k, a[ii][jj]);
          }
        }
      }
    }
    return ret;
  }
};
