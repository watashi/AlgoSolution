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

struct SquaresCovering {
  int minCost(vector <int> x, vector <int> y, vector <int> cost, vector <int> sides);
};

const int INF = 2000000000;

int SquaresCovering::minCost(vector <int> x, vector <int> y, vector <int> cost, vector <int> sides) {
  int n = x.size(), m = cost.size();
  vector<int> dp(1 << n, INF);
  dp[0] = 0;
  FOR (i, 1 << n) {
    if (i == 0) {
      continue;
    }
    vector<int> xx, yy;
    FOR (j, n) {
      if ((i & (1 << j)) != 0) {
        xx.push_back(x[j]);
        yy.push_back(y[j]);
      }
    }
    int w = max(*max_element(ALL(xx)) - *min_element(ALL(xx)),
                *max_element(ALL(yy)) - *min_element(ALL(yy)));
    FOR (j, m) {
      if (sides[j] >= w) {
        dp[i] = min(dp[i], cost[j]);
      }
    }
  }
  FOR (i, 1 << n) {
    if (i == 0) {
      continue;
    }
    for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
      dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
    }
  }
  return dp[(1 << n) - 1];
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
        int xARRAY[] = {1,100};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1,100};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int costARRAY[] = {3,1};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int sidesARRAY[] = {100,1};
        vector <int> sides( sidesARRAY, sidesARRAY+ARRSIZE(sidesARRAY) );
        SquaresCovering theObject;
        eq(0, theObject.minCost(x, y, cost, sides),2);
    }
    {
        int xARRAY[] = {1,100};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1,100};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int costARRAY[] = {1,1};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int sidesARRAY[] = {100,1};
        vector <int> sides( sidesARRAY, sidesARRAY+ARRSIZE(sidesARRAY) );
        SquaresCovering theObject;
        eq(1, theObject.minCost(x, y, cost, sides),1);
    }
    {
        int xARRAY[] = {0,100,201,300};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,0,1,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int costARRAY[] = {6,100,10};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int sidesARRAY[] = {1,100,99};
        vector <int> sides( sidesARRAY, sidesARRAY+ARRSIZE(sidesARRAY) );
        SquaresCovering theObject;
        eq(2, theObject.minCost(x, y, cost, sides),22);
    }
    {
        int xARRAY[] = {41,6334,19169,11478,26962,5705,23281,41};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {18467,26500,15724,29358,24464,28145,16827,18467};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int costARRAY[] = {292,11943,5437,14605,154,12383,18717,19896,21727,11539,19913,26300,9895,23812,30334,4665,7712,6869,27645,32758};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int sidesARRAY[] = {9962,2996,4828,32392,33,293,17422,19719,5448,14772,1870,25668,17036,28704,31323,17674,15142,28254,25548,32663};
        vector <int> sides( sidesARRAY, sidesARRAY+ARRSIZE(sidesARRAY) );
        SquaresCovering theObject;
        eq(3, theObject.minCost(x, y, cost, sides),738);
    }
    {
        int xARRAY[] = {41,6334,9169,1478,6962,5705,3281};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {8467,6500,5724,9358,4464,8145,6827};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int costARRAY[] = {92,43,37,15,54,83,17,96,27,39,13,100,95,12,34,65,12,69,45,58};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int sidesARRAY[] = {962,996,828,392,903,293,422,719,448,772,870,668,36,704,323,674,142,254,548,663};
        vector <int> sides( sidesARRAY, sidesARRAY+ARRSIZE(sidesARRAY) );
        SquaresCovering theObject;
        eq(4, theObject.minCost(x, y, cost, sides),84);
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
