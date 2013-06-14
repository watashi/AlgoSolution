#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int MAXM = 512;
const double EPS = 1e-8;

inline int RE(int i) { return i ^ 1; }

struct Edge {
  int v;
  double c;
};

struct FlowNetwork {
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

  void addEdge(int a, int b, double c) {
    edge[m].v = b;
    edge[m].c = c;
    e[a].push_back(m);
    edge[m + 1].v = a;
    edge[m + 1].c = c;    // 0
    e[b].push_back(m + 1);
    m += 2;
  }

  // shortest augmenting path
  int c[MAXN];        //*
  int d[MAXN];        //*
  int done[MAXN];        //*
  int path[MAXN];        //*
  int len;            //*
  
  void _bfs() {
    queue<int> q;
    fill(c, c + n, 0);
    fill(d, d + n, n);    // n->inf
    d[sink] = 0;
    q.push(sink);
    while (!q.empty()) {
      int cur = q.front();
      ++c[d[cur]];
      for (size_t i = 0; i < e[cur].size(); ++i) {
        int id = e[cur][i];
        if (d[edge[id].v] == n && edge[RE(id)].c > EPS) {
          d[edge[id].v] = d[cur] + 1;
          q.push(edge[id].v);
        }
      }
      q.pop();
    }
  }

  void _retreat(int v) {
    --c[d[v]];
    d[v] = n;    // n->inf
    for (size_t i = 0; i < e[v].size(); ++i) {
      Edge &arc = edge[e[v][i]];
      if (d[v] > d[arc.v] + 1 && arc.c > EPS) {
        d[v] = d[arc.v] + 1;
        done[v] = i;    // ~
      }
    }
    ++c[d[v]];
  }

  double _augment() {
    int todo = -1;
    double flow = 1e100;
    for (int i = 0; i < len; ++i) {
      Edge &arc = edge[e[path[i]][done[path[i]]]];
      if (arc.c < flow) {
        flow = arc.c;
        todo = i;
      }
    }
    for (int i = 0; i < len; ++i) {
      int id = e[path[i]][done[path[i]]];
      edge[id].c -= flow;
      edge[RE(id)].c += flow;
    }
    len = todo;
    return flow;
  }

  double sap() {
    double flow = 0;
    _bfs();
    fill(done, done + n, 0);
    len = 0;
    path[0] = source;
    while (d[source] != n/* && len >= 0*/) {    // n->inf
      int back = path[len];
      if (back == sink) {
        flow += _augment();
      } else {
        while (done[back] < (int)e[back].size()) {
          Edge &arc = edge[e[back][done[back]]];
          if (d[arc.v] == d[back] - 1 && arc.c > EPS) {
            break;
          } else {
            ++done[back];
          }
        }
        if (done[back] == (int)e[back].size()) {
          if (c[d[back]] == 1) {
            break;    // return;
          } else {
            _retreat(back);
            if (back != source) {    // !!
              --len;    // pop
            }
          }
        } else {
          path[++len] = edge[e[back][done[back]]].v;    // push
        }
      }
    }
    return flow;
  }
  // end of sap
};

int a[MAXM], b[MAXM];
double c[MAXM];
FlowNetwork fn;

int main() {
  bool blank = false;
  int n, m;
  double l, r, lr, flow;

#ifndef __WATASHI__
  freopen("network.in", "r", stdin);
  freopen("network.out", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%lf", &a[i], &b[i], &c[i]);
    --a[i];
    --b[i];
  }
  if (blank) {
    puts("");
  } else {
    blank = true;
  }

  l = *min_element(c, c + n);
  r = *max_element(c, c + n);
  while (r - l > EPS) {
    fn.init(n, 0, n - 1);
    lr = (l + r) / 2;
    flow = 0;
    for (int i = 0; i < m; ++i) {
      if (c[i] <= lr) {
        flow += c[i] - lr;
      } else {
        fn.addEdge(a[i], b[i], c[i] - lr);
      }
    }
    flow += fn.sap();
    if (flow > 0) {
      l = lr;
    } else {
      r = lr;
    }
  }

  fn.init(n, 0, n - 1);
  for (int i = 0; i < m; ++i) {
    if (c[i] <= r) {
      fn.addEdge(0, 0, 0);
    } else {
      fn.addEdge(a[i], b[i], c[i] - r);
    }
  }
  fn.sap();
  fn._bfs();
  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    if (c[i] <= r || ((fn.d[a[i]] == fn.n) ^ (fn.d[b[i]] == fn.n))) {
      ans.push_back(i + 1);
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i]);
  }
  puts("");

  return 0;
}

/*
Run ID      Submit Time      Judge Status      Problem ID      Language      Run Time(ms)      Run Memory(KB)      User Name
2130666     2010-03-28 21:22:02     Accepted     2676     C++     60     200     watashi@Zodiac
// EPS = 1e-6 => 50ms
// EPS = 1e-4 => 40ms
// EPS = 1e-3 => 30ms
// EPS = 1e-2 => 20ms
// EPS = 0.1 => 20ms
// EPS = 0.3 => AC
// EPS = 0.5 => WA
*/
