class Solution {
public:
  string findTheString(vector<vector<int>>& lcp) {
    int n = (int)lcp.size();
    string ret(n, ' ');
    char ch = 'a' - 1;
    for (int i = 0; i < n; ++i) {
      if (ret[i] != ' ') {
        continue;
      }
      if (++ch > 'z') {
        return "";
      }
      for (int j = i; j < n; ++j) {
        if (lcp[i][j] > 0) {
          if (ret[j] != ' ') {
            return "";
          }
          ret[j] = ch;
        }
      }
    }
    if (ret.find(' ') != string::npos) {
      return "";
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1][n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      dp[i][n - 1] = ret[i] == ret[n - 1] ? 1 : 0;
      for (int j = n - 2; j >= i; --j) {
        if (ret[i] == ret[j]) {
          dp[i][j] = dp[i + 1][j + 1] + 1;
        }
        else {
          dp[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i][j] = dp[j][i];
      }
    }
    return dp == lcp ? ret : "";
  }
};
