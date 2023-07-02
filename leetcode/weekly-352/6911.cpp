class Solution {
public:
  long long continuousSubarrays(vector<int>& a) {
    long long ret = 0;
    multiset<int> ms;
    for (int i = 0, j = 0; i < (int)a.size(); ++i) {
      ms.insert(a[i]);
      while (*ms.rbegin() - *ms.begin() > 2) {
        ms.erase(ms.find(a[j++]));
      }
      ret += i + 1 - j;
    }
    return ret;
  }
};
