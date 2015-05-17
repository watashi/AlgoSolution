#include <set>
#include <stack>
#include <tuple>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct SCCTarjan {
  int n;
  vector<vector<int> > e;

  vector<int> id;
  vector<vector<int> > scc;

  void init(int n) {
    this->n = n;
    vector<vector<int> >(n).swap(e);
    id.resize(n);
    dfn.resize(n);
    low.resize(n);
  }

  void add(int a, int b) {
    e[a].push_back(b);
  }

  vector<int> dfn, low;
  int timestamp;
  stack<int> s;

  void dfs(int v) {
    dfn[v] = timestamp++;
    low[v] = dfn[v];
    s.push(v);
    for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
      if (dfn[*w] == -1) {
        dfs(*w);
        low[v] = min(low[v], low[*w]);
      } else if (dfn[*w] != -2) {
        low[v] = min(low[v], dfn[*w]);
      }
    }

    if (low[v] == dfn[v]) {
      vector<int> t;
      do {
        int w = s.top();
        s.pop();
        id[w] = (int)scc.size();
        t.push_back(w);
        dfn[w] = -2;
      } while (t.back() != v);
      scc.push_back(t);
    }
  }

  int gao() {
    scc.clear();
    stack<int>().swap(s);
    timestamp = 0;

    fill(dfn.begin(), dfn.end(), -1);
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) {
        dfs(i);
      }
    }
    return (int)scc.size();
  }
};

bool gao(int n, int m, const pair<int, pair<int, int>> a[]) {
  SCCTarjan scc;
  scc.init(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    tie(x, y) = a[i].second;
    scc.add(x, y);
  }
  int nscc = scc.gao();

  vector<int> d(nscc);
  vector<set<int>> p(nscc);
  for (int i = 0; i < m; ++i) {
    int x, y;
    tie(x, y) = a[i].second;
    x = scc.id[x];
    y = scc.id[y];
    if (x != y && p[y].emplace(x).second) {
      ++d[x];
    }
  }

  stack<int> s;
  for (int i = 0; i < nscc; ++i) {
    if (d[i] == 0) {
      s.push(i);
    }
  }

  int rem = nscc;
  while (!s.empty()) {
    int v = s.top();
    s.pop();
    --rem;
    if (!s.empty()) {
      return false;
    } else {
      for (int w: p[v]) {
        if (--d[w] == 0) {
          s.push(w);
        }
      }
    }
  }

  return rem == 0;
}

int main() {
  int n, m, a, b, c;
  vector<pair<int, pair<int, int>>> e;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    e.emplace_back(c, make_pair(a - 1, b - 1));
  }
  sort(e.begin(), e.end());

  int lo = 0, hi = m + 1;
  while (lo < hi) {
    int mi = (lo + hi) / 2;
    if (!gao(n, mi, e.data())) {
      lo = mi + 1;
    } else {
      hi = mi;
    }
  }
  printf("%d\n", hi == 0
               ? 0
               : hi > m // wtf: hi == m
               ? -1
               : e[hi - 1].first);

  return 0;
}
