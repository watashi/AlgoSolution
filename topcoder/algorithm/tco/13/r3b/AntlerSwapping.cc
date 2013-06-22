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

struct AntlerSwapping {
  int getmin(vector <int> antler1, vector <int> antler2, int capacity);
};

const int INF = 100;

bool test(int i, int j) {
  return ((i >> j) & 1) != 0;
}

int AntlerSwapping::getmin(vector <int> a, vector <int> b, int cap) {
  int n = a.size();
  vector<int> t;
  vector<int> dp(1 << n, INF);
  for (int i = 1; i < (1 << n); ++i) {
    t.clear();
    for (int j = 0; j < n; ++j) {
      if (test(i, j)) {
        t.push_back(a[j]);
        t.push_back(b[j]);
      }
    }
    sort(ALL(t));
    bool flag = true;
    for (int j = 0; j < (int)t.size(); j += 2) {
      if (t[j + 1] - t[j] > cap) {
        flag = false;
      }
    }
    if (flag) {
      dp[i] = __builtin_popcount(i) - 1;
    }
    for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
      dp[i] = min(dp[i], dp[i ^ j] + dp[j]);
    }
  }
  int ans = dp.back();
  if (ans > n) {
    ans = -1;
  }
  return ans;
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
        int antler1ARRAY[] = {3, 2, 2};
        vector <int> antler1( antler1ARRAY, antler1ARRAY+ARRSIZE(antler1ARRAY) );
        int antler2ARRAY[] = {3, 5, 5};
        vector <int> antler2( antler2ARRAY, antler2ARRAY+ARRSIZE(antler2ARRAY) );
        AntlerSwapping theObject;
        eq(0, theObject.getmin(antler1, antler2, 0),1);
    }
    {
        int antler1ARRAY[] = {4, 2, 6, 4, 8, 5, 2, 3};
        vector <int> antler1( antler1ARRAY, antler1ARRAY+ARRSIZE(antler1ARRAY) );
        int antler2ARRAY[] = {3, 4, 5, 2, 8, 5, 7, 6};
        vector <int> antler2( antler2ARRAY, antler2ARRAY+ARRSIZE(antler2ARRAY) );
        AntlerSwapping theObject;
        eq(1, theObject.getmin(antler1, antler2, 1),2);
    }
    {
        int antler1ARRAY[] = {12, 34, 56, 78};
        vector <int> antler1( antler1ARRAY, antler1ARRAY+ARRSIZE(antler1ARRAY) );
        int antler2ARRAY[] = {1234, 2345, 3456, 4567};
        vector <int> antler2( antler2ARRAY, antler2ARRAY+ARRSIZE(antler2ARRAY) );
        AntlerSwapping theObject;
        eq(2, theObject.getmin(antler1, antler2, 100),-1);
    }
    {
        int antler1ARRAY[] = {47, 58, 2013};
        vector <int> antler1( antler1ARRAY, antler1ARRAY+ARRSIZE(antler1ARRAY) );
        int antler2ARRAY[] = {49, 55, 2013};
        vector <int> antler2( antler2ARRAY, antler2ARRAY+ARRSIZE(antler2ARRAY) );
        AntlerSwapping theObject;
        eq(3, theObject.getmin(antler1, antler2, 3),0);
    }
    {
        int antler1ARRAY[] = {4, 1, 7, 5, 7, 8, 2, 1, 3, 1, 7, 5, 9, 4, 9, 1};
        vector <int> antler1( antler1ARRAY, antler1ARRAY+ARRSIZE(antler1ARRAY) );
        int antler2ARRAY[] = {10, 6, 5, 3, 1, 8, 4, 4, 4, 7, 1, 4, 6, 5, 10, 10};
        vector <int> antler2( antler2ARRAY, antler2ARRAY+ARRSIZE(antler2ARRAY) );
        AntlerSwapping theObject;
        eq(4, theObject.getmin(antler1, antler2, 1),7);
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
