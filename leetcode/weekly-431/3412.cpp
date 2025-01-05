class Solution {
public:
  long long calculateScore(string s) {
    vector<vector<int>> idx(26);
    long long ret = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
      int x = s[i] - 'a';
      int y = 25 - x;
      if (idx[y].empty()) {
        idx[x].push_back(i);
      }
      else {
        int j = idx[y].back();
        idx[y].pop_back();
        ret += i - j;
      }
    }
    return ret;
  }
};
