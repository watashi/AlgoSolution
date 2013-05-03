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

struct GooseInZooDivTwo {
  int count(vector <string> field, int dist);
};

const int MAXN = 10000;
const int MOD = 1000000007;

struct DisjointSet {
  int p[MAXN];

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    if (i != j) {
      p[i] = j;
      return true;
    } else {
      return false;
    }
  }
} ds;

void dbl(int& x) {
  x <<= 1;
  if (x >= MOD) {
    x -= MOD;
  }
}

int GooseInZooDivTwo::count(vector <string> s, int dist) {
  vector<pair<int, int> > v;
  int r = s.size(), c = s[0].size();
  FOR (i, r) {
    FOR (j, c) {
      if (s[i][j] == 'v') {
        v.push_back(make_pair(i, j));
      }
    }
  }
  ds.init(v.size());
  FOR (i, v.size()) {
    FOR (j, i) {
      if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= dist) {
        ds.setp(i, j);
      }
    }
  }

  int ans = 1;
  FOR (i, v.size()) {
    if (ds.getp(i) == i) {
      dbl(ans);
    }
  }
  return (ans + MOD - 1) % MOD;
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
        string fieldARRAY[] = {"vvv"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivTwo theObject;
        eq(0, theObject.count(field, 0),7);
    }
    {
        string fieldARRAY[] = {"."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivTwo theObject;
        eq(1, theObject.count(field, 100),0);
    }
    {
        string fieldARRAY[] = {"vvv"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivTwo theObject;
        eq(2, theObject.count(field, 1),1);
    }
    {
        string fieldARRAY[] = {"v.v..................v............................"
           ,".v......v..................v.....................v"
           ,"..v.....v....v.........v...............v......v..."
           ,".........vvv...vv.v.........v.v..................v"
           ,".....v..........v......v..v...v.......v..........."
           ,"...................vv...............v.v..v.v..v..."
           ,".v.vv.................v..............v............"
           ,"..vv.......v...vv.v............vv.....v.....v....."
           ,"....v..........v....v........v.......v.v.v........"
           ,".v.......v.............v.v..........vv......v....."
           ,"....v.v.......v........v.....v.................v.."
           ,"....v..v..v.v..............v.v.v....v..........v.."
           ,"..........v...v...................v..............v"
           ,"..v........v..........................v....v..v..."
           ,"....................v..v.........vv........v......"
           ,"..v......v...............................v.v......"
           ,"..v.v..............v........v...............vv.vv."
           ,"...vv......v...............v.v..............v....."
           ,"............................v..v.................v"
           ,".v.............v.......v.........................."
           ,"......v...v........................v.............."
           ,".........v.....v..............vv.................."
           ,"................v..v..v.........v....v.......v...."
           ,"........v.....v.............v......v.v............"
           ,"...........v....................v.v....v.v.v...v.."
           ,"...........v......................v...v..........."
           ,"..........vv...........v.v.....................v.."
           ,".....................v......v............v...v...."
           ,".....vv..........................vv.v.....v.v....."
           ,".vv.......v...............v.......v..v.....v......"
           ,"............v................v..........v....v...."
           ,"................vv...v............................"
           ,"................v...........v........v...v....v..."
           ,"..v...v...v.............v...v........v....v..v...."
           ,"......v..v.......v........v..v....vv.............."
           ,"...........v..........v........v.v................"
           ,"v.v......v................v....................v.."
           ,".v........v................................v......"
           ,"............................v...v.......v........."
           ,"........................vv.v..............v...vv.."
           ,".......................vv........v.............v.."
           ,"...v.............v.........................v......"
           ,"....v......vv...........................v........."
           ,"....vv....v................v...vv..............v.."
           ,".................................................."
           ,"vv........v...v..v.....v..v..................v...."
           ,".........v..............v.vv.v.............v......"
           ,".......v.....v......v...............v............."
           ,"..v..................v................v....v......"
           ,".....v.....v.....................v.v......v......."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        GooseInZooDivTwo theObject;
        eq(3, theObject.count(field, 3),797922654);
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
