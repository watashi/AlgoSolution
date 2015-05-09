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

struct UnrelatedPaths {
  int maxUnrelatedPaths(vector <int> parent);
};

vector<vector<int>> e;

int UnrelatedPaths::maxUnrelatedPaths(vector <int> parent) {
  int n = parent.size() + 1;
  e.clear();
  e.resize(n);
  FOR (i, parent.size()) {
    e[parent[i]].push_back(i + 1);
  }

  int ans = 0;
  FOR (i, n) {
    if (e[i].empty()) {
      ++ans;
    }
  }
  return ans;
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
        int parentARRAY[] = {0, 1, 1, 2, 3};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        UnrelatedPaths theObject;
        eq(0, theObject.maxUnrelatedPaths(parent),2);
    }
    {
        int parentARRAY[] = {0, 0, 1, 1, 2, 2};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        UnrelatedPaths theObject;
        eq(1, theObject.maxUnrelatedPaths(parent),4);
    }
    {
        int parentARRAY[] = {0, 1, 2, 3};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        UnrelatedPaths theObject;
        eq(2, theObject.maxUnrelatedPaths(parent),1);
    }
    {
        int parentARRAY[] = {0,1,1,2,2,2,4,6,5,0,10,5,12,12,10,4,16,12,5,3,20,12,11,21,9,5,1,20,15,24,6,8,15}
           ;
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        UnrelatedPaths theObject;
        eq(3, theObject.maxUnrelatedPaths(parent),17);
    }
    {
        int parentARRAY[] = {0,1,1,1,1,0,2,5,1,6,7,10,5,10,8,5,16,14,8,14,4,14,15,21,0,24,11,1,9,18,13,20,6,28,19,28,14,11,38,26,25,10,23,43}
           ;
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        UnrelatedPaths theObject;
        eq(4, theObject.maxUnrelatedPaths(parent),19);
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
