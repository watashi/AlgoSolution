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

struct TheKnights {
  double find(int n, int a, int b);
};

inline bool ok(llint n, llint x, llint y) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

double TheKnights::find(int n, int a, int b) {
  int _st[] = {0, a, b, n - a, n - b, n};
  set<llint> st(_st, _st + 6);
  vector<llint> v;
  FOREACH (i, st) {
    if (0 <= *i && *i <= n) {
      v.push_back(*i);
    }
  }
  llint m = 1LL * n * n;
  long double ans = 0;
  for (int i = 1; i < (int)v.size(); ++i) {
    llint x1 = v[i - 1], x2 = v[i];
    for (int j = 1; j < (int)v.size(); ++j) {
      llint y1 = v[j - 1], y2 = v[j];
      llint z = (x2 - x1) * (y2 - y1);
      llint k = 1;
      for (int dx = -1; dx <= 1; dx += 2) {
        for (int dy = -1; dy <= 1; dy += 2) {
          if (ok(n, x1 + dx * a, y1 + dy * b)) {
            ++k;
          }
          if (a != b && ok(n, x1 + dx * b, y1 + dy * a)) {
            ++k;
          }
        }
      }
      long double p = (long double)k * (2 * m - k - 1);
      ans += p * z;
    }
  }
  return (double)ans / m / (m - 1);
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
        TheKnights theObject;
        eq(0, theObject.find(2, 1, 1),3.3333333333333335);
    }
    {
        TheKnights theObject;
        eq(1, theObject.find(47, 7, 74),2.0);
    }
    {
        TheKnights theObject;
        eq(2, theObject.find(3, 2, 1),4.888888888888889);
    }
    {
        TheKnights theObject;
        eq(3, theObject.find(9999, 999, 99),16.25885103191273);
    }
    {
        TheKnights theObject;
        eq(4, theObject.find(10, 1, 6),7.636363636363637);
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
