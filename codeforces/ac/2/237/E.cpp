#include <queue>
#include <limits>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

template<int MAXN, typename T = int, typename S = T>
struct MinCostMaxFlow {
  struct NegativeCostCircuitExistsException {
  };

  struct Edge {
    int v;
    T c;
    S w;
    int b;
    Edge(int v, T c, S w, int b) : v(v), c(c), w(w), b(b) { }
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

  void addEdge(int a, int b, T c, S w) {
    e[a].push_back(Edge(b, c, w, e[b].size()));
    e[b].push_back(Edge(a, 0, -w, e[a].size() - 1));  // TODO
  }

  bool mark[MAXN];
  T maxc[MAXN];
  S minw[MAXN];
  int dist[MAXN];
  Edge* prev[MAXN];

  bool _spfa() {
    queue<int> q;
    fill(mark, mark + n, false);
    fill(maxc, maxc + n, 0);
    fill(minw, minw + n, numeric_limits<S>::max());
    fill(dist, dist + n, 0);
    fill(prev, prev + n, (Edge*)NULL);
    mark[source] = true;
    maxc[source] = numeric_limits<S>::max();
    minw[source] = 0;

    q.push(source);
    while (!q.empty()) {
      int cur = q.front();
      mark[cur] = false;
      q.pop();
      for (typename vector<Edge>::iterator it = e[cur].begin(); it != e[cur].end(); ++it) {
        T c = min(maxc[cur], it->c);
        if (c == 0) {
          continue;
        }

        int v = it->v;
        S w = minw[cur] + it->w;
        if (minw[v] > w || (minw[v] == w && maxc[v] < c)) { // TODO
          maxc[v] = c;
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

  pair<T, S> gao() {
    T sumc = 0;
    S sumw = 0;
    while (true) {
      if (!_spfa()) {
        throw NegativeCostCircuitExistsException();
      } else if (maxc[sink] == 0) {
        break;
      } else {
        T c = maxc[sink];
        sumc += c;
        sumw += c * minw[sink];

        int cur = sink;
        while (cur != source) {
          Edge* e1 = prev[cur];
          e1->c -= c;
          Edge* e2 = &e[e1->v][e1->b];
          e2->c += c;
          cur = e2->v;
        }
      }
    }
    return make_pair(sumc, sumw);
  }
};

const int MAXN = 4096;
const int SIGMA = 26;

MinCostMaxFlow<MAXN> mcmf;

vector<int> read() {
  static char buf[MAXN];
  vector<int> ret(SIGMA);

  scanf("%s", buf);
  for (int i = 0; buf[i] != '\0'; ++i) {
    ++ret[buf[i] - 'a'];
  }

  return ret;
}

int main() {
  int n, m, s = 26, t = 27, c = 0;
  pair<int, int> ans;
  vector<int> v;

  v = read();
  scanf("%d", &n);
  mcmf.init(t + 1 + n, s, t);
  for (int i = 0; i < SIGMA; ++i) {
    mcmf.addEdge(s, i, v[i], 0);
    c += v[i];
  }
  for (int i = 0; i < n; ++i) {
    v = read();
    scanf("%d", &m);
    for (int j = 0; j < SIGMA; ++j) {
      mcmf.addEdge(j, t + 1 + i, v[j], 0);
    }
    mcmf.addEdge(t + 1 + i, t, m, i + 1);
  }

  ans = mcmf.gao();
  printf("%d\n", ans.first == c ? ans.second : -1);

  return 0;
}

