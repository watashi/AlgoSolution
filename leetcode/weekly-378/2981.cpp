class Solution {
public:
  int maximumLength(string s) {
    int n = s.length();
    vector<vector<int>> v(26, vector<int>(n + 1, 0));
    for (int i = 1, c = 1; i <= n; ++i) {
      if (i < n && s[i] == s[i - 1]) {
        ++c;
        continue;
      }
      auto& w = v[s[i - 1] - 'a'];
      for (int j = 1; j <= c; ++j) {
        w[j] += c + 1 - j;
      }
      c = 1;
    }
    int ret = -1;
    for (const auto& w : v) {
      for (int i = 1; i < (int)w.size(); ++i) {
        if (w[i] >= 3) {
          ret = max(ret, i);
        }
      }
    }
    return ret;
  }
};
