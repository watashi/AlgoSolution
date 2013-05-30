#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int MAXM = 4096;
inline int RE(int i) { return i ^ 1; }

struct Edge {
  int v;
  int c;
};

struct ExtFlowNetwork {
  int n, m, source, sink;
  vector<int> e[MAXN];
  Edge edge[MAXM * 2];

  void init(int n, int source, int sink) {	// if no source & sink, then source = sink = -1
    this->n = n;
    this->m = 0;
    this->source = source;
    this->sink = sink;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }

  void addEdge(int a, int b, int c) {
    edge[m].v = b;
    edge[m].c = c;
    e[a].push_back(m);
    edge[m + 1].v = a;
    edge[m + 1].c = 0;
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
} fn;

int re, r, c, h, v, s, t;
char str[MAXN][MAXN];
vector<string> ans;

void gao(char color) {
  int cr, cc;
  vector<string> vs;
  static char buf[1024];
  static pair<int, int> p[MAXN][MAXN];

  cr = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (str[i][j] != color) {
        continue;
      }
      int k = j;
      while (k < c && str[i][k] == color) {
        p[i][k].first = cr;
        ++k;
      }
      sprintf(buf, "h %d %d %d %d %c", i + 1, j + 1, i + 1, k, color);
      vs.push_back(buf);
      ++cr;
      j = k - 1;
    }
  }

  cc = 0;
  for (int j = 0; j < c; ++j) {
    for (int i = 0; i < r; ++i) {
      if (str[i][j] != color) {
        continue;
      }
      int k = i;
      while (k < r && str[k][j] == color) {
        p[k][j].second = cc;
        ++k;
      }
      sprintf(buf, "v %d %d %d %d %c", i + 1, j + 1, k, j + 1, color);
      vs.push_back(buf);
      ++cc;
      i = k - 1;
    }
  }

  fn.init(cr + cc + 2, cr + cc, cr + cc + 1);
  for (int i = 0; i < cr; ++i) {
    fn.addEdge(cr + cc, i, h);
  }
  for (int j = 0; j < cc; ++j) {
    fn.addEdge(cr + j, cr + cc + 1, v);
  }
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (str[i][j] == color) {
        sprintf(buf, "s %d %d %c", i + 1, j + 1, color);
        vs.push_back(buf);
        fn.addEdge(p[i][j].first, cr + p[i][j].second, s);
      }
    }
  }

  t += fn.sap();
  fn._bfs();
  for (int i = 0; i < fn.m; i += 2) {
    if (fn.d[fn.edge[i].v] != fn.n && fn.d[fn.edge[RE(i)].v] == fn.n) {
      ans.push_back(vs[i >> 1]);
    }
  }
}

int main() {

#ifndef __WATASHI__
  freopen("painter.in", "r", stdin);
  freopen("painter.out", "w", stdout);
#endif
  scanf("%d%d%d%d%d", &r, &c, &h, &v, &s);
  for (int i = 0; i < r; ++i) {
    scanf("%s", str[i]);
  }

  t = 0;
  ans.clear();
  for (char color = 'a'; color <= 'z'; ++color) {
    gao(color);
  }
  printf("%d %d\n", t, (int)ans.size());
  for (vector<string>::const_iterator i = ans.begin(); i != ans.end(); ++i) {
    puts(i->c_str());
  }

  return 0;
}

