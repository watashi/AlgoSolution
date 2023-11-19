
template<typename T>
struct RMQ {
  int n;
  vector<T> e;
  vector<vector<int> > rmq;

  static const int INT_BIT = sizeof(4) * CHAR_BIT;
  static inline int LG2(int i) { return INT_BIT - 1 - __builtin_clz(i); }
  static inline int BIN(int i) { return 1 << i; }

  int cmp(int l, int r) const {
    return e[l] >= e[r] ? l : r;
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

class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    const int n = heights.size();
    RMQ<int> rmq;
    rmq.init(n, heights.data());
    vector<int> ret;
    ret.reserve(queries.size());
    for (const auto& q : queries) {
      int a = q[0], b = q[1];
      if (a > b) {
        swap(a, b);
      }
      if (a == b || heights[a] < heights[b]) {
        ret.push_back(b);
        continue;
      }
      int lo = b + 1, hi = n + 1, h = heights[a];
      while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (rmq.value(b, mi) > h) {
          hi = mi;
        }
        else {
          lo = mi + 1;
        }
      }
      ret.push_back(hi <= n ? hi - 1 : -1);
    }
    return ret;
  }
};
