#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
#define __WATASHI__
// BEGIN CUT HERE
// <errf>
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  for (const auto& i: v) {
    errf(fmt, i);
  }
  errf("}\n");
}
// </errf>
// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct EllysRansom {
  string getRansom(string A, string B, string T);
};

namespace {
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
        }
        else if (maxc[sink] == 0) {
          break;
        }
        else {
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
}

string EllysRansom::getRansom(string A, string B, string T) {
  MinCostMaxFlow<1100> mcmf;
  int n = A.length();
  int s = n + 26, t = s + 1;
  mcmf.init(t + 1, s, t);
  FOR(i, n) {
    mcmf.addEdge(s, i, 1, 0);
    mcmf.addEdge(i, A[i] - 'A' + n, 1, 0);
    mcmf.addEdge(i, B[i] - 'A' + n, 1, 0);
  }
  FOR(i, 26) {
    mcmf.addEdge(n + i, t, count(ALL(T), 'A' + i), 0);
  }
  auto f = mcmf.gao().first;
  if (f != T.length()) {
    return "NO SOLUTION";
  }
  else {
    string ans(n, '_');
    FOR(i, n) {
      for (const auto& j : mcmf.e[i]) {
        if (j.c == 0 && n <= j.v && j.v < s) {
          ans[i] = 'A' + (j.v - n);
        }
      }
    }
    return ans;
  }
}

// BEGIN CUT HERE
// <main>
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
        EllysRansom theObject;
        eq(0, theObject.getRansom("GOODLUCKANDHAVEFUNN", "RPSETSUJMITITUOHTIW", "TOPCODER"),"RPOET_C___D___O____");
    }
    {
        EllysRansom theObject;
        eq(1, theObject.getRansom("HELP", "ELLY", "HELL"),"NO SOLUTION");
    }
    {
        EllysRansom theObject;
        eq(2, theObject.getRansom("NEVERMINDTHENOISEYOUHEARD", "DEBRUOYREDNUTSAEBATSUJSTI", "ENTERSANDMANYEAH"),"NE_ERMYNDTHENSA__A____A__");
    }
    {
        EllysRansom theObject;
        eq(3, theObject.getRansom("THISWASATRIUMPHIMMAKINANOTEHEREHUGE", "EVILALLITSERAOHWELPOEPEHTROFSSECCUS", "APERTURESCIENCEPORTALHASEVILTESTS"),"TVISALSATRERAPHIELPOENE_TTE_SRECCUS");
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
 * __builtin_popcount __builtin_ctz
 * make_pair first second
 * iterator const_iterator
 * priority_queue
 * push_back
 */
/*
 * vim: ft=cpp.doxygen
 */
// </main>
// END CUT HERE
