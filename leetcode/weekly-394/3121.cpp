class Solution {
public:
  int numberOfSpecialChars(string word) {
    vector<pair<int, int>> v(26, make_pair(-1, -1));
    for (int i = 0; i < (int)word.size(); ++i) {
      char ch = word[i];
      if (islower(ch)) {
        v[ch - 'a'].first = i;
      }
      else if (isupper(ch)) {
        ch -= 'A';
        if (v[ch].second == -1) {
          v[ch].second = i;
        }
      }
    }
    int ret = 0;
    for (const auto& i : v) {
      if (i.first != -1 && i.second != -1 && i.first < i.second) {
        ++ret;
      }
    }
    return ret;
  }
};
