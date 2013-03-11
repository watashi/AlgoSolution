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

struct DirectionBoard {
  int getMinimum(vector <string> board);
};
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

MinCostMaxFlow<500, int> mcmf;

inline int IN(int i) { return i << 1; }
inline int OUT(int i) { return IN(i) ^ 1; }

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "DRUL";

int DirectionBoard::getMinimum(vector <string> a) {
  int r = a.size(), c = a[0].size(), n = r * c;
  mcmf.init(OUT(n) + 1, IN(n), OUT(n));
  FOR (i, r) {
    FOR (j, c) {
      mcmf.addEdge(IN(n), IN(i * c + j), 0);
      mcmf.addEdge(OUT(i * c + j), OUT(n), 0);
      FOR (k, 4) {
        int x = (i + dx[k] + r) % r;
        int y = (j + dy[k] + c) % c;
        mcmf.addEdge(IN(i * c + j), OUT(x * c + y), a[i][j] == dz[k] ? 0 : 1);
      }
    }
  }
  return mcmf.gao().second;
}

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
        string boardARRAY[] = {"RRRD",
            "URDD",
            "UULD",
            "ULLL"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        DirectionBoard theObject;
        eq(0, theObject.getMinimum(board),0);
    }
    {
        string boardARRAY[] = {"RRRD",
            "URLL",
            "LRRR"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        DirectionBoard theObject;
        eq(1, theObject.getMinimum(board),2);
    }
    {
        string boardARRAY[] = {"RRD",
            "URD",
            "ULL"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        DirectionBoard theObject;
        eq(2, theObject.getMinimum(board),2);
    }
    {
        string boardARRAY[] = {"ULRLRD",
            "UDDLRR"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        DirectionBoard theObject;
        eq(3, theObject.getMinimum(board),4);
    }
    {
        string boardARRAY[] = {"UDLRLDLD",
            "DLDLLDLR",
            "LLLLLDLD",
            "UUURRRDD"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        DirectionBoard theObject;
        eq(4, theObject.getMinimum(board),9);
    }
    {
        string boardARRAY[] = {"UDUDUUDUDUDUDUR",
            "LLLLDUUDRDLUDRU",
            "DLLDLDURDURUDDL",
            "UDUDUUDUDUDUDUR",
            "LLLLDUUDRDLUDRU",
            "DLLDLDURDURUDDL",
            "UDUDUUDUDUDUDUR",
            "LLLLDUUUDDLUDRU",
            "DLLDLDURDURUDDL",
            "UDUDUUDUDUDUDUR",
            "LLLLDUUDRDLUDRU",
            "DLLDLDURDURUDDL",
            "UDUDUUDUDUDUDUR",
            "LLLLDUUDRDLUDRU",
            "RRRDLDURDURUDDR"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        DirectionBoard theObject;
        eq(5, theObject.getMinimum(board),73);
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
