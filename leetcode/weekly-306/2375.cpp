class Solution {
public:
  string smallestNumber(string pattern) {
    string ret;
    for (int i = 0; i <= (int)pattern.length(); ++i) {
      ret.push_back('1' + i);
    }
    for (int i = 0; i < (int)pattern.length(); ) {
      if (pattern[i] == 'D') {
        int j = i + 1;
        while (j < (int)pattern.length() && pattern[j] == 'D') {
          ++j;
        }
        reverse(ret.data() + i, ret.data() + j + 1);
        i = j;
      }
      else {
        ++i;
      }
    }
    return ret;
  }
};
