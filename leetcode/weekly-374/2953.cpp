class Solution {
public:
  int countCompleteSubstrings(string word, int k) {
    int n = word.size();
    vector<int> ok(n);
    ok[0] = 0;
    for (int i = 1; i < n; ++i) {
      if (abs(word[i] - word[i - 1]) <= 2) {
        ok[i] = ok[i - 1];
      }
      else {
        ok[i] = i;
      }
    }
    vector<vector<int>> c(n + 1);
    c[0] = vector<int>(26, 0);
    for (int i = 0; i < n; ++i) {
      c[i + 1] = c[i];
      ++c[i + 1][word[i] - 'a'];
    }
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1, ii = i - k; j <= 26 && ii >= ok[i - 1]; ++j, ii -= k) {
        bool valid = true;
        for (int ch = 0; ch < 26 && valid; ++ch) {
          int d = c[i][ch] - c[ii][ch];
          valid = d == 0 || d == k;
        }
        if (valid) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
