class Solution {
public:
  int findPermutationDifference(string s, string t) {
    int ret = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
      int j = t.find(s[i]);
      ret += abs(i - j);
    }
    return ret;
  }
};
