class Solution {
public:
  int takeCharacters(string s, int k) {
    if (k == 0) {
      return 0;
    }

    vector<int> c(3, 0);
    int r = 0;
    int i = 0;
    int n = s.length();
    for (; i < n && r < 3; ++i) {
      if (++c[s[i] - 'a'] == k) {
        ++r;
      }
    }
    if (r < 3) {
      return -1;
    }

    int ret = i;
    int j = n - 1;
    for (--i; i >= 0; --i) {
      if (c[s[i] - 'a']-- == k) {
        while (++c[s[j--] - 'a'] != k) {
        }
      }
      ret = min(ret, i + (n - 1 - j));
    }
    return ret;
  }
};
