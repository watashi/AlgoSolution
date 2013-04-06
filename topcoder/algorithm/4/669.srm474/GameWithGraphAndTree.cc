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

struct GameWithGraphAndTree {
  int calc(vector <string> graph, vector <string> tree);
};

const int MAXN = 14;
const llint MOD = 1000000007;

vector<string> graph, tree;

map<pair<int, int>, llint> gao(int n, int v, int p) {
  map<pair<int, int>, llint> ret;
  FOR (i, n) {
      ret[make_pair(i, 1 << i)] = 1;
  }
  for (int w = 0; w < n; ++w) {
    if (w != p && tree[v][w] == 'Y') {
      map<pair<int, int>, llint> x = ret;
      map<pair<int, int>, llint> y = gao(n, w, v);
      ret.clear();
      if (!x.empty() && !y.empty()) {
        int k = __builtin_popcount(x.begin()->first.second) +
                __builtin_popcount(y.begin()->first.second);
        bool swp = x.size() > y.size();
        if (swp) {
          x.swap(y);
        }
        FOR (i, 1 << n) {
          if (__builtin_popcount(i) != k) {
            continue;
          }
          FOREACH (j, x) {
            if ((i & j->first.second) != j->first.second) {
              continue;
            }
            int jj = i ^ j->first.second;
            FOR (k, n) {
              if ((jj & (1 << k)) != 0 && graph[j->first.first][k] == 'Y') {
                map<pair<int, int>, llint>::const_iterator it = y.find(make_pair(k, jj));
                if (it != y.end()) {
                  llint& z = ret[make_pair(swp ? k : j->first.first, i)];
                  z += j->second * it->second;
                  z %= MOD;
                }
              }
            }
          }
        }
      }
    }
  }
  /*
  printf("@ %d\n", v);
  FOREACH (i, ret) {
    printf("<%d,%d> %lld\n", i->first.first, i->first.second, i->second);
  }
  */
  return ret;
}

int GameWithGraphAndTree::calc(vector <string> graph, vector <string> tree) {
  int n = graph.size();
  ::graph = graph;
  ::tree = tree;
  map<pair<int, int>, llint> dp = gao(n, 0, -1);
  llint ans = 0;
  FOREACH (i, dp) {
    ans += i->second;
  }
  return ans % MOD;
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
        string graphARRAY[] = {"NYN",
            "YNY",
            "NYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        string treeARRAY[] = {"NYY",
            "YNN",
            "YNN"};
        vector <string> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        GameWithGraphAndTree theObject;
        eq(0, theObject.calc(graph, tree),2);
    }
    {
        string graphARRAY[] = {"NYNNN",
            "YNYYY",
            "NYNYY",
            "NYYNY",
            "NYYYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        string treeARRAY[] = {"NYNNN", 
            "YNYNN",
            "NYNYN",
            "NNYNY",
            "NNNYN"};
        vector <string> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        GameWithGraphAndTree theObject;
        eq(1, theObject.calc(graph, tree),12);
    }
    {
        string graphARRAY[] = {"NYNNNY",
            "YNYNNN",
            "NYNYNN",
            "NNYNYN", 
            "NNNYNY",
            "YNNNYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        string treeARRAY[] = {"NYNNYN",
            "YNNYNY",
            "NNNNYN",
            "NYNNNN",
            "YNYNNN",
            "NYNNNN"};
        vector <string> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        GameWithGraphAndTree theObject;
        eq(2, theObject.calc(graph, tree),0);
    }
    {
        string graphARRAY[] = {"NYNNYN",
            "YNNYNY",
            "NNNNYN",
            "NYNNNN",
            "YNYNNN",
            "NYNNNN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        string treeARRAY[] = {"NNNYYN", 
            "NNYNNN",
            "NYNNYY", 
            "YNNNNN",
            "YNYNNN",
            "NNYNNN"};
        vector <string> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        GameWithGraphAndTree theObject;
        eq(3, theObject.calc(graph, tree),2);
    }
    {
        string graphARRAY[] = {"NYNNNYNNY",
            "YNNNNNNYN",
            "NNNNYYNYY",
            "NNNNNYNNY",
            "NNYNNNYNY",
            "YNYYNNNYN",
            "NNNNYNNYN",
            "NYYNNYYNN",
            "YNYYYNNNN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        string treeARRAY[] = {"NNYNNNYYN",
            "NNNNYNNNN",
            "YNNNNNNNN",
            "NNNNNNYNN",
            "NYNNNNNYY",
            "NNNNNNNNY",
            "YNNYNNNNN",
            "YNNNYNNNN",
            "NNNNYYNNN"};
        vector <string> tree( treeARRAY, treeARRAY+ARRSIZE(treeARRAY) );
        GameWithGraphAndTree theObject;
        eq(4, theObject.calc(graph, tree),90);
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
