class Solution {
public:
  int maximumTastiness(vector<int>& price, int k) {
    vector<int> v(price.begin(), price.end());
    sort(v.begin(), v.end());
    int lo = 0, hi = v.back() - v.front() + 1;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      bool ok = true;
      int tmp = v.front();
      for (int i = 1; i < k; ++i) {
        auto it = lower_bound(v.begin(), v.end(), tmp + mi);
        if (it == v.end()) {
          ok = false;
          break;
        }
        tmp = *it;
      }
      if (ok) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi - 1;
  }
};
