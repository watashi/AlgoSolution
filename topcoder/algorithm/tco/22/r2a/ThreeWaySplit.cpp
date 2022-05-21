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

struct ThreeWaySplit {
  string split(vector <int> loot);
};

struct Stat {
  long long min;
  int a;
  int b;
};

void gao(int n, const int* p, long long sa, long long sb, int a, int b, unordered_map<long long, Stat>& ret) {
  if (n == 0) {
    if (sa < sb) {
      swap(sa, sb);
      swap(a, b);
    }
    auto& v = ret[sa - sb];
    if (v.min <= sb) {
      v.min = sb;
      v.a = a;
      v.b = b;
    }
  }
  else {
    --n;
    --p;
    gao(n, p, sa + *p, sb, a | (1 << n), b, ret);
    gao(n, p, sa, sb + *p, a, b | (1 << n), ret);
    gao(n, p, sa, sb, a, b, ret);
  }
}

string ThreeWaySplit::split(vector <int> loot) {
  int n = (int)loot.size();
  int m = n / 2;
  unordered_map<long long, Stat> x, y;
  gao(m, loot.data() + m, 0, 0, 0, 0, x);
  gao(n - m, loot.data() + n, 0, 0, 0, 0, y);
  Stat ans{ 0, 0, 0 };
  for (const auto& i : x) {
    auto it = y.find(i.first);
    if (it != y.end()) {
      Stat tmp{
        i.second.min + it->second.min + i.first,
        i.second.a | (it->second.b << m),
        i.second.b | (it->second.a << m)
      };
      if (tmp.min >= ans.min) {
        ans = tmp;
      }
    }
  }
  errf("%lld\n", ans.min);

  string ret;
  FOR(i, n) {
    if ((ans.a >> i) & 1) {
      ret.push_back('A');
    }
    else if ((ans.b >> i) & 1) {
      ret.push_back('B');
    }
    else {
      ret.push_back('C');
    }
  }
  return ret;
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
        int lootARRAY[] = {4, 7, 53};
        vector <int> loot( lootARRAY, lootARRAY+ARRSIZE(lootARRAY) );
        ThreeWaySplit theObject;
        eq(0, theObject.split(loot),"CCC");
    }
    {
        int lootARRAY[] = {1, 1, 1, 4, 1};
        vector <int> loot( lootARRAY, lootARRAY+ARRSIZE(lootARRAY) );
        ThreeWaySplit theObject;
        eq(1, theObject.split(loot),"BBBAB");
    }
    {
        int lootARRAY[] = {47, 47, 47};
        vector <int> loot( lootARRAY, lootARRAY+ARRSIZE(lootARRAY) );
        ThreeWaySplit theObject;
        eq(2, theObject.split(loot),"CBA");
    }
    {
        int lootARRAY[] = {1, 2, 3, 4, 5, 6};
        vector <int> loot( lootARRAY, lootARRAY+ARRSIZE(lootARRAY) );
        ThreeWaySplit theObject;
        eq(3, theObject.split(loot),"CBBABA");
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
