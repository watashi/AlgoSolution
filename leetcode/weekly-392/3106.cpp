
class Solution {
public:
  string getSmallestString(string s, int k) {
    for (int i = 0; i < (int)s.length(); ++i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        int d = abs((int)c - s[i]);
        d = min(d, 26 - d);
        if (d <= k) {
          k -= d;
          s[i] = c;
          break;
        }
      }
    }
    return s;
  }
};
