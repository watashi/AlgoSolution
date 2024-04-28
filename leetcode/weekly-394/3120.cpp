class Solution {
public:
  int numberOfSpecialChars(string word) {
    unordered_set<char> s(word.begin(), word.end());
    int ret = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (s.count(c) > 0 && s.count(toupper(c)) > 0) {
        ++ret;
      }
    }
    return ret;
  }
};
