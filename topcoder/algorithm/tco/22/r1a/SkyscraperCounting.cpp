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

struct SkyscraperCounting {
  int count(string visibility);
};

constexpr int64_t MOD = 1000000007;

int SkyscraperCounting::count(string v) {
  int n = v.length();
  vector<int64_t> fact(n + 1);
  vector<vector<int64_t>> choose(n + 1);
  fact[0] = 1;
  choose[0].push_back(1);
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    choose[i].resize(i + 1);
    choose[i][0] = choose[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
    }
  }
  int end = n;
  int64_t ans = 1;
  for (int i = end - 1; i >= 0; --i) {
    if (v[i] == 'O') {
      ans = ans * choose[end - 1][end - 1 - i] % MOD * fact[end - 1 - i] % MOD;
      end = i;
    }
  }
  return end == 0 ? ans : 0;
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
        SkyscraperCounting theObject;
        eq(0, theObject.count("OXXXX"),24);
    }
    {
        SkyscraperCounting theObject;
        eq(1, theObject.count("OXOXXOX"),72);
    }
    {
        SkyscraperCounting theObject;
        eq(2, theObject.count("XOXOXO"),0);
    }
    {
        SkyscraperCounting theObject;
        eq(3, theObject.count("OXXXXXXXXXXXXXO"),227020758);
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
