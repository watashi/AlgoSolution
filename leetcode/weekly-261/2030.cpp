class Solution {
public:
  string smallestSubsequence(string s, int k, char letter, int repetition) {
    int n = (int)s.size();
    vector<int> cnt(n + 1, 0);
    vector<vector<int>> next(n + 1);
    next[n] = vector<int>(26, n);
    for (int i = n - 1; i >= 0; --i) {
      cnt[i] = cnt[i + 1] + (s[i] == letter ? 1 : 0);
      next[i] = next[i + 1];
      next[i][s[i] - 'a'] = i;
    }
    int pos = 0;
    string ans;
    for (int i = k - 1; i >= 0; --i) {
      for (int c = 0; c < 26; ++c) {
        int newpos = next[pos][c] + 1;
        int newrep = repetition - (c == letter - 'a' ? 1 : 0);
        if (n - newpos >= i && cnt[newpos] >= newrep && newrep <= i) {
          ans += (char)('a' + c);
          pos = newpos;
          repetition = newrep;
          break;
        }
      }
    }
    return ans;
  }
};
