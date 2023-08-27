class Solution {
public:
  int minOperations(vector<int>& num, int target) {
    static constexpr int BITS = 32;
    vector<int> c(BITS + 1, 0);
    for (int i : num) {
      ++c[BITS - 1 - __builtin_clz(i)];
    }
    int ret = 0;
    for (int i = 0; target > 0; ++i, target >>= 1) {
      if ((target & 1) == 1) {
        if (c[i] == 0) {
          auto j = find_if(&c[i], &c[BITS], [](const auto& x){ return x > 0; }) - &c[0];
          if (j == BITS) {
            return -1;
          }
          ret += j - i;
          --c[j];
          fill(&c[i], &c[j], 1);
        }
        --c[i];
      }
      c[i + 1] += c[i] / 2;
    }
    return ret;
  }
};
