
class Solution {
public:
  string finalString(string s) {
    string t;
    for (char c : s) {
      if (c == 'i') {
        reverse(t.begin(), t.end());
      }
      else {
        t += c;
      }
    }
    return t;
  }
};
