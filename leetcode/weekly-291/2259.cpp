class Solution {
public:
  string removeDigit(string s, char digit) {
    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == digit) {
        ans = max(ans, s.substr(0, i) + s.substr(i + 1));
      }
    }
    return ans;
  }
};
