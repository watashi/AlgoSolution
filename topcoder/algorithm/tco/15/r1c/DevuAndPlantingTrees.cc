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

struct DevuAndPlantingTrees {
  int maximumTreesDevuCanGrow(vector <string> garden);
};

int DevuAndPlantingTrees::maximumTreesDevuCanGrow(vector <string> garden) {
  int ans = 0, cur = 1;
  FOR (i, garden[0].size()) {
    if (garden[0][i] == '*') {
      ++ans;
    }
    if (garden[1][i] == '*') {
      ++ans;
    }
    if (garden[0][i] == '*' || garden[1][i] == '*') {
      if (cur >= 3) {
        ans += (cur - 1) / 2;
      }
      cur = 0;
    } else {
      ++cur;
    }
  }
  ++cur;
  ans += (cur - 1) / 2;
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
        string gardenARRAY[] = {"..", ".."};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(0, theObject.maximumTreesDevuCanGrow(garden),1);
    }
    {
        string gardenARRAY[] = {"..", ".*"};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(1, theObject.maximumTreesDevuCanGrow(garden),1);
    }
    {
        string gardenARRAY[] = {"...",
           "..*"};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(2, theObject.maximumTreesDevuCanGrow(garden),2);
    }
    {
        string gardenARRAY[] = {".....*..........",
           ".*.......*.*..*."};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(3, theObject.maximumTreesDevuCanGrow(garden),7);
    }
    {
        string gardenARRAY[] = {"....*.*.*...........*........",
           "*..........*..*.*.*....*...*."};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(4, theObject.maximumTreesDevuCanGrow(garden),13);
    }
    {
        string gardenARRAY[] = {".....*..*..........*............................*",
           "*..*.............*...*.*.*.*..*.....*.*...*...*.."};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(5, theObject.maximumTreesDevuCanGrow(garden),23);
    }
    {
        string gardenARRAY[] = {".", "."};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(11, theObject.maximumTreesDevuCanGrow(garden),1);
    }
    {
        string gardenARRAY[] = {"*", "."};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(12, theObject.maximumTreesDevuCanGrow(garden),1);
    }
    {
        string gardenARRAY[] = {".", "*"};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(13, theObject.maximumTreesDevuCanGrow(garden),1);
    }
    {
        string gardenARRAY[] = {"*", "*"};
        vector <string> garden( gardenARRAY, gardenARRAY+ARRSIZE(gardenARRAY) );
        DevuAndPlantingTrees theObject;
        eq(14, theObject.maximumTreesDevuCanGrow(garden),2);
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
