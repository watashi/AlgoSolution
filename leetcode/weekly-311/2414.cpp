class Solution {
public:
  int longestContinuousSubstring(string s) {
    int ret = 1;
    int cur = 1;
    for (int i = 1; i < (int)s.length(); ++i) {
      if (s[i] == s[i - 1] + 1) {
        ++cur;
      }
      else {
        cur = 1;
      }
      ret = max(ret, cur);
    }
    return ret;
  }
};
