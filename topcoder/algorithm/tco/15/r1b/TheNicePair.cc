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

struct TheNicePair {
  int solve(vector <int> A);
};

int TheNicePair::solve(vector <int> A) {
  int n = A.size();
  int ans = -1;
  for (int v = 2; v <= 1000; ++v) {
    FOR (i, n) {
      int k = 0;
      for (int j = i; j < n; ++j) {
        if (A[j] % v == 0) {
          ++k;
        }
        if (2 * k >= j - i + 1) {
          ans = max(ans, j - i);
        }
      }
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
        int AARRAY[] = {5,5,5,5,5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        TheNicePair theObject;
        eq(0, theObject.solve(A),4);
    }
    {
        int AARRAY[] = {1,1,1,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        TheNicePair theObject;
        eq(1, theObject.solve(A),-1);
    }
    {
        int AARRAY[] = {2,3,5,7};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        TheNicePair theObject;
        eq(2, theObject.solve(A),1);
    }
    {
        int AARRAY[] = {8,8,5,5,5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        TheNicePair theObject;
        eq(3, theObject.solve(A),4);
    }
    {
        int AARRAY[] = {1,1000,1000,1,1000,1,999};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        TheNicePair theObject;
        eq(4, theObject.solve(A),5);
    }
    {
        int AARRAY[] = {1000,1,1,1000};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        TheNicePair theObject;
        eq(5, theObject.solve(A),3);
    }
    {
        int AARRAY[] = {1,1,953,1,1,1,1,1,1,1,1,1,1,1,1,953,1,953,953,1,1,1,1,1,1,1,953,953,953,1,1,1,1,1,953,953,1,1,1,953,953,953,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        TheNicePair theObject;
        eq(6, theObject.solve(A),15);
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
