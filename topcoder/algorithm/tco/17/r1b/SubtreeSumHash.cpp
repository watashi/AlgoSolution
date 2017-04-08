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

struct SubtreeSumHash {
  int count(vector <int> weight, vector <int> p, int x);
};

constexpr int64_t MOD = 1000000007;

int64_t gao(int64_t a, int64_t b, int64_t m) {
  int64_t ret = 1;
  while (b > 0) {
    if ((b & 1) != 0) {
      ret = ret * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return ret;
}

int SubtreeSumHash::count(vector <int> weight, vector <int> p, int x) {
  int n = weight.size();
  vector<vector<int>> e(n);
  for (int i = 0; i < (int)p.size(); ++i) {
    e[p[i]].push_back(i + 1);
  }
  vector<int64_t> all(n);
  errf("n = %d\n", n);
  for (int i = n - 1; i >= 0; --i) {
    all[i] = gao(x, weight[i], MOD);
    for (int j: e[i]) {
      // errf("%d -> %d\n", i, v);
      all[i] *= all[j] + 1;
      all[i] %= MOD;
    }
    // errf("[%d]", i);
    // errf("%d, ", all[i]);
  }

  int64_t ret = 0;
  for (auto i: all) {
    ret += i;
  }
  return (int)(ret % MOD);
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
        int weightARRAY[] = {1,2,3};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        int pARRAY[] = {0,1};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SubtreeSumHash theObject;
        eq(0, theObject.count(weight, p, 10),1102110);
    }
    {
        int weightARRAY[] = {123456789,987654321,111111111,999999999};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        int pARRAY[] = {0,0,0};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SubtreeSumHash theObject;
        eq(1, theObject.count(weight, p, 1),11);
    }
    {
        int weightARRAY[] = {10};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        SubtreeSumHash theObject;
        eq(2, theObject.count(weight, vector <int>(), 10),999999937);
    }
    {
        int weightARRAY[] = {3,7,6,8,9,4,2,1,5,6,7,8,9,6,1,2,3,5};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        int pARRAY[] = {0,0,0,3,1,1,2,0,0,3,7,8,9,0,0,4,1};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SubtreeSumHash theObject;
        eq(3, theObject.count(weight, p, 987654321),46327623);
    }
    {
        int weightARRAY[] = {981981872, 137244431, 944958650, 719891852, 49946249, 99332976, 687829452, 797183972, 521759907, 695089008, 857445201, 918685371, 713909623, 549299230, 101933638, 868995524, 549555708, 621134027, 568445543, 482680479, 194657108, 285223549, 712149805, 68166263, 811035241, 707523361, 203558611, 221781002, 490603303, 59629306, 196520255, 245050406, 495135531, 913415717, 826480473, 877268389, 33554320, 594983199, 943552792, 497031849, 458272537, 978980114, 692349067, 491694735, 259866834, 648345985, 897035515, 32762517, 175374585, 622421636};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        int pARRAY[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SubtreeSumHash theObject;
        eq(4, theObject.count(weight, p, 987654321), 307958603);
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
