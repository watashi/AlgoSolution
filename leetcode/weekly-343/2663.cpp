class Solution {
public:
  char fix(const string& s, int i, char c) {
   if (i >= 1 && c == s[i - 1]) {
     return fix(s, i, c + 1);
   }
   if (i >= 2 && c == s[i - 2]) {
     return fix(s, i, c + 1);
   }
   return c;
  }

  string smallestBeautifulString(string s, int k) {
    int n = s.size();
    int m = 0;
    while (m < n - 1 && fix(s, m, s[m]) == s[m]) {
      ++m;
    }
    char end = 'a' + k;
    for (; m >= 0; --m) {
      char c = fix(s, m, s[m] + 1);
      if (c < end) {
        s[m] = c;
        for (int i = m + 1; i < n; ++i) {
          s[i] = fix(s, i, 'a');
        }
        return s;
      }
    }
    return "";
  }
};
