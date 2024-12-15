class Solution {
public:
  int makeStringGood(string s) {
    vector<int> c(26, 0);
    for (char ch : s) {
      ++c[ch - 'a'];
    }
    const int total = s.length();
    int ret = total;
    for (int i = 0; i <= total; ++i) {
      int pre1 = 0, pre2 = 0;
      for (int ch = 0; ch < 26; ++ch) {
        int cur = pre1 + min(abs(c[ch] - i), c[ch]);
        if (ch > 0) {
          int d = i - c[ch];
          if (d > 0) {
            cur = min(cur, pre2 + c[ch - 1] + max(0, d - c[ch - 1]));
            d = min(d, c[ch - 1] - i);
            if (d > 0) {
              cur = min(cur, pre2 + c[ch - 1] - c[ch] - d);
            }
          }
        }
        pre2 = pre1;
        pre1 = cur;
      }
      ret = min(ret, pre1);
    }
    return ret;
  }
};
