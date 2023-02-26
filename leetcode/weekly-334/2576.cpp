class Solution {
public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    vector<int> a = nums;
    sort(a.begin(), a.end());
    int n = a.size();
    int lo = 0, hi = n / 2 + 1;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      bool ok = true;
      for (int i = 0; i < mi; ++i) {
        if (a[i] * 2 > a[n - mi + i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        lo = mi + 1;
      }
      else {      
        hi = mi;
      }
    }
    return (hi - 1) * 2;
  }
};
