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
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
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

struct MountainsEasy {
  int countPlacements(vector <string> picture, int N);
};

const int MAXN = 64;
const llint MOD = 1000000009LL;
llint c[MAXN][MAXN];
llint dp[MAXN][MAXN];

void init() {
  MEMSET(c, 0);
  FOR (i, MAXN) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
}

int MountainsEasy::countPlacements(vector <string> pic, int n) {
  init();
  int w = pic[0].size();
  int h = pic.size();
  int x = 0, y = 0;
  FOR (i, h) {
    FOR (j, w) {
      if (pic[i][j] == 'X') {
        ++x;
      }
    }
  }
  FOR (i, h) {
    FOR (j, w) {
      if (pic[i][j] == 'X') {
        --x;
        ++y;
        for (int ii = i; ii < h; ++ii) {
          for (int jj = max(0, j - (ii - i)); jj <= min(w - 1, j + (ii - i)); ++jj) {
            pic[ii][jj] = '.';
          }
        }
      }
    }
  }

  MEMSET(dp, 0);
  dp[0][0] = 1LL;
  FOR (i, y) {
    FOR (j, n + 1) {
      FOR (k, j) {
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][k] * c[j][k]) % MOD;
      }
    }
  }
  llint ret = 0;
  FOR (i, n + 1) {
    llint tmp = dp[y][i] * c[n][i] % MOD;
    FOR (j, n - i) {
      tmp = tmp * x % MOD;
    }
    ret += tmp;
  }
  return ret % MOD;
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
        string pictureARRAY[] = {"X.",
            "XX"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        MountainsEasy theObject;
        eq(0, theObject.countPlacements(picture, 1),1);
    }
    {
        string pictureARRAY[] = {"X.",
            "XX"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        MountainsEasy theObject;
        eq(1, theObject.countPlacements(picture, 2),5);
    }
    {
        string pictureARRAY[] = {"X.X",
            "XXX"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        MountainsEasy theObject;
        eq(2, theObject.countPlacements(picture, 2),2);
    }
    {
        string pictureARRAY[] = {"X.X",
            "XXX"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        MountainsEasy theObject;
        eq(3, theObject.countPlacements(picture, 3),24);
    }
    {
        string pictureARRAY[] = {"......",
            "X..X..",
            "XXXXXX",
            "XXXXXX"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        MountainsEasy theObject;
        eq(4, theObject.countPlacements(picture, 3),6);
    }
    {
        string pictureARRAY[] = {"......",
            "X..X..",
            "XXXXXX",
            "XXXXXX"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        MountainsEasy theObject;
        eq(5, theObject.countPlacements(picture, 4),300);
    }
    {
        string pictureARRAY[] = {"....X...X..",
            "...XXX.XXX.",
            "XXXXXXXXXXX"};
        vector <string> picture( pictureARRAY, pictureARRAY+ARRSIZE(pictureARRAY) );
        MountainsEasy theObject;
        eq(6, theObject.countPlacements(picture, 10),764632413);
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
