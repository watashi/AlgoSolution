#include <set>
#include <queue>
#include <limits>
#include <vector>
#include <cstdio>
#include <utility>
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
      } else if (maxc[sink] == 0 || minw[sink] > 0) { // minw[sink] > 0
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

const int MAXN = 218;
const int INF = 1 << 20;

MinCostMaxFlow<MAXN, int, int> mcmf;
int a[MAXN], b[MAXN], c[MAXN];

inline int IN(int i) { return i << 1; }
inline int OUT(int i) { return IN(i) ^ 1; }

int gao(int n, int m, const set<int>& v) {
  mcmf.init(OUT(n) + 2, IN(n), OUT(n) + 1);
  mcmf.addEdge(OUT(n), OUT(n) + 1, m, 0);
  for (int i = 0; i < n; ++i) {
    mcmf.addEdge(IN(n), IN(i), 1, 0);
    mcmf.addEdge(OUT(i), OUT(n), 1, 0);
    if (v.count(i) > 0) {
      mcmf.addEdge(IN(i), OUT(i), 1, -1);
    }
  }
  for (set<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
    for (set<int>::const_iterator j = v.begin(); j != v.end(); ++j) {
      if (b[*i] <= a[*j] && c[*i] <= c[*j]) {
        mcmf.addEdge(OUT(*i), IN(*j), 1, 0);
      }
    }
  }
  return mcmf.gao().second;
}

int main() {
  int n, m;
  set<int> ans;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }

  for (int i = 0; i < n; ++i) {
    ans.insert(i);
    int tmp = gao(n, m, ans);
    if (-tmp < (int)ans.size()) {
      ans.erase(i);
    }
    printf("%d", ans.count(i));
  }
  puts("");

  return 0;
}

/*
id => 4706664
date => 20:49:465 Jan 2013
user => watashi
pname => The Best Picture in the Galaxy
lang => C++
status => Accepted
testid => 
time => 0.171
mem => 216 KB
pid => 1949
*/
