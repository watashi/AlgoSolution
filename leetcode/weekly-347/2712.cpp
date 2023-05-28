class Solution {
public:
  long long minimumCost(string s) {
    int n = s.size();
    vector<long long> pre[2], suf[2];
    for (int i = 0; i < 2; ++i) {
      pre[i] = suf[i] = vector<long long>(n + 1, (long long)n * n * 2);
    }
    pre[0][0] = pre[1][0] = suf[0][n] = suf[1][n] = 0;
    for (int i = 0; i < n; ++i) {
      int x = s[i] == '0' ? 0 : 1;
      pre[x][i + 1] = min(pre[x][i], pre[1 - x][i] + i);
      pre[1 - x][i + 1] = pre[x][i + 1] + (i + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
      int x = s[i] == '0' ? 0 : 1;
      suf[x][i] = min(suf[x][i + 1], suf[1 - x][i + 1] + (n - 1 - i));
      suf[1 - x][i] = suf[1 - x][i] + (n - i);
    }
    long long ret = numeric_limits<long long>::max();
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j <= n; ++j) {
        ret = min(ret, pre[i][j] + suf[i][j]);
      }
    }
    return ret;
  }
};
