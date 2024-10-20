class Solution {
public:
  int numberOfSubstrings(string s, int k) {
    static constexpr int CHARSET = 26;
    vector<vector<int>> idx(CHARSET);
    vector<int> kth(CHARSET, -1);
    int ret = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      int ii = s[i] - 'a';
      idx[ii].push_back(i);
      kth[ii] = idx[ii].size();
      int first = -1;
      for (int j = 0; j < CHARSET; ++j) {
        if (kth[j] >= k) {
          first = max(first, idx[j][kth[j] - k]);
        }
      }
      ret += first + 1;
    }
    return ret;
  }
};
