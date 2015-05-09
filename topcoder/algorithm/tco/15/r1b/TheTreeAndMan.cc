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
typedef int64_t LL;
typedef pair<int, int> PII;
const int E9 = 1000000000;
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

struct TheTreeAndMan {
  int solve(vector <int> parent);
};

const int64_t MOD = E9 + 7;
vector<vector<int>> e;

int TheTreeAndMan::solve(vector <int> parent) {
  int n = parent.size() + 1;
  e.clear();
  e.resize(n);
  FOR (i, parent.size()) {
    e[parent[i]].push_back(i + 1);
  }

  vector<int64_t> c(n, 1);
  for (int i = n - 1; i >= 0; --i) {
    for (int j: e[i]) {
      c[i] += c[j];
    }
  }
  errf("%lld, ", c);

  vector<int64_t> as4(n);
  for (int i = n - 1; i >= 0; --i) {
    for (int j: e[i]) {
      for (int k: e[i]) {
        if (j < k) {
          as4[i] += c[j] * c[k] % MOD;
        }
      }
      as4[i] += as4[j];
    }
    as4[i] %= MOD;
  }
  errf("%lld, ", as4);

  vector<int64_t> as1(n);
  for (int i = n - 1; i >= 0; --i) {
    int64_t s = 0;
    for (int j: e[i]) {
      s += as4[j];
    }
    s %= MOD;
    for (int j: e[i]) {
      for (int k: e[i]) {
        if (j < k) {
          int64_t t = c[j] * c[k] % MOD;
          as1[i] += t * (s - as4[j] - as4[k]) % MOD;
        }
      }
      as1[i] += as1[j];
    }
    as1[i] %= MOD;
  }
  errf("%lld, ", as1);

  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j: e[i]) {
      ans += as1[j];
    }
  }
  ans %= MOD;
  ans += MOD;
  ans %= MOD;
  return (int)ans;
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
        int parentARRAY[] = {0,1,1,1,4,4};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        TheTreeAndMan theObject;
        eq(0, theObject.solve(parent),1);
    }
    {
        int parentARRAY[] = {0,0,2,2,2,4,0,4,7,2,10,11,9,0,1,0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        TheTreeAndMan theObject;
        eq(1, theObject.solve(parent),7);
    }
    {
        int parentARRAY[] = {0,0,2,2,3,1,0,1,5};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        TheTreeAndMan theObject;
        eq(2, theObject.solve(parent),0);
    }
    {
        int parentARRAY[] = {0,0,0,2,3,5,2,5,3,7,7,7,2};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        TheTreeAndMan theObject;
        eq(3, theObject.solve(parent),3);
    }
    {
        int parentARRAY[] = {0,0,1,2,2,2,1,4,2,9,0,1,5};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        TheTreeAndMan theObject;
        eq(4, theObject.solve(parent),0);
    }
    {
        int parentARRAY[] = {0,0,0,2,4,2,5,6,5,9,5,0,3,8,8,15,0,17,9};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        TheTreeAndMan theObject;
        eq(5, theObject.solve(parent),3);
    }
    {
        int parentARRAY[] = {0,0,0,3,0,1,3,5,6,8,2,7,1,9,1,5,13,6,3,7,8,4,2,18,12,11,17,13,10,25,11,26,22,32,32,18,35,33,25,31,24,38,41,34,43,42,32,
           43,31,35,47,49,36,35,39,42,36,39,47,53,40,61,60,43,47,61,51,56,67,69,53,53,63,56,71,55,76,73,70,74,67,76,64,80,68,85,78,
           69,79,73,70,75,77,81,80,94,85,88,88,99,83,99,93,90,85,100,89,96,96,103,107,96,105,95,100,97,97}
           ;
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        TheTreeAndMan theObject;
        eq(6, theObject.solve(parent),9864);
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
