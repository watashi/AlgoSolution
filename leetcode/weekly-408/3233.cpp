class Solution {
  struct PrimeTable {
    vector<int> p;
    vector<int> ps;

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
        ps.clear();
        for (int i = 2; i < n; ++i) {
        if (p[i] == i) {
            ps.push_back(i);
        }
      }
    }
  };

  // [0, n)
  static int count(int n) {
    static constexpr int MAXN = 40000;
    static const PrimeTable pt(MAXN);
    int lo = 0, hi = (int)pt.ps.size();
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (pt.ps[mi] * pt.ps[mi] < n) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return n - hi;
  }

public:
  int nonSpecialCount(int l, int r) {
    return count(r + 1) - count(l);
  }
};
