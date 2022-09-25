class Solution {
public:
  vector<int> goodIndices(vector<int>& a, int k) {
    int n = a.size();
    vector<int> inc(n), dec(n);
    dec[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] <= a[i - 1]) {
        dec[i] = dec[i - 1] + 1;
      }
      else {
        dec[i] = 1;
      }
    }
    inc[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] <= a[i + 1]) {
        inc[i] = inc[i + 1] + 1;
      }
      else {
        inc[i] = 1;
      }
    }
    vector<int> ret;
    for (int i = 1; i < n - 1; ++i) {
      if (dec[i - 1] >= k && inc[i + 1] >= k) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
