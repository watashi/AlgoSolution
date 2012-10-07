#include <set>
#include <list>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXM = 18;
const int MAXN = 100100;
const int MOD = 1000000007;

struct LCA {
  vector<int> e[MAXN];
  int d[MAXN], p[MAXN][MAXM], q[MAXN][MAXM];

  void dfs_(int v, int f) {
    p[v][0] = f;
    for (int i = 1; i < MAXM; ++i) {
      p[v][i] = p[p[v][i - 1]][i - 1];
      q[v][i] = q[v][i - 1] + q[p[v][i - 1]][i - 1];
    }
    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f) {
        d[w] = d[v] + 1;
        dfs_(w, v);
      }
    }
  }

  void init(int n, vector<int> e[MAXN], int s) {
    copy(e, e + n, this->e);
    d[s] = 0;
    dfs_(s, s);
  }

  pair<int, int> up_(int v, int m) {
    int w = 0;
    for (int i = 0; i < MAXM; ++i) {
      if (m & (1 << i)) {
        w += q[v][i];
        v = p[v][i];
      }
    }
    return {v, w};
  }

  pair<int, int> lca(int a, int b) {
    int c;
    if (d[a] > d[b]) {
      swap(a, b);
    }
    tie(b, c) = up_(b, d[b] - d[a]);
    if (a == b) {
      c += q[a][0];
      return {a, c};
    } else {
      for (int i = MAXM - 1; i >= 0; --i) {
        if (p[a][i] != p[b][i]) {
          c += q[a][i] + q[b][i];
          a = p[a][i];
          b = p[b][i];
        }
      }
      c += q[a][0] + q[b][0];
      c += q[p[a][0]][0];
      return {p[a][0], c};
    }
  }
} lca;

int id[MAXN], ts[MAXN], sz[MAXN], bin[MAXN];
set<int> e[MAXN];
vector<int> ee[MAXN];

list<int> s;

void dfs(int v, int p) {
  static int timestamp = 0;
  s.push_front(v);
  ts[v] = timestamp++;
  for (int w: e[v]) {
    if (w == p) {
      continue;
    } else if (ts[w] == -1) {
      dfs(w, v);
    } else if (ts[w] < ts[v]) {
      for (int i: s) {
        id[i] = w;
        if (i == w) {
          break;
        }
      }
    }
  }
  s.pop_front();
}

int main() {
  int n, m, a, b;

  bin[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    bin[i] = bin[i - 1] << 1;
    if (bin[i] >= MOD) {
      bin[i] -= MOD;
    }
  }

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    e[a].insert(b);
    e[b].insert(a);
  }
  for (int i = 0; i < n; ++i) {
    id[i] = i;
    ts[i] = -1;
  }
  ts[0] = 0;
  dfs(0, 0);

  for (int i = 0; i < n; ++i) {
    if (id[i] != i) {
      ++sz[id[i]];
      e[id[i]].insert(e[i].begin(), e[i].end());
    }
  }
  for (int i = 0; i < n; ++i) {
    if (id[i] == i) {
      if (sz[i] > 0) {
        lca.q[i][0] = 1;
      }
      set<int> st;
      for (int j: e[i]) {
        if (id[j] != i) {
          st.insert(id[j]);
        }
      }
      ee[i].insert(ee[i].begin(), st.begin(), st.end());
    }
  }
  lca.init(n, ee, id[0]);

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    // printf("(%d,%d) = %d\n", id[a], id[b], lca.lca(id[a], id[b]).first);
    printf("%d\n", bin[lca.lca(id[a], id[b]).second]);
  }

  return 0;
}

