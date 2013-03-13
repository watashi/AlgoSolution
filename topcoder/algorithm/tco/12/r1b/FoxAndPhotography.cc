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

struct FoxAndPhotography {
  int getMinimumSwaps(vector <int> heightsFront, vector <int> heightsBack);
};

int FoxAndPhotography::getMinimumSwaps(vector <int> a, vector <int> b) {
  int n = a.size();
  vector<int> dp(1 << n, n * n);
  dp[0] = 0;
  FOR (k, (1 << n) - 1) {
    int i = __builtin_popcount(k);
    FOR (j, n) {
      if (((k >> j) & 1) == 0 && a[i] < b[j]) {
        dp[k | (1 << j)] = min(dp[k | (1 << j)], dp[k] + __builtin_popcount(k >> j << j));
      }
    }
  }
  return dp.back() < n * n ? dp.back() : -1;
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
        int heightsFrontARRAY[] = {140, 150};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {160, 150};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(0, theObject.getMinimumSwaps(heightsFront, heightsBack),1);
    }
    {
        int heightsFrontARRAY[] = {140, 140, 140, 140};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {190, 190, 190, 190};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(1, theObject.getMinimumSwaps(heightsFront, heightsBack),0);
    }
    {
        int heightsFrontARRAY[] = {170, 170, 170};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {160, 170, 180};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(2, theObject.getMinimumSwaps(heightsFront, heightsBack),-1);
    }
    {
        int heightsFrontARRAY[] = {140, 141, 142, 143};
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {144, 143, 142, 141};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(3, theObject.getMinimumSwaps(heightsFront, heightsBack),6);
    }
    {
        int heightsFrontARRAY[] = {140, 170, 140, 170, 140, 170, 140, 170, 140, 170}
           ;
        vector <int> heightsFront( heightsFrontARRAY, heightsFrontARRAY+ARRSIZE(heightsFrontARRAY) );
        int heightsBackARRAY[] = {180, 180, 180, 180, 180, 150, 150, 150, 150, 150};
        vector <int> heightsBack( heightsBackARRAY, heightsBackARRAY+ARRSIZE(heightsBackARRAY) );
        FoxAndPhotography theObject;
        eq(4, theObject.getMinimumSwaps(heightsFront, heightsBack),15);
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
