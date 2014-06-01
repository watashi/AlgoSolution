#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int MAXM = 1 << 20;
inline int RE(int i) { return i ^ 1; }

struct Edge {
  int v;
  int c;
};

struct FlowNetwork {
  int n, m, source, sink;
  vector<int> e[MAXN];
  Edge edge[MAXM * 2];

  void init(int n, int source, int sink) {  // if no source & sink, then source = sink = -1
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
  int c[MAXN];    //*
  int d[MAXN];    //*
  int done[MAXN];    //*
  int path[MAXN];    //*
  int len;      //*

  void _bfs() {
    queue<int> q;
    fill(c, c + n, 0);
    fill(d, d + n, n);  // n->inf
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
    d[v] = n;  // n->inf
    for (size_t i = 0; i < e[v].size(); ++i) {
      Edge &arc = edge[e[v][i]];
      if (d[v] > d[arc.v] + 1 && arc.c > 0) {
        d[v] = d[arc.v] + 1;
        done[v] = i;  // ~
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
    while (d[source] != n/* && len >= 0*/) {  // n->inf
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
            break;  // return;
          } else {
            _retreat(back);
            if (back != source) {  // !!
              --len;  // pop
            }
          }
        } else {
          path[++len] = edge[e[back][done[back]]].v;  // push
        }
      }
    }
    return flow;
  }
  // end of sap
} fn;

int r, c;

inline int S(int i, int j) {
  return (i * c + j) << 1;
}

inline int T(int i, int j) {
  return S(i, j) ^ 1;
}

const int MAXR = 512;
const int MAXC = 128;
bool s[MAXR][MAXC];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
  int re, n;
  int x0, y0, x1, y1;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%d", &c, &r, &n);
    fill(s[0], s[r], false);
    for (int k = 0; k < n; ++k) {
      scanf("%d%d%d%d", &y0, &x0, &y1, &x1);
      for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
          s[i][j] = true;
        }
      }
    }

    fn.init(T(r, 0) + 1, S(r, 0), T(r, 0));
    for (int j = 0; j < c; ++j) {
      fn.addEdge(S(r, 0), S(0, j), 1);
      fn.addEdge(T(r - 1, j), T(r, 0), 1);
    }
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (!s[i][j]) {
          fn.addEdge(S(i, j), T(i, j), 1);
          for (int k = 0; k < 4; ++k) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            if (0 <= ii && ii < r && 0 <= jj && jj < c) {
              fn.addEdge(T(i, j), S(ii, jj), 1);
            }
          }
        }
      }
    }
    int ans = fn.sap();

    printf("Case #%d: %d\n", ri, ans);
  }

  return 0;
}

