class Solution {
public:
  int maxSum(vector<vector<int>>& a) {
    int ret = 0;
    for (int i = 1; i + 1 < (int)a.size(); ++i) {
      for (int j = 1; j + 1 < (int)a[i].size(); ++j) {
        int tmp = 0;
        tmp -= a[i][j - 1];
        tmp -= a[i][j + 1];
        for (int ii = i - 1; ii <= i + 1; ++ii) {
          for (int jj = j - 1; jj <= j + 1; ++jj) {
            tmp += a[ii][jj];
          }
        }
        ret = max(ret, tmp);
      }
    }
    return ret;
  }
};
