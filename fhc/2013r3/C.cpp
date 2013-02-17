#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 1234;
const long long INF = 0x7f7f7f7f7f;

struct SCC {
  int n;
  vector<int> e[MAXN];
  vector<int> re[MAXN];
  vector<int> ord;

  int id[MAXN], size[MAXN];

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
      re[i].clear();
    }
  }

  void add(int a, int b) {
    e[a].push_back(b);
    re[b].push_back(a);
  }

  void dfs(int v) {
    id[v] = v;
    for (int i: e[v]) {
      if (id[i] == -1) {
        dfs(i);
      }
    }
    ord.push_back(v);
  }

  void rdfs(int v, int p) {
    id[v] = p;
    ++size[p];
    for (int i: re[v]) {
      if (id[i] == -1) {
        rdfs(i, p);
      }
    }
  }

  void gao() {
    ord.clear();
    fill(id, id + n, -1);
    for (int i = 0; i < n; ++i) {
      if (id[i] == -1) {
        dfs(i);
      }
    }

    reverse(ord.begin(), ord.end());
    fill(id, id + n, -1);
    fill(size, size + n, 0);
    for (int i: ord) {
      if (id[i] == -1) {
        rdfs(i, i);
      }
    }
  }
} scc;

llint r[MAXN][MAXN];

llint gao(int n, int k, long long edge) {
  static bool mark[MAXN];

  scc.init(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && r[i][j] > edge) {
        scc.add(i, j);
      }
    }
  }
  scc.gao();

  fill(mark, mark + MAXN, true);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && r[i][j] > edge && scc.id[i] != scc.id[j]) {
        mark[scc.id[i]] = false;
      }
    }
  }

  vector<int> v;
  // printf("scc(@%lld): ", edge);
  for (int i = 0; i < n; ++i) {
    // printf("%d ", scc.id[i]);
    if (scc.id[i] == i && mark[i]) {
      v.push_back(scc.size[i]);
    }
  }
  // puts("");
  sort(v.begin(), v.end());
  if ((int)v.size() < k) {
    return INF;
  } else {
    return accumulate(v.begin(), v.begin() + k, 0);
  }
}

pair<llint, int> gao(int n, int k, int m, const vector<long long>& edge) {
  int lo = 0, hi = edge.size();
  while (lo < hi) {
    int mi = (lo + hi) / 2;
    if (gao(n, k, edge[mi]) <= m) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  fprintf(stderr, "%lld + %lld[%d]\n", edge[hi], gao(n, k, edge[hi]), m);
  fflush(stderr);
  return {edge[hi], gao(n, k, edge[hi])};
}

llint f1[MAXN * MAXN], f2[MAXN * MAXN];

void gen(llint x, llint a, llint b, llint m, llint ret[]) {
  for (int i = 0; i < MAXN * MAXN; ++i) {
    ret[i] = x;
    x = (a * x + b) % m;
  }
}

int main() {
  int re;
  int n, k;
  llint c, x, a, b, m, ans;
  vector<long long> edge;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%lld", &n, &k, &c);
    scanf("%lld%lld%lld%lld", &x, &a, &b, &m);
    gen(x, a, b, m, f1);
    scanf("%lld%lld%lld%lld", &x, &a, &b, &m);
    gen(x, a, b, m, f2);
    edge.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i > j) {
          r[i][j] = f1[i * (i - 1) / 2 + j];
        } else if (i < j) {
          r[i][j] = f2[j * (j - 1) / 2 + i];
        } else {
          r[i][j] = -1;
        }
        // printf("%4lld%c", r[i][j], j == n - 1 ? '\n' : ' ');
        if (r[i][j] != -1) {
          edge.push_back(r[i][j]);
        }
      }
    }
    edge.push_back(0);
    sort(edge.begin(), edge.end());
    edge.erase(unique(edge.begin(), edge.end()), edge.end());

    tie(ans, m) = gao(n, k, n, edge);
    ans += m * c;
    while (m > k) {
      long long tmp;
      tie(tmp, m) = gao(n, k, m - 1, edge);
      ans = min(ans, tmp + m * c);
    }

    printf("Case #%d: ", ri);
    printf("%lld\n", ans);
    fflush(stdout);
  }

  return 0;
}
