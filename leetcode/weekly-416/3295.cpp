class Solution {
public:
  bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
    set<string> st(bannedWords.begin(), bannedWords.end());
    int c = 0;
    for (const auto& s : message) {
      if (st.count(s) > 0 && ++c >= 2) {
        return true;
      }
    }
    return false;
  }
};
