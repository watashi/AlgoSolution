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

struct FoxAndDoraemon {
  int minTime(vector <int> workCost, int splitCost);
};

int FoxAndDoraemon::minTime(vector <int> workCost, int splitCost) {
  int n = workCost.size();
  int l = *max_element(ALL(workCost));
  int r = l + n * splitCost;
  while (l < r) {
    int m = (l + r) / 2;
    llint total = 1LL << n;
    FOREACH (i, workCost) {
      total -= 1LL << max(0, n - (m - *i) / splitCost); // max!!
      if (total < 0) {
        break;
      }
    }
    if (total < 0) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return r;
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
        int workCostARRAY[] = {1,2};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(0, theObject.minTime(workCost, 1000),1002);
    }
    {
        int workCostARRAY[] = {3,6,9,12};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(1, theObject.minTime(workCost, 1000),2012);
    }
    {
        int workCostARRAY[] = {1000,100,10,1};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(2, theObject.minTime(workCost, 1),1001);
    }
    {
        int workCostARRAY[] = {1712,1911,1703,1610,1697,1612};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(3, theObject.minTime(workCost, 100),2012);
    }
    {
        int workCostARRAY[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(4, theObject.minTime(workCost, 3000),15000);
    }
    {
        int workCostARRAY[] = {58};
        vector <int> workCost( workCostARRAY, workCostARRAY+ARRSIZE(workCostARRAY) );
        FoxAndDoraemon theObject;
        eq(5, theObject.minTime(workCost, 3600),58);
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
