class Solution {
public:
  int maxOperations(string s) {
    s += '1';
    int total = 0, count = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
      if (s[i] == '1') {
        if (i > 0 && s[i - 1] == '0') {
          total += count;
        }
        ++count;
      }
    }
    return total;
  }
};
