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

struct TheFrog {
  double getMinimum(int D, vector <int> L, vector <int> R);
};

double TheFrog::getMinimum(int D, vector <int> L, vector <int> R) {
  int n = L.size();
  double ans = D;
  set<int> st;
  FOREACH (i, L) {
    st.insert(*i);
  }
  FOREACH (i, R) {
    st.insert(*i);
  }
  FOREACH (_i, st) {
    llint i = *_i;
    for (llint j = 1; j <= i; ++j) {
      if (ans < 1.0 * i / j) {
        continue;
      }
      FOR (k, n) {
        if ((L[k] * j / i + 1) * i < R[k] * j) {
          goto NEXT;
        }
      }
      ans = 1.0 * i / j;
NEXT:
      continue;
    }
  }
  return ans;
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
        int LARRAY[] = {2};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {7};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(0, theObject.getMinimum(16, L, R),7.0);
    }
    {
        int LARRAY[] = {11, 3};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {21, 7};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(1, theObject.getMinimum(25, L, R),10.5);
    }
    {
        int LARRAY[] = {0};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {100};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(2, theObject.getMinimum(100, L, R),100.0);
    }
    {
        int LARRAY[] = {0, 50};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {50, 100};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(3, theObject.getMinimum(100, L, R),50.0);
    }
    {
        int LARRAY[] = {17, 25281, 5775, 2825, 14040};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {55, 26000, 5791, 3150, 14092};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        TheFrog theObject;
        eq(4, theObject.getMinimum(30000, L, R),787.8787878787879);
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
