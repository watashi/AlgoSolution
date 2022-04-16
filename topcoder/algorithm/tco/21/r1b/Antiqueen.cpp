#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
#define __WATASHI__
// BEGIN CUT HERE
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

struct Antiqueen {
  int countPaths(int R, int C, int N);
};

namespace {
  constexpr int64_t MOD = 1000000007;
}

int Antiqueen::countPaths(int R, int C, int N) {
  vector<vector<int64_t>> dp(R, vector<int64_t>(C, 1));
  FOR(n, N + 1) {
    int64_t s = 0;
    vector<int64_t> r(R, 0), c(C, 0), diag(R + C, 0), rdiag(R + C, 0);
    FOR(i, R) {
      FOR(j, C) {
        s += dp[i][j];
        r[i] += dp[i][j];
        c[j] += dp[i][j];
        diag[j - i + R] += dp[i][j];
        rdiag[i + j] += dp[i][j];
      }
    }
    if (n == N) {
      return (s % MOD + MOD) % MOD;
    }
    FOR(i, R) {
      FOR(j, C) {
        dp[i][j] = s - r[i] - c[j] - diag[j - i + R] - rdiag[i + j] + 3 * dp[i][j];
        dp[i][j] %= MOD;
      }
    }
  }
  return -1;
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
        Antiqueen theObject;
        eq(0, theObject.countPaths(3, 3, 1),16);
    }
    {
        Antiqueen theObject;
        eq(1, theObject.countPaths(2, 3, 100),4);
    }
    {
        Antiqueen theObject;
        eq(2, theObject.countPaths(2, 4, 100),9613417);
    }
    {
        Antiqueen theObject;
        eq(3, theObject.countPaths(7, 8, 2),64904);
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
