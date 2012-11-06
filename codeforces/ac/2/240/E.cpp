#include <list>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

template<int MAXN>
struct DisjointSet {
  int p[MAXN];

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return p[i] == i ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    if (i != j) {
      p[i] = j;
      return true;
    } else {
      return false;
    }
  }
};

const int MAXN = 100100;

DisjointSet<MAXN> ds, id;

struct Edge {
  int a, b, c, i;
};

Edge p[MAXN];
list<Edge> e[MAXN][2];

int main() {
#ifndef __WATASHI__
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, m, s;
  Edge t;
  queue<int> q;
  vector<Edge> v;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    t.i = i;
    scanf("%d%d%d", &t.a, &t.b, &t.c);
    --t.a;
    --t.b;
    e[t.b][t.c].push_back(t);
  }
  for (int i = 1; i < n; ++i) {
    q.push(i);
  }

  ds.init(n);
  id.init(n);
  while (!q.empty()) {
    s = id.getp(q.front());
    p[s].a = s;
    q.pop();
    for (int i = 0; i < 2 && p[s].a == s; ++i) {
      while (!e[s][i].empty() && p[s].a == s) {
        t = e[s][i].front();
        p[s].a = id.getp(t.a);
        p[s].b = s;
        p[s].c = i;
        e[s][i].pop_front();
      }
    }
    if (p[s].a == s) {
      puts("-1");
      return 0;
    }

    v.push_back(t);
    if (!ds.setp(t.a, s)) {
      list<Edge> ee[2];
      for (int i = s, j; ; i = j) {
        j = id.getp(p[i].a);
        id.setp(i, s);
        if (p[i].c == 0) {
          ee[0].splice(ee[0].end(), e[i][0]);
          ee[1].splice(ee[1].end(), e[i][1]);
        } else {
          ee[0].splice(ee[0].end(), e[i][1]);
        }
        if (j == s) {
          break;
        }
      }
      e[s][0].swap(ee[0]);
      e[s][1].swap(ee[1]);
      q.push(s);
    }
  }

  for (Edge i: v) {
    p[i.b] = i;
  }
  v.clear();
  for (int i = 1; i < n; ++i) {
    if (p[i].c > 0) {
      v.push_back(p[i]);
    }
  }
  printf("%d\n", (int)v.size());
  for (Edge i: v) {
    printf("%d ", i.i + 1);
  }

  return 0;
}


