class Solution {
public:
  string getSmallestString(string s) {
    for (int i = 1; i < (int)s.length(); ++i) {
      if (s[i - 1] > s[i] && (s[i - 1] ^ s[i]) % 2 == 0) {
        swap(s[i - 1], s[i]);
        return s;
      }
    }
    return s;
  }
};

