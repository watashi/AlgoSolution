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
typedef long long llint;
typedef pair<int, int> PII;
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

struct WolvesAndSheep {
  int getmin(vector <string> field);
};

int WolvesAndSheep::getmin(vector <string> s) {
  int r = s.size(), c = s[0].size();
  vector<int> last(c + 1);

  int ans = (r - 1) + (c - 1);
  for (int i = 1; i < (1 << r); i += 2) {
    vector<int> v;
    for (int j = 0; j < r; ++j) {
      if ((i & (1 << j)) != 0) {
        v.push_back(j);
      }
    }
    v.push_back(r);

    int m = (int)v.size() - 1;
    int tmp = (int)v.size() - 2;
    bool first = true;
    vector<bool> hasw(m, false), hass(m, false);
    for (int y = 0; y < c; ++y) {
      for (int j = 0; j < m; ++j) {
        for (int x = v[j]; x < v[j + 1]; ++x) {
          if (s[x][y] == 'W') {
            hasw[j] = true;
          } else if (s[x][y] == 'S') {
            hass[j] = true;
          }
        }
        if (hasw[j] && hass[j]) {
          if (!first) {
            --y;
            ++tmp;
            first = true;
            fill(hasw.begin(), hasw.end(), false);
            fill(hass.begin(), hass.end(), false);
            goto GOOD;
          } else {
            goto BAD;
          }
        }
      }
      first = false;
GOOD:
      continue;
    }
    ans = min(ans, tmp);
BAD:
    continue;
  }
  return ans;
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
        string fieldARRAY[] = {"W.WSS",
            "WW.S.",
            ".SSS.",
            "SSS.S",
            ".SS.S"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        WolvesAndSheep theObject;
        eq(0, theObject.getmin(field),2);
    }
    {
        string fieldARRAY[] = {".....",
            ".....",
            "....."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        WolvesAndSheep theObject;
        eq(1, theObject.getmin(field),0);
    }
    {
        string fieldARRAY[] = {".SS",
            "...",
            "S..",
            "W.W"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        WolvesAndSheep theObject;
        eq(2, theObject.getmin(field),1);
    }
    {
        string fieldARRAY[] = {"WWWSWWSSWWW",
            "WWSWW.SSWWW",
            "WS.WSWWWWS."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        WolvesAndSheep theObject;
        eq(3, theObject.getmin(field),10);
    }
    {
        string fieldARRAY[] = {".W.S.W.W",
            "W.W.S.W.",
            ".S.S.W.W",
            "S.S.S.W.",
            ".S.W.W.S",
            "S.S.W.W.",
            ".W.W.W.S",
            "W.W.S.S."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        WolvesAndSheep theObject;
        eq(4, theObject.getmin(field),7);
    }
    {
        string fieldARRAY[] = {"W.SSWWSSSW.SS",
            ".SSSSW.SSWWWW",
            ".WWWWS.WSSWWS",
            "SS.WSS..W.WWS",
            "WSSS.SSWS.W.S",
            "WSS.WS...WWWS",
            "S.WW.S.SWWWSW",
            "WSSSS.SSW...S",
            "S.WWSW.WWSWSW",
            ".WSSS.WWSWWWS",
            "..SSSS.WWWSSS",
            "SSWSWWS.W.SSW",
            "S.WSWS..WSSS.",
            "WS....W..WSS."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        WolvesAndSheep theObject;
        eq(5, theObject.getmin(field),24);
    }
    {
        string fieldARRAY[] = {"WW..SS",
            "WW..SS",
            "......",
            "......",
            "SS..WW",
            "SS..WW"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        WolvesAndSheep theObject;
        eq(6, theObject.getmin(field),2);
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
