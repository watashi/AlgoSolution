class Solution {
  struct Impl {
    static constexpr int NP = 4;
    static constexpr int MAXP = 64 * 81 * 25 * 49;
    static constexpr int MAXD = 9;
    static constexpr int MAXS = MAXD * 9;
    static constexpr int MAXQ = 315;  // 7 * 5 * 3 * 3
    const int p[NP] = { 2, 3, 5, 7 };
    vector<int> pval;
    unordered_map<int, int> pidx;
    int ten[MAXD + 1] = {};
    int dp[MAXD + 1][MAXS + 1][MAXQ + 1] = {};

    static long long gcd(long long i, long long j) {
      return j == 0 ? i : gcd(j, i % j);
    }

    int pget(int x) const {
      assert(x > 0);
      int y = x;
      for (int i : p) {
        while (y % i == 0) {
          y /= i;
        }
      }
      return y > 1 ? MAXQ : pidx.at(gcd(MAXP, x));
    }

    int mul(int idx, int d) const {
      if (idx == MAXQ || d == 0) {
        return MAXQ;
      }
      else {
        return pidx.at(gcd(pval[idx] * d, MAXP));
      }
    }

    int gao(int n) const {
      vector<int> ds;
      for (int i = n; i > 0; i /= 10) {
        ds.push_back(i % 10);
      }
      const int nd = ds.size();

      int ret = 0;
      for (int i = 1; i < nd; ++i) {
        for (int d = 1; d < 10; ++d) {
          for (int s = d; s <= MAXS; ++s) {
            const int j = pget(s / gcd(s, d));
            ret += dp[i - 1][s - d][j];
          }
        }
      }
      // cout << n << " A " << ret << endl;

      int sum = 0, prod = 0;
      for (int i = nd - 1; i >= 0; --i) {
        if (prod == MAXQ) {
          ret += ds[i] * ten[i];
          continue;
        }
        for (int d = 0; d < ds[i]; ++d) {
          if (d == 0) {
            if (sum > 0) {
              ret += ten[i];
            }
            continue;
          }
          for (int s = sum + d; s <= MAXS; ++s) {
            const int j = pget(s / gcd(s, pval[prod] * d));
            ret += dp[i][s - sum - d][j];
          }
        }
        sum += ds[i];
        prod = mul(prod, ds[i]);
      }
      // cout << n << " B " << ret << endl;
      return ret;
    }

    Impl() {
      set<int> st;
      st.insert(1);
      while (!st.empty()) {
        auto x = *st.begin();
        st.erase(x);
        pval.push_back(x);
        pidx.emplace(x, pidx.size());
        for (int i = 0; i < NP; ++i) {
          int y = gcd(MAXP, x * p[i]);
          if (y > x) {
            st.insert(y);
          }
        }
      }
      assert(pidx.size() == MAXQ);

      ten[0] = 1;
      dp[0][0][0] = 1;
      for (int i = 0; i < MAXD; ++i) {
        ten[i + 1] = ten[i] * 10;
        for (int j = 0; j <= MAXS; ++j) {
          for (int k = 0; k <= MAXQ; ++k) {
            const int cnt = dp[i][j][k];
            if (cnt == 0) {
              continue;
            }
            for (int d = 0, jj = j + d; d < 10 && jj <= MAXS; ++d, ++jj) {
              const int kk = mul(k, d);
              dp[i + 1][jj][kk] += cnt;
            }
          }
        }
      }

      for (int h = 0; h <= NP; ++h) {
        for (int i = 0; i <= MAXD; ++i) {
          for (int j = 0; j <= MAXS; ++j) {
            for (int k = MAXQ - 1; k >= 0; --k) {
              const int kk = h < NP ? mul(k, p[h]) : MAXQ;
              if (k < kk && kk <= MAXQ) {
                dp[i][j][k] += dp[i][j][kk];
              }
            }
          }
        }
      }
    }
  };

public:
  int beautifulNumbers(int l, int r) {
    static const Impl impl;
    if (false) {
      for (int i = l; i <= r; ++i) {
        if (impl.gao(i + 1) - impl.gao(i) != 0) {
          cout << i << " " << impl.gao(i + 1) - impl.gao(i) << " " << impl.gao(i + 1) << endl;
        }
      }
      cout << impl.gao(r + 1) << " - " << impl.gao(l) << endl;
    }
    return impl.gao(r + 1) - impl.gao(l);
  }
};
