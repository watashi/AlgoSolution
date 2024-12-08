class Solution {
  static constexpr int INF = 1000000007;

  struct Remap {
    map<int, int> mp;
    vector<int> v;

    void add(int i) {
      mp[i];
    }

    void build() {
      int n = 0;
      for (auto& i : mp) {
        v.push_back(i.first);
        i.second = n++;
      }
    }

    int size() const {
      return mp.size();
    }

    int index(int i) const {
      return mp.find(i)->second;
    }

    int value(int i) const {
      return v[i];
    }
  };

  struct SegTree {
    vector<set<int>> v;
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
        v[i].emplace(y);
      }
    }

    int _query(int p, int pl, int pr, int l, int r, int y) const {
      if (pl == l && pr == r) {
        auto it = v[p].lower_bound(y);
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
  };

public:
  int maxRectangleArea(vector<vector<int>>& points) {
    Remap mpx, mpy;
    for (const auto& p : points) {
      mpx.add(p[0]);
      mpy.add(p[1]);
    }
    mpx.build();
    mpy.build();

    SegTree byx;
    vector<vector<int>> byy(mpy.size());
    byx.init(mpx.size());
    for (const auto& p : points) {
      int x = mpx.index(p[0]);
      int y = mpy.index(p[1]);
      byx.add(x, y);
      byy[y].push_back(x);
    }

    int ret = -1;
    for (int y = 0; y < (int)byy.size(); ++y) {
      auto& xs = byy[y];
      sort(xs.begin(), xs.end());
      for (int i = 1; i < (int)xs.size(); ++i) {
        const int x1 = xs[i - 1];
        const int x2 = xs[i];
        int y1 = byx.query(x1, x1 + 1, y + 1);
        int y2 = byx.query(x2, x2 + 1, y + 1);
        if (y1 != y2 || y1 == INF) {
          continue;
        }
        if (x2 - x1 > 1) {
          int y3 = byx.query(x1 + 1, x2, y);
          if (y3 <= y1) {
            continue;
          }
        }
        ret = max(ret, (mpx.value(x2) - mpx.value(x1)) * (mpy.value(y1) - mpy.value(y)));
      }
    }
    return ret;
  }
};
