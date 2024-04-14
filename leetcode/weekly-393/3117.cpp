
class Solution {
  static constexpr int INF = 1000000007;

  template<typename T>
  struct RMQAnd {
    int n;
    vector<T> e;
    vector<vector<int> > rmq;

    static const int INT_BIT = sizeof(4) * CHAR_BIT;
    static inline int LG2(int i) { return INT_BIT - 1 - __builtin_clz(i); }
    static inline int BIN(int i) { return 1 << i; }

    int cmp(int l, int r) const {
      return l & r;
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
        rmq[0][i] = e[i];
      }
      for (int i = 0; BIN(i + 1) <= n; ++i) {
        for (int j = 0; j + BIN(i + 1) <= n; ++j) {
          rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + BIN(i)]);
        }
      }
    }

    int query(int l, int r) const {
      int b = LG2(r - l);
      return cmp(rmq[b][l], rmq[b][r - (1 << b)]);
    }
  };

  template<typename T>
  struct RMQMin {
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

public:
  int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
    const int n = nums.size();
    RMQAnd<int> rmq;
    rmq.init(n, nums.data());

    vector<int> pre(n + 1, INF);
    pre[0] = 0;
    RMQMin<int> dp;
    dp.init(n + 1, pre.data());
    for (const int andValue : andValues) {
      // cout << "? " << andValue << endl;
      pre = vector<int>(n + 1, INF);
      for (int i = 0; i < n; ++i) {
        if ((nums[i] & andValue) != andValue) {
          continue;
        }
        int lo = 0, hi = i + 1;
        while (lo < hi) {
          int mi = (lo + hi) / 2;
          int v = rmq.query(mi, i + 1);
          if ((v & andValue) == andValue) {
            hi = mi;
          }
          else {
            lo = mi + 1;
          }
        }
        const int jl = hi;
        lo = jl, hi = i + 1;
        while (lo < hi) {
          int mi = (lo + hi) / 2;
          int v = rmq.query(mi, i + 1);
          if (v == andValue) {
            lo = mi + 1;
          }
          else {
            hi = mi;
          }
        }
        const int jr = hi;
        // [jl, jr)
        // cout << i << " = [" << jl << ", " << jr << ") " << (jl < jr ? dp.value(jl, jr) : -1) << endl;
        if (jl < jr) {
          pre[i + 1] = nums[i] + dp.value(jl, jr);
        }
      }
      dp.init(n + 1, pre.data());
    }

    auto ret = pre.back();
    return ret >= INF ? -1 : ret;
  }
};
