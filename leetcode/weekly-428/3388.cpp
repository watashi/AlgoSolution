class Solution {
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

  struct SuffixArrayBase {
    vector<int> sa, rank, height;

    template<typename T>
    void init(int n, const T a[]) {
      height.resize(n);
      for (int i = 0, z = 0; i < n; ++i) {
        if (rank[i] == 0) {
          height[0] = z = 0;
        }
        else {
          int x = i, y = sa[rank[i] - 1];
          z = max(0, z - 1);
          while (x + z < n && y + z < n && a[x + z] == a[y + z]) {
            ++z;
          }
          height[rank[i]] = z;
        }
      }
    }
  };

  struct SuffixArrayNaive : SuffixArrayBase {
    template<typename T>
    void init(int n, const T a[]) {
      sa.clear();
      for (int i = 0; i < n; ++i) {
        sa.push_back(i);
      }
      sort(sa.begin(), sa.end(), [=](int i, int j) {
        return lexicographical_compare(a + i, a + n, a + j, a + n);
        });

      rank.resize(n);
      for (int i = 0; i < n; ++i) {
        rank[sa[i]] = i;
      }

      height.resize(n);
      if (n > 0) {
        height[0] = 0;
      }
      for (int i = 1; i < n; ++i) {
        int h = n - max(sa[i], sa[i - 1]);
        height[i] = mismatch(a + sa[i], a + sa[i] + h, a + sa[i - 1]).first - (a + sa[i]);
      }
    }
  };

public:
  int beautifulSplits(vector<int>& nums) {
    const int n = nums.size();
    SuffixArrayNaive sa;
    RMQ<int> rmq;
    sa.init(n, nums.data());
    rmq.init(n, sa.height.data());
    auto lcp = [&sa, &rmq](int i, int j) {
      i = sa.rank[i];
      j = sa.rank[j];
      if (i > j) {
        swap(i, j);
      }
      return i < j ? rmq.value(i + 1, j + 1) : (int)sa.rank.size() - i;
    };

    int ret = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        // printf("[%d,%d) %d %d\n", i, j, lcp(0, i), lcp(i, j));
        if ((lcp(0, i) >= i && j - i >= i) ||
            (lcp(i, j) >= j - i && j - i <= n - j)) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
