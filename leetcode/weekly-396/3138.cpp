class Solution {
public:
  int minAnagramLength(string s) {
    const int n = (int)s.length();
    vector<vector<int>> c(n + 1);
    c[0] = vector<int>(26, 0);
    for (int i = 0; i < n; ++i) {
      c[i + 1] = c[i];
      ++c[i + 1][s[i] - 'a'];
    }
    for (int k = 1; k < n; ++k) {
      if (n % k != 0) {
        continue;
      }
      const int m = n / k;
      auto d = c.back();
      bool ok = true;
      for (int i = 0; i < 26; ++i) {
        if (d[i] % m == 0) {
          d[i] /= m;
        }
        else {
          ok = false;
          break;
        }
      }
      for (int i = k; ok && i < n; i += k) {
        for (int j = 0; j < 26; ++j) {
          if (c[i][j] - c[i - k][j] != d[j]) {
            ok = false;
            break;
          }
        }
        }
      if (ok) {
        return k;
      }
    }
    return n;
  }
};
