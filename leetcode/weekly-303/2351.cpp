class Solution {
public:
  char repeatedCharacter(string s) {
    unordered_set<char> st;
    for (char c : s) {
      if (!st.insert(c).second) {
        return c;
      }
    }
    return ' ';
  }
};
