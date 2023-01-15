class Solution {
public:
  long long countGood(vector<int>& a, int k) {
    long long ret = 0;
    int n = a.size();
    map<int, int> mp;
    long long tmp = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      if (i > 0) {
        tmp -= --mp[a[i - 1]];
      }
      while (j < n && tmp < k) {
        tmp += mp[a[j++]]++;
      }
      if (tmp < k) {
        break;
      }
      else {
        ret += n + 1 - j;
      }
    }
    return ret;
  }
};
