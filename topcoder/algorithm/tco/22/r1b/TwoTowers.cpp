#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
// BEGIN CUT HERE
#define __WATASHI__
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

struct TwoTowers {
  int maxDifference(vector <int> A, vector <int> B);
};

int TwoTowers::maxDifference(vector <int> A, vector <int> B) {
  int x = 0, y = 0;
  int n = A.size();
  FOR(i, n) {
    x += max(A[i], B[i]);
    y += min(A[i], B[i]);
  }
  return x - y;
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
        int AARRAY[] = {3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {5};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        TwoTowers theObject;
        eq(0, theObject.maxDifference(A, B),2);
    }
    {
        int AARRAY[] = {5, 4, 1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {3, 4, 9};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        TwoTowers theObject;
        eq(1, theObject.maxDifference(A, B),10);
    }
    {
        int AARRAY[] = {1, 2, 3, 4, 5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1, 2, 3, 4, 5};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        TwoTowers theObject;
        eq(2, theObject.maxDifference(A, B),0);
    }
    {
        int AARRAY[] = {2, 2, 2, 2, 2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2, 2, 2, 2, 2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        TwoTowers theObject;
        eq(3, theObject.maxDifference(A, B),0);
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
