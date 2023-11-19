class Solution {
public:
  long long minimumSteps(string s) {
    long long ret = 0;
    for (int i = 0, j = 0; i < (int)s.size(); ++i) {
      if (s[i] == '0') {
        ret += i - j++;
      }
    }
    return ret;
  }
};
