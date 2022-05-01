class Solution {
public:
  int countDistinct(vector<int>& v, int k, int p) {
    set<vector<int>> s;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
      vector<int> w;
      int c = 0;
      for (int j = i; j < n; ++j) {
        w.emplace_back(v[j]);
        if (v[j] % p == 0) {
          ++c;
        }
        if (c > k) {
          break;
        }
        else {
          s.insert(w);
        }
      }
    }
    return (int)s.size();
  }
};
