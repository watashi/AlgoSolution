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

class Solution {
public:
  bool primeSubOperation(vector<int>& nums) {
    static constexpr int MAXN = 2000;
    const PrimeTable pt(MAXN);
    vector<int> ps;
    ps.push_back(0);
    for (int i = 2; i < MAXN; ++i) {
      if (pt.p[i] == i) {
        ps.push_back(i);
      }
    }
    int cur = 0;
    for (int i : nums) {
      auto it = lower_bound(ps.begin(), ps.end(), i - cur);
      if (it == ps.begin()) {
        return false;
      }
      cur = i - *--it;
      // cout << i << " => " << cur << endl;
    }
    return true;
  }
};
