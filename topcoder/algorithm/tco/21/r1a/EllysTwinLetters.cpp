#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <ratio>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

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

struct EllysTwinLetters {
  int getMin(string S);
};

namespace {
  int cost(char c, int i) {
    return abs(c - 'A' - i);
  }
}

int EllysTwinLetters::getMin(string S) {
  static constexpr int INF = 1000000007;
  int n = S.length();
  vector<vector<int>> dp(n, vector<int>(26, INF));
  FOR(i, 26) {
    dp[1][i] = cost(S[0], i) + cost(S[1], i);
  }
  for (int i = 2; i < n; ++i) {
    int pre = *min_element(ALL(dp[i - 2]));
    FOR(j, 26) {
      dp[i][j] = min(dp[i - 1][j], pre + cost(S[i - 1], j)) + cost(S[i], j);
    }
  }
  return *min_element(ALL(dp[n - 1]));
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
        EllysTwinLetters theObject;
        eq(0, theObject.getMin("TOPCODER"),30);
    }
    {
        EllysTwinLetters theObject;
        eq(1, theObject.getMin("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),13);
    }
    {
        EllysTwinLetters theObject;
        eq(2, theObject.getMin("ESPRIT"),25);
    }
    {
        EllysTwinLetters theObject;
        eq(3, theObject.getMin("WITHOUTITIMJUSTESPR"),54);
    }
    {
        EllysTwinLetters theObject;
        eq(4, theObject.getMin("NOZAPHODJUSTVERYVERYIMPROBABLE"),93);
    }
    {
        EllysTwinLetters theObject;
        eq(5, theObject.getMin("FROMALLTHETHINGSIVELOSTMYMINDIMISSTHEMOST"),111);
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
