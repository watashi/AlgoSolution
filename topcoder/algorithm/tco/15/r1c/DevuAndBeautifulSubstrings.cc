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

struct DevuAndBeautifulSubstrings {
  long long countBeautifulSubstrings(int n, int cnt);
};

const int MAXN = 52;
const int MAXM = MAXN * (MAXN + 1) / 2;
int64_t dp[MAXN][MAXN][MAXM];

long long DevuAndBeautifulSubstrings::countBeautifulSubstrings(int n, int cnt) {
  MEMSET(dp, 0);
  dp[1][1][1] = 2;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= i; ++j) {
      int maxk = i * (i + 1) / 2;
      for (int k = 0; k <= maxk; ++k) {
        dp[i+1][j+1][k+j+1] += dp[i][j][k];
        dp[i+1][1][k+1] += dp[i][j][k];
      }
    }
  }
  int64_t ans = 0;
  for (int j = 1; j <= n; ++j) {
    ans += dp[n][j][cnt];
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
        DevuAndBeautifulSubstrings theObject;
        eq(0, theObject.countBeautifulSubstrings(2, 2),2L);
    }
    {
        DevuAndBeautifulSubstrings theObject;
        eq(1, theObject.countBeautifulSubstrings(2, 1),0L);
    }
    {
        DevuAndBeautifulSubstrings theObject;
        eq(2, theObject.countBeautifulSubstrings(3, 4),4L);
    }
    {
        DevuAndBeautifulSubstrings theObject;
        eq(3, theObject.countBeautifulSubstrings(15, 35),642L);
    }
    {
        DevuAndBeautifulSubstrings theObject;
        eq(4, theObject.countBeautifulSubstrings(40, 820),2L);
    }
    {
        DevuAndBeautifulSubstrings theObject;
        eq(5, theObject.countBeautifulSubstrings(50, 94),32357325751902L);
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
