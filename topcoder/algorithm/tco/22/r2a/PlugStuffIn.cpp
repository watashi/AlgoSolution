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

struct PlugStuffIn {
  vector <int> plug(vector <int> gadgets);
};

vector <int> PlugStuffIn::plug(vector <int> g) {
  int n = (int)g.size();
  vector<int> ans(n);
  vector<int> v, w;
  v.push_back(n);
  FOR(i, n) {
    if (g[i] == 0) {
      w.push_back(i);
    }
    else {
      auto k = v.back();
      v.pop_back();
      ans[i] = k;
      FOR(j, g[i]) {
        v.push_back(i);
      }
    }
  }
  if (v.size() < w.size()) {
    return vector<int>();
  }
  else {
    FOR(i, w.size()) {
      ans[w[i]] = v[i];
    }
    return ans;
  }
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
        int gadgetsARRAY[] = {0};
        vector <int> gadgets( gadgetsARRAY, gadgetsARRAY+ARRSIZE(gadgetsARRAY) );
        int retrunValueARRAY[] = {1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlugStuffIn theObject;
        eq(0, theObject.plug(gadgets),retrunValue);
    }
    {
        int gadgetsARRAY[] = {1, 1, 0, 1, 1, 1};
        vector <int> gadgets( gadgetsARRAY, gadgetsARRAY+ARRSIZE(gadgetsARRAY) );
        int retrunValueARRAY[] = {-1, -1, 4, -1, 6, -1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlugStuffIn theObject;
        eq(1, theObject.plug(gadgets),retrunValue);
    }
    {
        int gadgetsARRAY[] = {1, 1, 0, 1, 1, 1, 0};
        vector <int> gadgets( gadgetsARRAY, gadgetsARRAY+ARRSIZE(gadgetsARRAY) );
        PlugStuffIn theObject;
        eq(2, theObject.plug(gadgets),vector <int>());
    }
    {
        int gadgetsARRAY[] = {0, 0, 2, 0, 2};
        vector <int> gadgets( gadgetsARRAY, gadgetsARRAY+ARRSIZE(gadgetsARRAY) );
        int retrunValueARRAY[] = {2, 4, 5, 4, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlugStuffIn theObject;
        eq(3, theObject.plug(gadgets),retrunValue);
    }
    {
        int gadgetsARRAY[] = {0, 3, 3};
        vector <int> gadgets( gadgetsARRAY, gadgetsARRAY+ARRSIZE(gadgetsARRAY) );
        int retrunValueARRAY[] = {3, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlugStuffIn theObject;
        eq(4, theObject.plug(gadgets),retrunValue);
    }
    {
        int gadgetsARRAY[] = {10, 20, 30, 40};
        vector <int> gadgets( gadgetsARRAY, gadgetsARRAY+ARRSIZE(gadgetsARRAY) );
        int retrunValueARRAY[] = {-1, 1, -1, -1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PlugStuffIn theObject;
        eq(5, theObject.plug(gadgets),retrunValue);
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
