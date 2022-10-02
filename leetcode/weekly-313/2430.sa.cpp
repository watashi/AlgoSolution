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

struct SuffixArraySimple : SuffixArrayBase {
  template<typename T>
  void init(int n, const T a[]) {
    sa.resize(n);
    rank.resize(n);

    for (int i = 0; i < n; ++i) {
      rank[i] = a[i];
    }
    for (int m = 1; (m == 1 && n == 1) || m < n; m <<= 1) {
      vector<pair<int, int> > suffix(n);
      for (int i = 0; i < n; ++i) {
        sa[i] = i;
        suffix[i] = make_pair(rank[i],
          i + m < n ? rank[i + m] : numeric_limits<int>::min());
      }
      sort(sa.begin(), sa.end(), [&suffix](int i, int j) {
        return suffix[i] < suffix[j];
      });
      for (int i = 0; i < n; ++i) {
        if (i == 0 || (suffix[sa[i]] != suffix[sa[i - 1]])) {
          rank[sa[i]] = i;
        }
        else {
          rank[sa[i]] = rank[sa[i - 1]];
        }
      }
    }

    SuffixArrayBase::init(n, a);
  }
};

class Solution {
public:
  int deleteString(string s) {
    int n = (int)s.size();
    SuffixArraySimple sa;
    sa.init(n, s.data());
    RMQ<int> rmq;
    rmq.init(n, sa.height.data());

    auto lcp = [&sa, &rmq](int i, int j) {
      i = sa.rank[i];
      j = sa.rank[j];
      if (i > j) {
        swap(i, j);
      }
      return i < j ? rmq.value(i + 1, j + 1) : (int)sa.rank.size() - i;
    };

    vector<int> dp(n, 1);
    int ret = 0;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 1; i + j + j <= n; ++j) {
        if (lcp(i, i + j) >= j) {
          dp[i] = max(dp[i], dp[i + j] + 1);
        }
      }
    }
    return dp[0];
  }
};
