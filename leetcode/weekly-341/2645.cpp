class Solution {
public:
  inline char next(char c) {
    return c == 'c' ? 'a' : c + 1;
  }

  int addMinimum(string word) {
    int ret = 0;
    char e = 'a';
    word += 'a';
    for (char c : word) {
      while (e != c) {
        ++ret;
        e = next(e);
      }
      e = next(e);
    }
    return ret;
  }
};
