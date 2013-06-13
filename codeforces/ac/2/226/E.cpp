#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXM = 17;
const int MAXN = 1 << MAXM;

struct TreeDecomposition {
  vector<int> e[MAXN], c[MAXN];
  int s[MAXN];    // subtree size
  int p[MAXN];    // parent id
  int r[MAXN];    // chain root id
  int t[MAXN];    // timestamp, index used in segtree
  int ts;

  void dfs_(int v, int f) {
    p[v] = f;
    s[v] = 1;
    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f) {
        dfs_(w, v);
        s[v] += s[w];
      }
    }
  }

  void decomp_(int v, int f, int k) {
    t[v] = ts++;
    c[k].push_back(v);
    r[v] = k;

    int x = 0, y = -1;
    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f) {
        if (s[w] > x) {
          x = s[w];
          y = w;
        }
      }
    }
    if (y != -1) {
      decomp_(y, v, k);
    }

    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f && w != y) {
        decomp_(w, v, w);
      }
    }
  }

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }

  void add(int a, int b) {
    e[a].push_back(b);
    e[b].push_back(a);
  }

  void build() {  // !!
    ts = 0;
    dfs_(0, 0);
    decomp_(0, 0, 0);
  }
} hld;

struct LCA {
  vector<int> e[MAXN];
  int d[MAXN], p[MAXN][MAXM];

  void dfs_(int v, int f) {
    p[v][0] = f;
    for (int i = 1; i < MAXM; ++i) {
      p[v][i] = p[p[v][i - 1]][i - 1];
    }
    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f) {
        d[w] = d[v] + 1;
        dfs_(w, v);
      }
    }
  }

  int up_(int v, int m) {
    for (int i = 0; i < MAXM; ++i) {
      if (m & (1 << i)) {
        v = p[v][i];
      }
    }
    return v;
  }

  int lca(int a, int b) {
    if (d[a] > d[b]) {
      swap(a, b);
    }
    b = up_(b, d[b] - d[a]);
    if (a == b) {
      return a;
    } else {
      for (int i = MAXM - 1; i >= 0; --i) {
        if (p[a][i] != p[b][i]) {
          a = p[a][i];
          b = p[b][i];
        }
      }
      return p[a][0];
    }
  }

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }

  void add(int a, int b) {
    e[a].push_back(b);
    e[b].push_back(a);
  }

  void build() {
    d[0] = 0;
    dfs_(0, 0);
  }
} lca;

struct SegTree {
  int n;
  map<int, int> mp[MAXN + MAXN];

  void init(int m) {
    n = 1;
    while (n < m) {
      n <<= 1;
    }
    fill(mp + 1, mp + n + n, map<int, int>());
  }

  void del(int i, int e) {
    for (i += n; i > 0; i >>= 1) {
      mp[i][e];
    }
  }

  void build() {
    for (int i = 1; i < n + n; ++i) {
      int k = 0;
      for (auto& j: mp[i]) {
        j.second = k++;
      }
      mp[i][MAXN] = k;  // guard
    }
  }

  // [x, y)
  int bad(int p, int x, int y) const {
    return mp[p].lower_bound(y)->second - mp[p].lower_bound(x)->second;
  }

  static int L(int i) { return i << 1; }
  static int R(int i) { return L(i) ^ 1; }

  int good(int p, int pl, int pr, int l, int r, int x, int y) {
    l = max(l, pl);
    r = min(r, pr);
    if (l >= r) {
      return 0;
    } else if (pl == l && pr == r) {
      return pr - pl - bad(p, x, y);
    } else {
      int pm = (pl + pr) / 2;
      return good(L(p), pl, pm, l, r, x, y) + good(R(p), pm, pr, l, r, x, y);
    }
  }


