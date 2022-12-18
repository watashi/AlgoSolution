class Solution {
public:
  vector<int> path(int x) {
    vector<int> v;
    while (x > 1) {
      v.push_back(x);
      x >>= 1;
    }
    return v;
  }

  vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ret;
    for (const auto& q : queries) {
      vector<int> a = path(q[0]), b = path(q[1]);
      while (!a.empty() && !b.empty() && a.back() == b.back()) {
        a.pop_back();
        b.pop_back();
      }
      ret.push_back(a.size() + b.size() + 1);
    }
    return ret;
  }
};
