class Solution {
public:
  int maximumLengthSubstring(string s) {
    map<char, int> mp;
    int ret = 0;
    for (int i = 0, j = 0; i < (int)s.length(); ++i) {
      auto& c = ++mp[s[i]];
      while (c > 2) {
        --mp[s[j++]];
      }
      ret = max(ret, i - j + 1);
    }
    return ret;
  }
};
