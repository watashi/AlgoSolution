class Solution {
public:
  int percentageLetter(string s, char letter) {
    int c = count(s.begin(), s.end(), letter);
    return c * 100 / (int)s.size();
  }
};
