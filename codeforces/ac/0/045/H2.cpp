#include <queue>
#include <stack>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

template<int MAXN>
struct DisjointSet {
  int p[MAXN];

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    p[i] = j;
    return i != j;
  }
};

template<int MAXN>
struct Tarjan {
  int n;
  vector<int> e[MAXN];

  vector<int> cut;
  vector<pair<int, int> > bridge;
  vector<vector<pair<int, int> > > bcc;

  void init(int size) {
    n = size;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }

  void add(int a, int b) {
    // assert(find(a.begin(), a.end(), b) == a.end());
    e[a].push_back(b);
    e[b].push_back(a);
  }

  int dfn[MAXN], low[MAXN];
  int timestamp;
  stack<pair<int, int> > s;

  void dfs(int v, int p) {
    int part = p == -1 ? 0 : 1;
    dfn[v] = low[v] = timestamp++;
    for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
      pair<int, int> f = make_pair(min(v, *w), max(v, *w));
      if (dfn[*w] == -1) {
        s.push(f);
        dfs(*w, v);
        low[v] = min(low[v], low[*w]);
        if (dfn[v] <= low[*w]) {
          // articulation point
          if (++part == 2) {
            cut.push_back(v);
          }
          // articulation edge
          if (dfn[v] < low[*w]) {
            bridge.push_back(f);
          }
          // biconnected component (2-vertex-connected)
          vector<pair<int, int> > t;
          do {
            t.push_back(s.top());
            s.pop();
          } while (t.back() != f);
          bcc.push_back(t);
        }
      } else if (*w != p && dfn[*w] < dfn[v]) {
        s.push(f);
        low[v] = min(low[v], dfn[*w]);
      }
    }
  }

  void gao() {
    cut.clear();
    bridge.clear();
    bcc.clear();

    timestamp = 0;
    stack<pair<int, int> >().swap(s);
    fill(dfn, dfn + n, -1);

    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) {
        dfs(i, -1);
      }
    }
  }
};

template<int MAXN>
struct BridgeBlockTree {
  Tarjan<MAXN> bcc;
  DisjointSet<MAXN> ds;
  vector<int> e[MAXN];

  void init(int n) {
    bcc.init(n);
    ds.init(n);
  }

  void add(int a, int b) {
    bcc.add(a, b);
  }

  void gao() {
    bcc.gao();
    for (const auto& i: bcc.bcc) {
      if (i.size() > 1) {
        for (const auto& j: i) {
          ds.setp(j.first, j.second);
        }
      }
    }
    for (const auto& i: bcc.bridge) {
      int a = ds.getp(i.first);
      int b = ds.getp(i.second);
      e[a].push_back(b);
      e[b].push_back(a);
    }
  }

  int id(int v) {
    return ds.getp(v);
  }
};

const int MAXN = 1024;

BridgeBlockTree<MAXN> bbt;

void dfs(int v, int p, vector<int>& ret) {
  bool leaf = true;
  for (int w: bbt.e[v]) {
    if (w != p) {
      leaf = false;
      dfs(w, v, ret);
    }
  }
  if (leaf) {
    ret.push_back(v);
  }
}

int main() {
  int n, m, a, b;

  scanf("%d%d", &n, &m);
  bbt.init(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    bbt.add(a, b);
  }
  bbt.gao();

  if (n == 2) {
    puts("-1");
  } else {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (bbt.e[i].size() == 1) {
        v.push_back(i);
      } else if (bbt.e[i].size() > 1) {
        v.clear();
        dfs(i, -1, v);
        break;
      }
    }

    if (v.size() % 2 != 0) {
      v.push_back(v.back());
    }
    int ans = (int)v.size() / 2;
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) {
      printf("%d %d\n", v[i] + 1, v[ans + i] + 1);
    }
  }

  return 0;
}
