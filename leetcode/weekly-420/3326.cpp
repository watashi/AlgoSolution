class Solution {
  struct PrimeTable {
    vector<int> p;

    PrimeTable(int n) {
      init(n);
    }

    void init(int n) {
      p = vector<int>(n, 0);
      iota(p.begin(), p.end(), 0);
      for (int i = 2; i * i < n; ++i) {
        if (p[i] == i) {
          for (int j = i * i; j < n; j += i) {
            if (p[j] == j) {
              p[j] = i;
            }
          }
        }
      }
    }
  };

public:
  int minOperations(vector<int>& nums) {
    static const PrimeTable pt(1 << 20);
    vector<int> v = nums;
    int ret = 0;
    while (v.size() >= 2) {
      auto& lhs = v[v.size() - 2];
      auto rhs = v.back();
      if (lhs <= rhs) {
        v.pop_back();
      }
      else if (pt.p[lhs] <= rhs) {
        lhs = pt.p[lhs];
        ++ret;
      }
      else {
        return -1;
      }
    }
    return ret;
  }
};
