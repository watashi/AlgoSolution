class Solution {
  static constexpr int INF = 1000000007;

  struct Remap {
    vector<int> v;

    void add(int i) {
      v.push_back(i);
    }

    void build() {
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
    }

    int size() const {
      return v.size();
    }

    int index(int i) const {
      return lower_bound(v.begin(), v.end(), i) - v.begin();
    }

    int value(int i) const {
      return v[i];
    }
  };

  struct SegTree {
    vector<vector<int>> v;
    int m = 0;

    static inline int L(int i) {
      return i << 1;
    }

    static inline int R(int i) {
      return L(i) ^ 1;
    }

    void init(int n) {
      m = 1;
      while (m < n) {
        m <<= 1;
      }
      v.clear();
      v.resize(m + m);
    }

    void add(int x, int y) {
      for (int i = x + m; i > 0; i >>= 1) {
        v[i].push_back(y);
      }
    }

    void build() {
      for (auto& vi : v) {
        sort(vi.begin(), vi.end());
        vi.erase(unique(vi.begin(), vi.end()), vi.end());
      }
    }

    int _query(int p, int pl, int pr, int l, int r, int y) const {
      if (pl == l && pr == r) {
        auto it = lower_bound(v[p].begin(), v[p].end(), y);
        return it == v[p].end() ? INF : *it;
      }
      int pm = (pl + pr) >> 1;
      if (r <= pm) {
        return _query(L(p), pl, pm, l, r, y);
      }
      else if (pm <= l) {
        return _query(R(p), pm, pr, l, r, y);
      }
      else {
        return min(_query(L(p), pl, pm, l, pm, y), _query(R(p), pm, pr, pm, r, y));
      }
    }

    // [l, r) && [y, inf)
    int query(int l, int r, int y) const {
      return _query(1, 0, m, l, r, y);
    }

    int query(int x, int y) const {
      const int p = m + x;
      auto it = lower_bound(v[p].begin(), v[p].end(), y);
      return it == v[p].end() ? INF : *it;
    }
  };

public:
  long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
    const int n = xCoord.size();
    Remap mpx, mpy;
    for (int i = 0; i < n; ++i) {
      mpx.add(xCoord[i]);
      mpy.add(yCoord[i]);
    }
    mpx.build();
    mpy.build();

    SegTree byx;
    vector<vector<int>> byy(mpy.size());
    byx.init(mpx.size());
    for (int i = 0; i < n; ++i) {
      int x = mpx.index(xCoord[i]);
      int y = mpy.index(yCoord[i]);
      byx.add(x, y);
      byy[y].push_back(x);
    }
    byx.build();

    long long ret = -1;
    for (int y = 0; y < (int)byy.size(); ++y) {
      auto& xs = byy[y];
      sort(xs.begin(), xs.end());
      for (int i = 1; i < (int)xs.size(); ++i) {
        const int x1 = xs[i - 1];
        const int x2 = xs[i];
        int y1 = byx.query(x1, y + 1);
        int y2 = byx.query(x2, y + 1);
        if (y1 != y2 || y1 == INF) {
          continue;
        }
        if (x2 - x1 > 1) {
          int y3 = byx.query(x1 + 1, x2, y);
          if (y3 <= y1) {
            continue;
          }
        }
        ret = max(ret, 1LL * (mpx.value(x2) - mpx.value(x1)) * (mpy.value(y1) - mpy.value(y)));
      }
    }
    return ret;
  }
};

