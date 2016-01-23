#include <queue>
#include <limits>
#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

template<int MAXN, typename S>
struct MinCostMaxFlow {
  struct NegativeCostCircuitExistsException {
  };

  struct Edge {
    int v;
    bool c;
    S w;
    int b;
    Edge(int v, bool c, S w, int b) : v(v), c(c), w(w), b(b) { }
  };

  int n, source, sink;
  vector<Edge> e[MAXN];

  void init(int n, int source, int sink) {
    this->n = n;
    this->source = source;
    this->sink = sink;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }

  void addEdge(int a, int b, S w) {
    e[a].push_back(Edge(b, true, w, e[b].size()));
    e[b].push_back(Edge(a, false, -w, e[a].size() - 1));  // TODO
  }

  bool mark[MAXN];
  S minw[MAXN];
  int dist[MAXN];
  Edge* prev[MAXN];

  bool _spfa() {
    queue<int> q;
    fill(mark, mark + n, false);
    fill(minw, minw + n, numeric_limits<S>::max());
    fill(dist, dist + n, 0);
    fill(prev, prev + n, (Edge*)NULL);
    mark[source] = true;
    minw[source] = 0;

    q.push(source);
    while (!q.empty()) {
      int cur = q.front();
      mark[cur] = false;
      q.pop();
      for (typename vector<Edge>::iterator it = e[cur].begin(); it != e[cur].end(); ++it) {
        if (!it->c) {
          continue;
        }
        int v = it->v;
        S w = minw[cur] + it->w;
        if (minw[v] > w) { // TODO
          minw[v] = w;
          dist[v] = dist[cur] + 1;
          if (dist[v] >= n) {
            return false;
          }
          prev[v] = &*it;
          if (!mark[v]) {
            mark[v] = true;
            q.push(v);
          }
        }
      }
    }
    return true;
  }

  pair<int, S> gao() {
    int sumc = 0;
    S sumw = 0;
    while (true) {
      if (!_spfa()) {
        throw NegativeCostCircuitExistsException();
      } else if (minw[sink] == numeric_limits<S>::max()) {
        break;
      } else {
        ++sumc;
        sumw += minw[sink];

        int cur = sink;
        while (cur != source) {
          Edge* e1 = prev[cur];
          e1->c = false;
          Edge* e2 = &e[e1->v][e1->b];
          e2->c = true;
          cur = e2->v;
        }
      }
    }
    return make_pair(sumc, sumw);
  }
};

const int MAXN = 64;
const int INF = 1000000007;

MinCostMaxFlow<MAXN, int> mcmf;
vector<vector<int>> tree;
vector<vector<int>> cost;
int penalty;

vector<int> minCost(int m, int p, const vector<vector<int>>& w) {
  int n = w.size(), s = n + m, t = s + 1;
  vector<int> ret(m);

  if (n >= m) {
    fill(ret.begin(), ret.end(), INF);
  } else {
    // TODO: optimize me from O(n^4) to O(n^3)
    for (int k = 0; k < m; ++k) {
      mcmf.init(t + 1, s, t);
      for (int i = 0; i < n; ++i) {
        mcmf.addEdge(s, i, 0);
        for (int j = 0; j < m; ++j) {
          mcmf.addEdge(i, n + j, w[i][j]);
        }
      }
      for (int j = 0; j < m; ++j) {
        if (j != k) {
          mcmf.addEdge(n + j, t, 0);
        }
      }
      ret[k] = mcmf.gao().second;
    }
  }

  for (auto& i: w) {
    p += *min_element(i.begin(), i.end());
  }
  for (int& i: ret) {
    i = min(i, p);
  }

  return ret;
}

vector<int> gao(int v, int p) {
  vector<int> ret = cost[v];

  for (int i: tree[v]) {
    if (i == p) {
      continue;
    }

    vector<vector<int>> grandchildren;
    for (int j: tree[i]) {
      if (j != v) {
        grandchildren.emplace_back(gao(j, i));
      }
    }
    vector<int> tmp = minCost(ret.size(), penalty, grandchildren);
    for (int i = 0; i < (int)ret.size(); ++i) {
      ret[i] += tmp[i];
    }
  }

  return ret;
}

int main() {
  int re, n, m, a, b;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%d", &n, &m, &penalty);
    cost.resize(n);
    for (auto& i: cost) {
      i.resize(m);
      for (auto& j: i) {
        scanf("%d", &j);
      }
    }
    vector<vector<int>>(n).swap(tree);
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &a, &b);
      --a;
      --b;
      tree[a].emplace_back(b);
      tree[b].emplace_back(a);
    }

    vector<int> x = gao(0, 0);
    vector<int> y = n == 1 ? vector<int>{0} : gao(tree[0][0], tree[0][0]);
    printf("Case #%d: %d\n", ri,
      *min_element(x.begin(), x.end()) + *min_element(y.begin(), y.end()));
  }

  return 0;
}
