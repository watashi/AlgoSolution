class Solution {
public:
  bool validPartition(vector<int>& a) {
    int n = a.size();
    vector<int> ok(n + 1, false);
    ok[0] = true;
    for (int i = 0; i < n - 1; ++i) {
      if (!ok[i]) {
        continue;
      }
      if (a[i] == a[i + 1]) {
        ok[i + 2] = true;
        if (i + 2 < n && a[i] == a[i + 2]) {
          ok[i + 3] = true;
        }
      }
      if (i + 2 < n && a[i + 1] == a[i] + 1 && a[i + 2] == a[i] + 2) {
        ok[i + 3] = true;
      }
    }
    return ok[n];
  }
};
