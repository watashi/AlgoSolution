class Solution {
public:
  int findTheLongestBalancedSubstring(string s) {
    int ret = 0;
    auto it = s.begin();
    while (it != s.end()) {
      int z = 0;
      while (it != s.end() && *it == '0') {
        ++z;
        ++it;
      }
      int o = 0;
      while (it != s.end() && *it != '0') {
        ++o;
        ++it;
      }
      ret = max(ret, min(z, o));
    }
    return ret * 2;
  }
};
