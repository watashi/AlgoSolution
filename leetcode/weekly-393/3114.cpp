class Solution {
public:
  string findLatestTime(string s) {
    for (int i = 11; i >= 0; --i) {
      int a = i / 10 + '0', b = i % 10 + '0';
      if ((s[0] == '?' || s[0] == a) && (s[1] == '?' || s[1] == b)) {
        s[0] = a;
        s[1] = b;
        break;
      }
    }
    for (int i = 59; i >= 0; --i) {
      int a = i / 10 + '0', b = i % 10 + '0';
      if ((s[3] == '?' || s[3] == a) && (s[4] == '?' || s[4] == b)) {
        s[3] = a;
        s[4] = b;
        break;
      }
    }
    return s;
  }
};
