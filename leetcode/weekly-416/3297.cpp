class Solution {
public:
  long long validSubstringCount(string word1, string word2) {
    vector<int> c(26, 0);
    for (char i : word2) {
      ++c[i - 'a'];
    }
    int nz = c.size() - count(c.begin(), c.end(), 0);
    const int n = (int)word1.size();
    int end = 0;
    while (nz > 0 && end < n) {
      if (--c[word1[end++] - 'a'] == 0) {
        --nz;
      }
    }
    if (nz > 0) {
      return 0;
    }

    long long ret = 0;
    int start = 0;
    while (true) {
      while (start < end && c[word1[start] - 'a'] < 0) {
        ++c[word1[start++] - 'a'];
      }
      ret += start + 1;
      if (end >= n) {
        break;
      }
      --c[word1[end++] - 'a'];
    }
    return ret;
  }
};
