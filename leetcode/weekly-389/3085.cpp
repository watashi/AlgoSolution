class Solution {
public:
  int minimumDeletions(string word, int k) {
    constexpr int CHARSET = 26;
    vector<int> v(CHARSET, 0);
    for (char c : word) {
      ++v[c - 'a'];
    }
    sort(v.begin(), v.end());
    int ret = word.length();
    for (int i = 0; i <= v.back(); ++i) {
      int tmp = 0;
      for (int j : v) {
        if (j < i) {
          tmp += j;
        }
        else if (j > i + k) {
          tmp += j - (i + k);
        }
      }
      ret = min(ret, tmp);
    }
    return ret;
  }
};
