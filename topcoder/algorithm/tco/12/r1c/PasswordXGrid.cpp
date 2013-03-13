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

struct PasswordXGrid {
  int minSum(vector <string> horizontal, vector <string> vertical);
};

int PasswordXGrid::minSum(vector <string> h, vector <string> v) {
  int n = h.size() - 1, m = h[0].size();
  vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
  FOR (i, n + 1) {
    FOR (j, m + 1) {
      // printf("%d %d\n", i, j);
      if (i < n) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i][j] - '0');
      }
      if (j < m) {
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + h[i][j] - '0');
      }
    }
  }
  return dp[n][m];
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
        string horizontalARRAY[] = {"1","4"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"32"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(0, theObject.minSum(horizontal, vertical),7);
    }
    {
        string horizontalARRAY[] = {"47", "59"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"361"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(1, theObject.minSum(horizontal, vertical),19);
    }
    {
        string horizontalARRAY[] = {"36", "23", "49"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"890", "176"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(2, theObject.minSum(horizontal, vertical),28);
    }
    {
        string horizontalARRAY[] = {"8888585","5888585"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"58585858"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(3, theObject.minSum(horizontal, vertical),58);
    }
    {
        string horizontalARRAY[] = {"7777777","7777777","7777777","7777777"};
        vector <string> horizontal( horizontalARRAY, horizontalARRAY+ARRSIZE(horizontalARRAY) );
        string verticalARRAY[] = {"44444444","44444444","44444444"};
        vector <string> vertical( verticalARRAY, verticalARRAY+ARRSIZE(verticalARRAY) );
        PasswordXGrid theObject;
        eq(4, theObject.minSum(horizontal, vertical),61);
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
