class Solution {
public:
  int medianOfUniquenessArray(vector<int>& a) {
    const int n = a.size();
    const long long m = (n * (n + 1LL) / 2 - 1) / 2;
    int lo = 1, hi = n;
    while (lo < hi) {
      const int mi = (lo + hi) / 2;
      unordered_map<int, int> mp;
      int dist = 0;
      long long cnt = 0;
      for (int i = 0, j = 0; i < n; ++i) {
        if (mp[a[i]]++ == 0) {
          ++dist;
          while (dist > mi) {
            if (--mp[a[j]] == 0) {
              --dist;
              mp.erase(a[j]);
            }
            ++j;
          }
        }
        cnt += i + 1 - j;
      }
      if (cnt <= m) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi;
  }
};
