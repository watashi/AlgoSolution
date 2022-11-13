struct Manacher {
  vector<int> p;

  template<typename T>
  void init(int n, const T s[]) {
    p.resize(max(0, 2 * n - 1));
    for (int i = 0, j = 0, k = 0; i <= 2 * (n - 1); ++i) {
      int d = i < k ? min(p[j + j - i], (k - i) / 2) : 0;
      int a = i / 2 - d, b = (i + 1) / 2 + d;
      while (0 <= a && b < n && s[a] == s[b]) {
        --a;
        ++b;
        ++d;
      }
      p[i] = d;
      if (k < 2 * b - 1) {
        j = i;
        k = 2 * b - 1;
      }
    }
  }

  // [l, r)
  bool test(int l, int r) {
    int m = l + r - 1;
    return m / 2 - p[m] < l;
  }
};


class Solution {
public:
  int maxPalindromes(string s, int k) {
    int n = s.length();
    Manacher m;
    m.init(n, s.data());

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      dp[i] = max(dp[i], dp[i - 1]);
      for (int j = 0; j <= i - k; ++j) {
        if (m.test(j, i)) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return dp.back();
  }
};
