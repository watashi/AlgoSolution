class Solution {
public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ret;
    ret.reserve(queries.size());
    for (const auto& q : queries) {
      int a = q[0], b = q[1];
      if (a > b) {
        swap(a, b);
      }
      int d = __builtin_clz(a) - __builtin_clz(b);
      b >>= d;
      d += a == b ? 0 : 2 * (sizeof(int) * CHAR_BIT - __builtin_clz(a ^ b));
      ret.push_back(d + 1);
    }
    return ret;
  }
};
