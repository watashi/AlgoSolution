class Solution {
public:
  int findMinimumOperations(string s1, string s2, string s3) {
    int n = min({ s1.size(), s2.size(), s3.size() });
    int m = s1.size() + s2.size() + s3.size() - 3 * n;
    s1.resize(n);
    s2.resize(n);
    s3.resize(n);
    while (s1.size() >= 2 && (s1 != s2 || s1 != s3)) {
      s1.pop_back();
      s2.pop_back();
      s3.pop_back();
      m += 3;
    }
    if (s1 == s2 && s1 == s3) {
      return m;
    }
    return -1;
  }
};
