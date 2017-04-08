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

struct CheeseSlicing {
  int totalArea(int A, int B, int C, int S);
};

constexpr int MAXN = 101;
int dp[MAXN][MAXN][MAXN];

int gao(int a, int b, int c, int s) {
  if (b < c) swap(b, c);
  if (a < b) swap(a, b);
  if (b < c) swap(b, c);
  int& ret = dp[a][b][c];
  if (ret != -1) {
    return ret;
  } else if (c < s) {
    return ret = 0;
  } else {
    ret = max(ret, gao(a - s, b, c, s) + b * c);
    ret = max(ret, gao(a, b - s, c, s) + a * c);
    ret = max(ret, gao(a, b, c - s, s) + a * b);
    return ret;
  }
}

int CheeseSlicing::totalArea(int A, int B, int C, int S) {
  memset(dp, 0xff, sizeof(dp));
  return gao(A, B, C, S);
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
        CheeseSlicing theObject;
        eq(0, theObject.totalArea(1, 3, 3, 2),0);
    }
    {
        CheeseSlicing theObject;
        eq(1, theObject.totalArea(5, 3, 5, 3),25);
    }
    {
        CheeseSlicing theObject;
        eq(2, theObject.totalArea(5, 5, 5, 2),58);
    }
    {
        CheeseSlicing theObject;
        eq(3, theObject.totalArea(49, 92, 20, 3),30045);
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
