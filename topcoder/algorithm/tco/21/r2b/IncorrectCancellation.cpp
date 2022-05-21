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

template <typename, typename = void>
constexpr bool is_iterable{};

template <typename T>
constexpr bool is_iterable<
  T,
  std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
  >
> = true;

template<typename T, typename = enable_if_t<is_iterable<T>>>
inline void errf(const char* fmt, const T& v) {
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

struct IncorrectCancellation {
  int find(int D);
};

namespace {
  int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  array<int, 10> diff(int x, int y) {
    array<int, 10> ret;
    fill(ALL(ret), 0);
    while (x > 0) {
      if (y > 0 && x % 10 == y % 10) {
        x /= 10;
        y /= 10;
      }
      else {
        ++ret[x % 10];
        x /= 10;
      }
    }
    if (y > 0) {
      fill(ALL(ret), -1);
    }
    return ret;
  }
}

int IncorrectCancellation::find(int D) {
  vector<int> ds;
  for (int d = D; d > 0; d /= 10) {
    ds.push_back(d % 10);
  }
  reverse(ALL(ds));
  int dn = (int)ds.size();
  set<int> st;
  for (int i = 1; i < (1 << dn) - 1; ++i) {
    int k = 0;
    for (int j = 0; j < dn; ++j) {
      if ((i >> j) & 1) {
        k = k * 10 + ds[j];
        if (k == 0) {
          break;
        }
      }
    }
    if (k > 0) {
      st.insert(k);
    }
  }

  for (int i : st) {
    int g = gcd(D, i);
    int x = D / g, y = i / g;
    auto expected = diff(D, i);
    for (int j = 1; j < g; ++j) {
      if (diff(x * j, y * j) == expected) {
        errf("%d/%d = %d/%d = %d/%d\n", x * j, D, y * j, i, j, g);
        return x * j;
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
        IncorrectCancellation theObject;
        eq(0, theObject.find(64),16);
    }
    {
        IncorrectCancellation theObject;
        eq(1, theObject.find(98),49);
    }
    {
        IncorrectCancellation theObject;
        eq(2, theObject.find(470),10);
    }
    {
        IncorrectCancellation theObject;
        eq(3, theObject.find(1057),-1);
    }
    {
        IncorrectCancellation theObject;
        eq(4, theObject.find(15436),454);
    }
    {
        IncorrectCancellation theObject;
        eq(5, theObject.find(15425),13574);
    }
    {
        IncorrectCancellation theObject;
        eq(6, theObject.find(6665),2666);
    }
    {
        IncorrectCancellation theObject;
        eq(7, theObject.find(1221),222);
    }
    {
        IncorrectCancellation theObject;
        eq(8, theObject.find(7),-1);
        theObject.find(1285);
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
  (void)getchar();

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
