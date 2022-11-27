class Solution {
public:
  int appendCharacters(string s, string t) {
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    while (!t.empty() && !s.empty()) {
      if (t.back() == s.back()) {
        t.pop_back();
      }
      s.pop_back();
    }
    return (int)t.size();
  }
};
