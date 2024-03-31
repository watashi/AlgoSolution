class Solution {
public:
  long long countAlternatingSubarrays(vector<int>& a) {
    long long ret = 0;
    int n = a.size();
    for (int i = 0; i < n; ) {
      int j = i + 1;
      while (j < n && a[j] != a[j - 1]) {
        ++j;
      }
      // [i, j)
      ret += (j - i) * (j - i + 1LL) / 2;
      i = j;
    }
    return ret;
  }
};
