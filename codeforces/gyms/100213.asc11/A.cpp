#include <queue>
#include <cstdio>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int MAXM = MAXN * MAXN;

struct Edge {
  int v, c, w;
  Edge() { }
  Edge(int v, int c, int w) : v(v), c(c), w(w) { }
};

struct NegativeCostCircuitExistsException {
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
  int maxc[MAXN];
  int minw[MAXN];
  int pre[MAXN];
  int d[MAXN];

  // assert @return == true
  bool _spfa() {
    queue<int> q;

    fill(mark, mark + n, false);
    fill(maxc, maxc + n, 0);
    fill(minw, minw + n, numeric_limits<int>::max());
    fill(pre, pre + n, -1);
    fill(d, d + n, 0);
    mark[source] = true;
    maxc[source] = numeric_limits<int>::max();
    minw[source] = 0;
    // pre[source] = source;
    q.push(source);
    while (!q.empty()) {
      int cur = q.front();
      // fprintf(stderr, "%d %d %d\n", cur, maxc[cur], minw[cur]);
      mark[cur] = false;
      q.pop();
      for (size_t i = 0; i < e[cur].size(); ++i) {
        int id = e[cur][i];
        int v = edge[id].v;
        int c = min(maxc[cur], edge[id].c);
        if (c == 0) { // ~~
          continue;
        }
        int w = minw[cur] + edge[id].w;
        if (minw[v] > w || (minw[v] == w && maxc[v] < c)) {
          maxc[v] = c;
          minw[v] = w;
          pre[v] = id;  // e not v !
          d[v] = d[cur] + 1;
          if (d[v] >= n) {
            return false;
          }
          if (!mark[v]) {
            mark[v] = true;
            q.push(v);
          }
        }
      }
    }

    return true;
  }

  pair<int, int> gao() {
    int sumc = 0, sumw = 0;

    while (true) {
      if (!_spfa()) {
        throw NegativeCostCircuitExistsException();
      } else if (maxc[sink] == 0) {
        break;
      } else if (minw[sink] >= 0) {
        break;  // different HERE!!
      } else {
        int c = maxc[sink];
        sumc += c;
        sumw += c * minw[sink];
        int cur = sink;
        while (cur != source) {
          int id = pre[cur];
          edge[id].c -= c;
          edge[id ^ 1].c += c;
          cur = edge[id ^ 1].v;
        }
      }
    }

    return make_pair(sumc, sumw);
  }
};

MinCostMaxFlow mcmf;

const int INF = 0x77777777;

int main() {
  int n, m, a, b, c, d;

#ifndef __WATASHI__
  freopen("beer.in", "r", stdin);
  freopen("beer.out", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  mcmf.init(n + 1, 0, n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &d);
    mcmf.addEdge(i, n, INF, -d);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    --a;
    --b;
    mcmf.addEdge(a, b, c, d);
    mcmf.addEdge(b, a, c, d);
  }
  printf("%d\n", -mcmf.gao().second);

  return 0;
}


