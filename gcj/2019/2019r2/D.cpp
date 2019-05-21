#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

const int64_t MOD = 1000000007;

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
} scc;

vector<vector<int>> e;
vector<bool> reachable, nonzero;
vector<int64_t> m, dp;

int64_t gao(int v) {
  int64_t& ret = dp[v];
  if (ret == -1) {
    ret = m[v];
    if (nonzero[v]) {
      for (int i: e[v]) {
        if (scc.id[i] != scc.id[0]) {
          ret += gao(i);
        }
      }
      ret %= MOD;
    }
  }
  return ret;
}

int main() {
  int re, n, a, b;
  stack<int> q;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    scc.init(n);
    e = vector<vector<int>>(n);
    reachable = vector<bool>(n, false);
    nonzero = vector<bool>(n, false);
    m.resize(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a, &b);
      --a;
      --b;
      scc.add(i, a);
      scc.add(i, b);
      e[a].emplace_back(i);
      e[b].emplace_back(i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a);
      m[i] = a;
    }
    scc.gao();

    q = stack<int>();
    reachable[0] = true;
    q.push(0);
    while (!q.empty()) {
      a = q.top();
      q.pop();
      for (int i: e[a]) {
        if (!reachable[i]) {
          reachable[i] = true;
          q.push(i);
        }
      }
    }

    q = stack<int>();
    for (int i = 0; i < n; ++i) {
      if (m[i] != 0) {
        nonzero[i] = true;
        q.push(i);
      }
    }
    while (!q.empty()) {
      a = q.top();
      q.pop();
      for (int i: scc.e[a]) {
        if (!nonzero[i]) {
          nonzero[i] = true;
          q.push(i);
        }
      }
    }

    bool unbounded = false;
    for (int i = 0; i < n; ++i) {
      a = scc.e[i][0];
      b = scc.e[i][1];
      if (nonzero[i] && reachable[a] && reachable[b] &&
          (scc.id[a] == scc.id[i] || scc.id[b] == scc.id[i])) {
        unbounded = true;
      }
    }
    printf("Case #%d: ", ri);
    if (unbounded) {
      puts("UNBOUNDED");
    } else {
      int64_t ans = 0;
      dp = vector<int64_t>(n, -1);
      for (int i = 0; i < n; ++i) {
        if (scc.id[i] == scc.id[0]) {
          ans += gao(i);
        }
      }
      printf("%d\n", static_cast<int>(ans % MOD));
    }
  }

  return 0;
}
