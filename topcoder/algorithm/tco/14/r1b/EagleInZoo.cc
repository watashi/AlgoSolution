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
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
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
/// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct EagleInZoo {
  double calc(vector <int> parent, int K);
};

const int MAXN = 110;

vector<vector<int>> e;
long double c[MAXN][MAXN];

void init() {
  MEMSET(c, 0);
  for (int i = 0; i < MAXN; ++i) {
    c[i][0] = 1.0;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
}

vector<long double> gao(int v) {
  vector<long double> ret(MAXN);

  ret[0] = 1.0;
  if (!e[v].empty()) {
    long double p = 1.0 / e[v].size();
    for (auto w: e[v]) {
      vector<long double> tmp = gao(w);
      for (int i = 1; i < MAXN; ++i) {
        for (int j = 0; j < i; ++j) {
          long double x = c[i - 1][j] * powl(p, j) * powl(1 - p, i - 1 - j) * p;
          ret[i] += x * tmp[j];
        }
      }
    }
  }

  return ret;
}

double EagleInZoo::calc(vector <int> p, int m) {
  init();

  int n = (int)p.size() + 1;
  vector<vector<int>>(n).swap(e);
  for (int i = 0; i < (int)p.size(); ++i) {
    e[p[i]].push_back(i + 1);
  }

  vector<long double> ans = gao(0);
  return (double)ans[m - 1];
}

/// BEGIN CUT HERE
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
        int parentARRAY[] = {0,0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        EagleInZoo theObject;
        eq(0, theObject.calc(parent, 2),1.0);
    }
    {
        int parentARRAY[] = {0,0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        EagleInZoo theObject;
        eq(1, theObject.calc(parent, 3),0.5);
    }
    {
        int parentARRAY[] = {0,1,0,3};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        EagleInZoo theObject;
        eq(2, theObject.calc(parent, 4),0.75);
    }
    {
        int parentARRAY[] = {0,0,1,1,2,4,4,4,5,5,6,6};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        EagleInZoo theObject;
        eq(3, theObject.calc(parent, 20),0.14595168754091617);
    }
    {
        int parentARRAY[] = {0,1,2,3,2,1,1,7,0,9,10,11,12,13,14,15,16,17,18,14,9};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        EagleInZoo theObject;
        eq(4, theObject.calc(parent, 24),0.3272154791654077);
    }
    {
        int parentARRAY[] = {0,1,2,3,4,5,6,7,8,9,10};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        EagleInZoo theObject;
        eq(5, theObject.calc(parent, 50),0.0);
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
/// END CUT HERE
