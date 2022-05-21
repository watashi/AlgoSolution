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

struct ConstantSegment {
  int sendSomeHome(int N, int K, int M, vector <int> Pprefix, int seed);
};

int ConstantSegment::sendSomeHome(int N, int K, int M, vector <int> Pprefix, int seed) {
  vector<int> P(N);

  int L = Pprefix.size();
  for (int i = 0; i < L; ++i) P[i] = Pprefix[i];

  long long state = seed;
  for (int i = L; i < N; ++i) {
    state = (state * 1103515245 + 12345) % (1LL << 31);
    P[i] = (state / 16) % M;
  }

  unordered_map<int, vector<int>> m;
  int ans = N + 1;
  FOR(i, N) {
    auto& v = m[P[i]];
    v.push_back(i);
    int k = (int)v.size();
    if (v.size() >= K) {
      ans = min(ans, v[k - 1] - v[k - K] + 1 - K);
    }
  }
  if (ans >= N) {
    ans = -1;
  }
  return ans;
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
        int PprefixARRAY[] = {1, 4, 3, 3, 3, 3, 2, 0, 3, 9};
        vector <int> Pprefix( PprefixARRAY, PprefixARRAY+ARRSIZE(PprefixARRAY) );
        ConstantSegment theObject;
        eq(0, theObject.sendSomeHome(10, 3, 10, Pprefix, 0),0);
    }
    {
        int PprefixARRAY[] = {1, 4, 3, 3, 3, 3, 2, 0, 3, 9};
        vector <int> Pprefix( PprefixARRAY, PprefixARRAY+ARRSIZE(PprefixARRAY) );
        ConstantSegment theObject;
        eq(1, theObject.sendSomeHome(10, 5, 10, Pprefix, 0),2);
    }
    {
        int PprefixARRAY[] = {1, 4, 3, 3, 3, 3, 2, 0, 3, 9};
        vector <int> Pprefix( PprefixARRAY, PprefixARRAY+ARRSIZE(PprefixARRAY) );
        ConstantSegment theObject;
        eq(2, theObject.sendSomeHome(10, 6, 10, Pprefix, 0),-1);
    }
    {
        int PprefixARRAY[] = {1, 4, 5, 2, 1, 2, 3, 7, 8, 3};
        vector <int> Pprefix( PprefixARRAY, PprefixARRAY+ARRSIZE(PprefixARRAY) );
        ConstantSegment theObject;
        eq(3, theObject.sendSomeHome(10, 2, 47, Pprefix, 4747),1);
    }
    {
        int PprefixARRAY[] = {0, 1, 2, 3, 4};
        vector <int> Pprefix( PprefixARRAY, PprefixARRAY+ARRSIZE(PprefixARRAY) );
        ConstantSegment theObject;
        eq(4, theObject.sendSomeHome(20, 3, 10, Pprefix, 123456789),9);
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
