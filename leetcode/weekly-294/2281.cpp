template<typename T>
struct RMQ {
  int n;
  vector<T> e;
  vector<vector<int> > rmq;

  static const int INT_BIT = sizeof(4) * CHAR_BIT;
  static inline int LG2(int i) { return INT_BIT - 1 - __builtin_clz(i); }
  static inline int BIN(int i) { return 1 << i; }

  int cmp(int l, int r) const {
    return e[l] <= e[r] ? l : r;
  }

  void init(int n, const T e[]) {
    this->n = n;
    vector<T>(e, e + n).swap(this->e);

    int m = 1;
    while (BIN(m) <= n) {
      ++m;
    }
    vector<vector<int> >(m, vector<int>(n)).swap(rmq);

    for (int i = 0; i < n; ++i) {
      rmq[0][i] = i;
    }
    for (int i = 0; BIN(i + 1) <= n; ++i) {
      for (int j = 0; j + BIN(i + 1) <= n; ++j) {
        rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + BIN(i)]);
      }
    }
  }

  int index(int l, int r) const {
    int b = LG2(r - l);
    return cmp(rmq[b][l], rmq[b][r - (1 << b)]);
  }

  T value(int l, int r) const {
    return e[index(l, r)];
  }
};

static constexpr int64_t MOD = 1000000007;

class Solution {
public:
  int totalStrength(vector<int>& strength) {
    int n = (int)strength.size();
    vector<int64_t> sl, sr, xl, xr;
    sl.resize(n + 1);
    xl.resize(n + 1);
    sl[0] = xl[0] = 0;
    for (int i = 0; i < n; ++i) {
      sl[i + 1] = (sl[i] + strength[i]) % MOD;
      xl[i + 1] = (xl[i] + (i + 1LL) * strength[i]) % MOD;
    }
    sr.resize(n + 1);
    xr.resize(n + 1);
    sr[n] = xr[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      sr[i] = (sr[i + 1] + strength[i]) % MOD;
      xr[i] = (xr[i + 1] + (int64_t)(n - i) * strength[i]) % MOD;
    }

    RMQ<int> rmq;
    rmq.init(strength.size(), strength.data());
    queue<pair<int, int>> q;
    q.emplace(0, (int)strength.size());
    int64_t ret = 0;
    while (!q.empty()) {
      int l = q.front().first;
      int r = q.front().second;
      q.pop();
      int m = rmq.index(l, r);
      auto ll = (xl[m + 1] - xl[l] - (sl[m + 1] - sl[l]) * l) % MOD;
      auto rr = (xr[m] - xr[r] - (sr[m] - sr[r]) * (n - r)) % MOD;
      int64_t tmp = 0;
      // printf("[%d,%d) @ %d: %lld %lld\n", l, r, m, ll, rr);
      tmp += ll * (r - m) % MOD;
      tmp += rr * (m + 1 - l) % MOD;
      tmp -= (r - m) * (m + 1 - l) % MOD * strength[m] % MOD;
      ret += tmp * strength[m] % MOD;
      if (l < m) {
        q.emplace(l, m);
      }
      if (m + 1 < r) {
        q.emplace(m + 1, r);
      }
    }
    ret = (ret % MOD + MOD) % MOD;
    return ret;
  }
};
