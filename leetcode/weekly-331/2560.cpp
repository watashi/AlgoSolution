class Solution {
public:
  int minCapability(vector<int>& a, int k) {
    int lo = 0, hi = *max_element(a.begin(), a.end());
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      auto p = find_if(a.begin(), a.end(), [mi](const auto& ai) { return ai <= mi; });
      for (int i = 1; i < k; ++i) {
        if (p + 2 < a.end()) {
          p = find_if(p + 2, a.end(), [mi](const auto& ai) { return ai <= mi; });
        }
        else {
          p = a.end();
          break;
        }
      }
      if (p == a.end()) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi;
  }
};
