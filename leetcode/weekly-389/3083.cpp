class Solution {
public:
  bool isSubstringPresent(string s) {
    int n = s.length();
    set<string> st;
    for (int i = 0; i + 1 < n; ++i) {
      st.insert(s.substr(i, 2));
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i + 1 < n; ++i) {
      if (st.count(s.substr(i, 2)) > 0) {
        return true;
      }
    }
    return false;
  }
};
