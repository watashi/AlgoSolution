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

vector<int> gao(int v, int p, vector<pair<int, int> >& ans) {
  int rem = 0;
  bool leaf = true;
  priority_queue<pair<int, int> > pq;

  for (int w: bbt.e[v]) {
    if (w != p) {
      vector<int> sub = gao(w, v, ans);
      rem += sub.size();
      leaf = false;
      pq.push({sub.size() > 1 ? sub.back() : -1, sub.front()});
    }
  }

  if (leaf) {
    return {v};
  } else {
    while (rem > 2) {
      pair<int, int> a, b;
      assert(pq.size() >= 2);
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      rem -= 2;
      ans.push_back({a.second, b.second});
      if (a.first != -1) {
        pq.push({-1, a.first});
      }
      if (b.first != -1) {
        pq.push({-1, b.first});
      }
    }

    vector<int> ret;
    while (!pq.empty()) {
      if (pq.top().first != -1) {
        ret.push_back(pq.top().first);
      }
      ret.push_back(pq.top().second);
      pq.pop();
    }
    assert(ret.size() == 1 || ret.size() == 2);
    return ret;
  }
}

int dfs(int v, int p, int bad) {
  if (v == bad) {
    return -1;
  } else {
    int ret = v;
    for (int w: bbt.e[v]) {
      if (w != p) {
        int t = dfs(w, v, bad);
        if (t == -1) {
          return -1;
        } else {
          ret = t;
        }
      }
    }
    return ret;
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
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; ++i) {
      if (bbt.id(i) == i) {
        v.push_back(i);
      }
    }

    if (v.size() == 2) {
      ans.push_back({v[0], v[1]});
    } else {
      int root = -1;
      for (int i: v) {
        if (bbt.e[i].size() > 1) {
          root = i;
        }
      }
      vector<int> rem = gao(root, -1, ans);
      if (rem.size() == 1) {
        for (int i: bbt.e[root]) {
          // any leaf whose LCA with rem[0] is root
          int j = dfs(i, root, rem[0]);
          if (j != -1) {
            ans.push_back({rem[0], j});
            break;
          }
        }
      } else if (rem.size() == 2) {
        ans.push_back({rem[0], rem[1]});
      } else {
        throw rem.size();
      }
    }

    printf("%d\n", (int)ans.size());
    for (auto i: ans) {
      printf("%d %d\n", i.first + 1, i.second + 1);
    }
  }

  return 0;
}
