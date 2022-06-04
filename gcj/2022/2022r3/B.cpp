#include "bits/stdc++.h"

using namespace std;

inline int L(int i) { return i << 1; }
inline int R(int i) { return L(i) ^ 1; }

struct SegTree {
  int m;
  vector<pair<int, int>> v;

  void init(int n) {
    m = 1;
    while (m < n) {
      m <<= 1;
    }
    v.clear();
    v.resize(m + m);
    fill(v.begin() + m, v.end(), make_pair(0, 1));
    for (int i = m - 1; i > 0; --i) {
      v[i].second = v[L(i)].second + v[R(i)].second;
    }
  }

  int count(int p) {
    return v[p].first == 0 ? v[p].second : 0;
  }

  void update(int p, int pl, int pr, int l, int r, int d) {
    if (pl == l && pr == r) {
      v[p].first += d;
    }
    else {
      int pm = (pl + pr) / 2;
      if (l < pm) {
        update(L(p), pl, pm, l, min(r, pm), d);
      }
      if (pm < r) {
        update(R(p), pm, pr, max(l, pm), r, d);
      }
      v[p].second = count(L(p)) + count(R(p));
    }
  }

  int query(int p, int pl, int pr, int l, int r) {
    if (v[p].first > 0) {
      return 0;
    }
    else if (pl == l && pr == r) {
      return v[p].second;
    }
    else {
      int pm = (pl + pr) / 2;
      int ret = 0;
      if (l < pm) {
        ret += query(L(p), pl, pm, l, min(r, pm));
      }
      if (pm < r) {
        ret += query(R(p), pm, pr, max(l, pm), r);
      }
      return ret;
    }
  }
};

int ridx(const vector<int>& v, int i, int def) {
  if (i < (int)v.size()) {
    return v[(int)v.size() - 1 - i];
  }
  else {
    return def;
  }
}

int main() {
  int re;

  (void)scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n, c;
    (void)scanf("%d%d", &n, &c);
    vector<pair<int, int>> ab(c);
    for (auto& i : ab) {
      (void)scanf("%d%d", &i.first, &i.second);
    }
    vector<int> p(n);
    for (auto& i : p) {
      (void)scanf("%d", &i);
      --i;
    }

    vector<int> pp = p;
    p.insert(p.end(), pp.begin(), pp.end());
    vector<vector<int>> idx(c);
    for (int i = 0; i < n + n; ++i) {
      idx[p[i]].push_back(i);
    }
    for (int i = 0; i < c; ++i) {
      reverse(idx[i].begin(), idx[i].end());
    }

    int64_t ans = 0;
    SegTree st;
    vector<vector<pair<int, int>>> added(c);
    st.init(n + n);
    for (int i = 0; i < c; ++i) {
      if (ab[i].first > 1 && idx[i].size() > 0) {
        added[i].emplace_back(ridx(idx[i], 0, -1), ridx(idx[i], ab[i].first - 1, n + n));
      }
      if (idx[i].size() >= ab[i].second + 1) {
        added[i].emplace_back(ridx(idx[i], ab[i].second, -1), n + n);
      }
      for (const auto& j : added[i]) {
        st.update(1, 0, st.m, j.first, j.second, 1);
      }
    }
    for (int k = 0; k < n; ++k) {
      if (n > 2) {
        ans += st.query(1, 0, st.m, k + 1, k + n - 1);
      }
      auto i = p[k];
      for (const auto& j : added[i]) {
        st.update(1, 0, st.m, j.first, j.second, -1);
      }
      added[i].clear();
      idx[i].pop_back();
      if (ab[i].first > 1 && idx[i].size() > 0) {
        added[i].emplace_back(ridx(idx[i], 0, -1), ridx(idx[i], ab[i].first - 1, n + n));
      }
      if (idx[i].size() >= ab[i].second + 1) {
        added[i].emplace_back(ridx(idx[i], ab[i].second, -1), n + n);
      }
      for (const auto& j : added[i]) {
        st.update(1, 0, st.m, j.first, j.second, 1);
      }
    }

    printf("Case #%d: %lld\n", ri, ans);
  }

  return 0;
}