  int index(int p, int pl, int pr, int l, int r, int x, int y, int& z) {
    l = max(l, pl);
    r = min(r, pr);
    if (l >= r) {
      return -1;
    }
    if (pl == l && pr == r) {
      int g = pr - pl - bad(p, x, y);
      if (z >= g) {
        z -= g;
        return -1;
      }
    }
    if (pr - pl == 1) {
      return pl;
    }
    int pm = (pl + pr) / 2;
    int ret = index(L(p), pl, pm, l, r, x, y, z);
    if (ret != -1) {
      return ret;
    } else {
      return index(R(p), pm, pr, l, r, x, y, z);
    }
  }
} st;

vector<pair<int, int> > keypath(int a, int b) {
  int c = lca.lca(a, b);
  vector<pair<int, int> > pa, pb;

  while (hld.r[a] != hld.r[c]) {
    pa.push_back({a, hld.r[a]});
    a = hld.p[hld.r[a]];
  }
  while (hld.r[b] != hld.r[c]) {
    pb.push_back({hld.r[b], b});
    b = hld.p[hld.r[b]];
  }
  pa.push_back({a, b});
  pa.insert(pa.end(), pb.rbegin(), pb.rend());

  return pa;
}

struct Query {
  int a, b, x, y, k, ans;
} q[MAXN];

static int invt[MAXN];

int main() {
  int n, m, t;

  scanf("%d", &n);
  hld.init(n);
  lca.init(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    --t;
    if (t >= 0) {
      hld.add(i, t);
      lca.add(i, t);
    }
  }
  hld.build();
  lca.build();
  for (int i = 0; i < n; ++i) {
    invt[hld.t[i]] = i;
  }
#ifdef __WATASHI__
  for (int i = 0; i < n; ++i) {
    if (hld.c[i].empty()) {
      continue;
    }
    for (int j: hld.c[i]) {
      printf(" %d", j);
    }
    puts("");
  }
#endif

  scanf("%d", &m);
  st.init(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &t, &q[i].a);
    --q[i].a;
    if (t == 1) {
      st.del(hld.t[q[i].a], i);
      q[i].x = -1;
    } else {
      scanf("%d%d%d", &q[i].b, &q[i].k, &q[i].x);
      --q[i].b;
      --q[i].k;
      q[i].y = i;
    }
  }
  st.build();

  for (int i = 0; i < m; ++i) {
    if (q[i].x == -1) {
      continue;
    } else {
      q[i].ans = -1;
      q[i].k += st.good(1, 0, st.n, hld.t[q[i].a], hld.t[q[i].a] + 1, q[i].x, q[i].y);
      // q[i].k += st.good(1, 0, st.n, hld.t[q[i].b], hld.t[q[i].b] + 1, q[i].x, q[i].y);
      for (auto j: keypath(q[i].a, q[i].b)) {
        int a = hld.t[j.first], b = hld.t[j.second], good;
        if (a <= b) {
          good = st.good(1, 0, st.n, a, b + 1, q[i].x, q[i].y);
        } else {
          good = st.good(1, 0, st.n, b, a + 1, q[i].x, q[i].y);
        }
        // printf("[%d] %d -> %d (%d)\n", i, j.first + 1, j.second + 1, good);
        // printf("a = %d, b = %d, k = %d\n", a, b, q[i].k);
        if (q[i].k >= good) {
          q[i].k -= good;
        } else if (a <= b) {
          q[i].ans = st.index(1, 0, st.n, a, b + 1, q[i].x, q[i].y, q[i].k);
          break;
        } else {
          q[i].k = good - 1 - q[i].k;
          q[i].ans = st.index(1, 0, st.n, b, a + 1, q[i].x, q[i].y, q[i].k);
          break;
        }
      }
      if (q[i].ans != -1) {
        q[i].ans = invt[q[i].ans];
        if (q[i].ans == q[i].b) {
          q[i].ans = -1;
        } else {
          ++q[i].ans;
        }
      }
      printf("%d\n", q[i].ans);
    }
  }

  return 0;
}
