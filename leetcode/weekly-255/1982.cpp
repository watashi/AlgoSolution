class Solution {
public:
  vector<int> recoverArray(int n, vector<int>& sums) {
    multiset<int> s(sums.begin(), sums.end());
    vector<int> v;
    while (s.size() > 1) {
      auto it = s.begin();
      int x = *it++;
      int y = *it;
      int d = y - x;
      v.push_back(d);
      multiset<int> t;
      while (!s.empty()) {
        int z = *s.begin();
        s.erase(s.begin());
        s.erase(s.find(z + d));
        t.insert(z);
      }
      s = std::move(t);
    }
    int expected = *s.begin();
    for (int i = 0; i < 1 << n; ++i) {
      int actual = 0;
      for (int j = 0; j < n; ++j) {
        if (((i >> j) & 1) != 0) {
          actual -= abs(v[j]);
          v[j] = -abs(v[j]);
        } else {
          v[j] = abs(v[j]);
        }
      }
      if (actual == expected) {
        return v;
      }
    }
    return v;
  }
};
