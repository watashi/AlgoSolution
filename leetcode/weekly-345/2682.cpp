class Solution {
public:
  vector<int> circularGameLosers(int n, int k) {
    vector<bool> mark(n, false);
    for (int i = 0, j = 0; !mark[j]; ++i, j = (j + i * k) % n) {
      mark[j] = true;
    }
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
      if (!mark[i]) {
        ret.push_back(i + 1);
      }
    }
    return ret;
  }
};
