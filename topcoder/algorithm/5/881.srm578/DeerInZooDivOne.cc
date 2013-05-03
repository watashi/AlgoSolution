#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  FOR(i, v.size()) {
    errf(fmt, v[i]);
  }
  errf("}\n");
}
// TODO
/// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct DeerInZooDivOne {
  int getmax(vector <int> a, vector <int> b);
};

const int MAXN = 54;

vector<int> e[MAXN];
int dp[MAXN][MAXN];

int parent[MAXN];
vector<int> child[MAXN];
vector<int> treea, treeb;

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

MinCostMaxFlow<MAXN, int> mcmf;

int gao(int a, int b) {
  int& ret = dp[a][b];
  if (ret == -1) {
    if (child[a].empty() || child[b].empty()) {
      ret = 1;
    } else {
      int na = child[a].size();
      int nb = child[b].size();
      vector<vector<int> > w(na, vector<int>(nb));
      FOR (i, na) {
        FOR (j, nb) {
          w[i][j] = gao(child[a][i], child[b][j]);
        }
      }
      int s = na + nb;
      int t = s + 1;
      mcmf.init(t + 1, s, t);
      FOR (i, na) {
        mcmf.addEdge(s, i, 0);
      }
      FOR (i, nb) {
        mcmf.addEdge(na + i, t, 0);
      }
      FOR (i, na) {
        FOR (j, nb) {
          mcmf.addEdge(i, na + j, -w[i][j]);
        }
      }
      ret = 1 - mcmf.gao().second;
    }
  }
  return ret;
}

void dfs(int v, int p, vector<int>& tree) {
  parent[v] = p;
  child[v].clear();
  tree.push_back(v);
  FOREACH (w, e[v]) {
    if (*w != p) {
      child[v].push_back(*w);
      dfs(*w, v, tree);
    }
  }
}

int DeerInZooDivOne::getmax(vector <int> a, vector <int> b) {
  int n = a.size() + 1;
  int ans = 1;

  // 50
  FOR (i, a.size()) {
    FOR (j, n) {
      e[j].clear();
    }
    FOR (j, a.size()) {
      if (i != j) {
        e[a[j]].push_back(b[j]);
        e[b[j]].push_back(a[j]);
      }
    }
    treea.clear();
    dfs(a[i], -1, treea);
    treeb.clear();
    dfs(b[i], -1, treeb);
    if (treea.size() < treeb.size()) {
      treea.swap(treeb);
    }
    if ((int)treeb.size() <= ans) {
      continue;
    }

    // 25
    FOR (j, treeb.size()) {
      vector<int> dummy;
      dfs(treeb[j], -1, dummy);
      MEMSET(dp, 0xff);
      FOREACH (u, treea) {
        FOREACH (v, treeb) {
          ans = max(ans, gao(*u, *v));
        }
      }
    }
  }

  return ans;
}

/*
[quote=oldjunyi]
By changing each node <var>v</var> to <var>degree(v)</var> directed nodes
(<var>v</var>, <var>parent(v)</var>), the loop enumerating root of tree <var>b</var>
can be omitted.
[/quote]
 */

/// BEGIN CUT HERE
// TODO
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "{";
  FOR(i, v.size()) {
    os << "\"" << v[i] << "\",";
  }
  os << "}";

  return os;
}

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        int aARRAY[] = {0, 1, 2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1, 2, 3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DeerInZooDivOne theObject;
        eq(0, theObject.getmax(a, b),2);
    }
    {
        int aARRAY[] = {1, 8, 1, 7, 4, 2, 5, 2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {5, 3, 6, 8, 2, 6, 8, 0};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DeerInZooDivOne theObject;
        eq(1, theObject.getmax(a, b),4);
    }
    {
        int aARRAY[] = {0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DeerInZooDivOne theObject;
        eq(2, theObject.getmax(a, b),1);
    }
    {
        int aARRAY[] = {0, 11, 10, 10, 19, 17, 6, 17, 19, 10, 10, 11, 9, 9, 14, 2, 13, 11, 6};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {7, 5, 2, 12, 8, 9, 16, 8, 4, 18, 8, 13, 15, 13, 17, 16, 3, 1, 7};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DeerInZooDivOne theObject;
        eq(3, theObject.getmax(a, b),8);
    }
    {
        int aARRAY[] = {14, 13, 28, 15, 20, 4, 9, 6, 1, 23, 19, 25, 25, 8, 14, 16, 2, 8, 15, 25, 22, 22, 28, 10, 10, 14, 24, 27, 8};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {21, 5, 12, 13, 27, 1, 24, 17, 27, 17, 23, 14, 18, 26, 7, 26, 11, 0, 25, 23, 3, 29, 22, 11, 22, 29, 15, 28, 29};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DeerInZooDivOne theObject;
        eq(4, theObject.getmax(a, b),11);
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
  getchar();

  return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE
