class Solution {
public:
  static int countPairs(const vector<int>& v, int d) {
    int c = 0;
    for (int i = 1; i < (int)v.size(); ++i) {
      if (v[i] - v[i - 1] <= d) {
        ++c;
        ++i;
      }
    }
    return c;
  }

  int minimizeMax(vector<int>& nums, int p) {
    vector<int> v = nums;
    sort(v.begin(), v.end());
    int lo = 0, hi = v.back() - v.front();
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (countPairs(v, mi) >= p) {
        hi = mi;
      }
      else {
        lo = mi + 1;
      }
    }
    return hi;
  }
};
