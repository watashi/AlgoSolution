class Solution {
public:
  int solve1(string s, char ch) {
    int ret = 0;
    for (char c : s) {
      if (c != ch) {
        ++ret;
      }
      ch ^= 1;
    }
    return ret;
  }

  int solve2(string s) {
    int dp[2][3], pre[2][3];
    memset(dp, 0, sizeof(dp));
    for (char ch : s) {
      const int orig = ch - '0';
      memcpy(pre, dp, sizeof(dp));
      memset(dp, 0x7f, sizeof(dp));
      for (int i = 0; i < 2; ++i) {
        dp[i][1] = min(pre[i ^ 1][1], pre[i ^ 1][2]) + (i == orig ? 0 : 1);
        dp[i][2] = pre[i][1] + (i == orig ? 0 : 1);
      }
    }
    return min({ dp[0][1], dp[0][2], dp[1][1], dp[1][2] });
  }

  int minLength(string s, int numOps) {
    if (solve1(s, '0') <= numOps || solve1(s, '1') <= numOps) {
      return 1;
    }
    if (solve2(s) <= numOps) {
      return 2;
    }

    const int n = s.length();
    vector<int> v;
    v.push_back(1);
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[i - 1]) {
        ++v.back();
      }
      else {
        v.push_back(1);
      }
    }
    int lo = 3, hi = n + 1;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      int r = numOps;
      for (int i : v) {
        r -= i / mi;
      }
      if (r < 0) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi - 1;
  }
};
