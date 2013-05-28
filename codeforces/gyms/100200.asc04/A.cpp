#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 808;
const int MAXM = 10101;
inline int RE(int i) { return i ^ 1; }

struct Edge {
  int v;
  int c;
};

struct ExtFlowNetwork {
  int n, m, source, sink;
  vector<int> e[MAXN];
  Edge edge[MAXM * 2];

  int diff[MAXN];		//*

  void init(int n, int source, int sink) {	// if no source & sink, then source = sink = -1
    this->n = n;
    this->m = 0;
    this->source = source;
    this->sink = sink;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
    fill(diff, diff + n, 0);
  }

  void addEdge2(int a, int b, int c) {
    edge[m].v = b;
    edge[m].c = c;
    e[a].push_back(m);
    edge[m + 1].v = a;
    edge[m + 1].c = c;
    e[b].push_back(m + 1);
    m += 2;
  }

  // shortest augmenting path
  int c[MAXN];		//*
  int d[MAXN];		//*
  int done[MAXN];		//*
  int path[MAXN];		//*
  int len;			//*

  void _bfs() {
    queue<int> q;
    fill(c, c + n, 0);
    fill(d, d + n, n);	// n->inf
    d[sink] = 0;
    q.push(sink);
    while (!q.empty()) {
      int cur = q.front();
      ++c[d[cur]];
      for (size_t i = 0; i < e[cur].size(); ++i) {
        int id = e[cur][i];
        if (d[edge[id].v] == n && edge[RE(id)].c > 0) {
          d[edge[id].v] = d[cur] + 1;
          q.push(edge[id].v);
        }
      }
      q.pop();
    }
  }

  void _retreat(int v) {
    --c[d[v]];
    d[v] = n;	// n->inf
    for (size_t i = 0; i < e[v].size(); ++i) {
      Edge &arc = edge[e[v][i]];
      if (d[v] > d[arc.v] + 1 && arc.c > 0) {
        d[v] = d[arc.v] + 1;
        done[v] = i;	// ~
      }
    }
    ++c[d[v]];
  }

  int _augment() {
    int todo = -1;
    int flow = 0x7fffff;
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

  int sap() {
    int flow = 0;
    _bfs();
    fill(done, done + n, 0);
    len = 0;
    path[0] = source;
    while (d[source] != n/* && len >= 0*/) {	// n->inf
      int back = path[len];
      if (back == sink) {
        flow += _augment();
      } else {
        while (done[back] < (int)e[back].size()) {
          Edge &arc = edge[e[back][done[back]]];
          if (d[arc.v] == d[back] - 1 && arc.c > 0) {
            break;
          } else {
            ++done[back];
          }
        }
        if (done[back] == (int)e[back].size()) {
          if (c[d[back]] == 1) {
            break;	// return;
          } else {
            _retreat(back);
            if (back != source) {	// !!
              --len;	// pop
            }
          }
        } else {
          path[++len] = edge[e[back][done[back]]].v;	// push
        }
      }
    }
    return flow;
  }
  // end of sap

  bool unique() {
    queue<int> q;
    vector<bool> mark(n, false);
    mark[source] = true;
    q.push(source);
    while (!q.empty()) {
      int cur = q.front();
      for (size_t i = 0; i < e[cur].size(); ++i) {
        Edge &arc = edge[e[cur][i]];
        if (!mark[arc.v]) {
          if (arc.c > 0) {
            mark[arc.v] = true;
            q.push(arc.v);
          }
        }
      }
      q.pop();
    }
    _bfs();
    for (size_t k = 0; k < mark.size(); ++k) {
      if (mark[k]) {
        for (size_t i = 0; i < e[k].size(); ++i) {
          Edge &arc = edge[e[k][i]];
          if (!mark[arc.v] && d[arc.v] == n) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main() {
  int n, m, s, t, a, b, c;
  ExtFlowNetwork fn;

  freopen("attack.in", "r", stdin);
  freopen("attack.out", "w", stdout);
  while (scanf("%d%d%d%d", &n, &m, &s, &t) != EOF && n > 0) {
    fn.init(n, s - 1, t - 1);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      fn.addEdge2(a - 1, b - 1, c);
    }
    fprintf(stderr, "%d\n", fn.sap());
    puts(fn.unique() ? "UNIQUE" : "AMBIGUOUS");
  }

  return 0;
}

