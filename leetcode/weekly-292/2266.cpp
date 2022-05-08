class Solution {
public:
  int countTexts(string s) {
    static constexpr int64_t MOD = 1000000007;
    int n = s.length();
    vector<int64_t> dp3(n + 1, 0), dp4(n + 1, 0);
    dp3[0] = dp4[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 3 && j <= i; ++j) {
        dp3[i] += dp3[i - j];
        dp4[i] += dp4[i - j];
      }
      if (i >= 4) {
        dp4[i] += dp4[i - 4];
      }
      dp3[i] %= MOD;
      dp4[i] %= MOD;
    }
    int64_t ret = 1;
    for (int i = 0, j = 0; i < n; i = j) {
      j = i;
      while (j < n && s[j] == s[i]) {
        ++j;
      }
      if (s[i] == '7' || s[i] == '9') {
        ret *= dp4[j - i];
      }
      else {
        ret *= dp3[j - i];
      }
      ret %= MOD;
    }
    return ret;
  }
};
