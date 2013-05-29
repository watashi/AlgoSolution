#include <queue>
#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// [module] MinCostMaxFlow

const int MAXN = 404;
const int MAXM = 40404;

struct Edge {
  short v, c, w;
  Edge() { }
  Edge(int v, int c, int w) : v(v), c(c), w(w) { }
};

struct MinCostMaxFlow {
  int n, m, source, sink;
  vector<int> e[MAXN];
  Edge edge[MAXM * 2];

  void init(int n, int source, int sink) {
    this->n = n;
    this->m = 0;
    this->source = source;
    this->sink = sink;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }

  void addEdge(int a, int b, int c, int w) {
    edge[m] = Edge(b, c, w);
    e[a].push_back(m++);
    edge[m] = Edge(a, 0, -w);
    e[b].push_back(m++);
  }

  bool mark[MAXN];
  int minw[MAXN];
  int pre[MAXN];

  void _spfa() {
    queue<int> q;

    fill(mark, mark + n, false);
    fill(minw, minw + n, numeric_limits<int>::max());
    fill(pre, pre + n, -1);
    mark[source] = true;
    minw[source] = 0;
    // pre[source] = source;
    q.push(source);
    while (!q.empty()) {
      int cur = q.front();
      mark[cur] = false;
      q.pop();
      for (vector<int>::const_iterator i = e[cur].begin(); i != e[cur].end(); ++i) {
        if (edge[*i].c == 0) {
          continue;
        }
        int v = edge[*i].v;
        int w = minw[cur] + edge[*i].w;
        if (minw[v] > w) {
          minw[v] = w;
          pre[v] = *i;
          if (!mark[v]) {
            mark[v] = true;
            q.push(v);
          }
        }
      }
    }
  }

  pair<int, int> gao() {
    int sumc = 0, sumw = 0;

    while (true) {
      _spfa();
      if (minw[sink] == numeric_limits<int>::max()) {
        break;
      } else {
        ++sumc;
        sumw += minw[sink];
        int cur = sink;
        while (cur != source) {
          int id = pre[cur];
          --edge[id].c;
          ++edge[id ^ 1].c;
          cur = edge[id ^ 1].v;
        }
      }
    }

    return make_pair(sumc, sumw);
  }
};

MinCostMaxFlow mcmf;

#define X(i) (i)
#define Y(i) (n + (i))
#define S() (n + m)
#define T() (S() + 1)

int main() {
  int n, m, c, t, y;

#ifndef __WATASHI__
  freopen("keeper.in", "r", stdin);
  freopen("keeper.out", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  mcmf.init(n + m + 2, S(), T());
  for (int i = 0; i < n; ++i) {
    mcmf.addEdge(S(), X(i), 1, 0);
    scanf("%d", &c);
    for (int j = 0; j < c; ++j) {
      scanf("%d", &t);
      mcmf.addEdge(X(i), Y(t - 1), 1, 1);
    }
  }
  for (int j = 0; j < m; ++j) {
    mcmf.addEdge(Y(j), T(), 1, 0);
  }
  y = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    if (t > 0) {
      ++y;
      mcmf.addEdge(X(i), Y(t - 1), 1, 0);
    }
  }

  pair<int, int> ans = mcmf.gao();
  printf("%d %d\n", ans.first, y - (ans.first - ans.second));
  for (int i = 0; i < n; ++i) {
    t = 0;
    for (vector<int>::const_iterator j = mcmf.e[i].begin(); t == 0 && j != mcmf.e[i].end(); ++j) {
      if (mcmf.edge[*j].c == 0 && mcmf.edge[*j].v != S()) {
        t = mcmf.edge[*j].v - n + 1;
      }
    }
    printf("%d%c", t, (i == n - 1) ? '\n' : ' ');
  }

  return 0;
}


