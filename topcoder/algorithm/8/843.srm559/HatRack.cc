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
#define WATASHI_PC

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
#ifndef WATASHI_PC
#define errf(fmt, ...) do { } while (false)
#endif

struct HatRack {
  long long countWays(vector <int> knob1, vector <int> knob2);
};

const int MAXN = 64;
typedef pair<int, bool> KEY;
typedef map<KEY, llint> MAP;

const KEY INVALID(-1, false);

vector<int> e[MAXN];

KEY concat(const KEY& lhs, const KEY& rhs) {
  if (lhs.first == rhs.first) {
    if (lhs.second) {
      return KEY(lhs.first + 1, rhs.second);
    } else {
      return INVALID;
    }
  } else if (lhs.first == rhs.first + 1) {
    if (rhs.second) {
      return KEY(lhs.first + 1, false);
    } else {
      return INVALID;
    }
  } else {
    return INVALID;
  }
}

MAP gao(int v, int p) {
  vector<int> c;
  for (vector<int>::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
    if (*it != p) {
      c.push_back(*it);
    }
  }
  MAP ret;
  if ((int)c.size() == 0) {
    ret[make_pair(0, true)] += 1;
  } else if ((int)c.size() == 1) {
    ret[make_pair(1, false)] += gao(c[0], v)[make_pair(0, true)];
  } else if ((int)c.size() == 2) {
    MAP lhs = gao(c[0], v);
    MAP rhs = gao(c[1], v);
    for (MAP::const_iterator it = lhs.begin(); it != lhs.end(); ++it) {
      for (MAP::const_iterator jt = rhs.begin(); jt != rhs.end(); ++jt) {
        KEY key;
        key = concat(it->first, jt->first);
        if (key != INVALID) {
          ret[key] += it->second * jt->second;
        }
        key = concat(jt->first, it->first);
        if (key != INVALID) {
          ret[key] += jt->second * it->second;
        }
      }
    }
  }
  return ret;
}

long long HatRack::countWays(vector <int> knob1, vector <int> knob2) {
  int n = knob1.size() + 1;
  fill(e, e + MAXN, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int a = knob1[i] - 1;
    int b = knob2[i] - 1;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    MAP ret = gao(i, -1);
    for (MAP::const_iterator it = ret.begin(); it != ret.end(); ++it) {
      ans += it->second;
    }
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

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  {
    int knob1ARRAY[] = {10, 35, 32, 8, 4, 44, 21, 30, 6, 22, 23, 14, 26, 37, 3, 20, 48, 38, 16, 25, 36, 4, 23, 5, 1, 19, 45, 29, 34, 1, 18, 6, 20, 19, 9, 11, 7, 20, 21, 47, 24, 25, 7, 15, 24, 21, 33, 13, 6};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {5, 17, 16, 17, 2, 22, 43, 15, 13, 11, 11, 28, 13, 18, 7, 10, 24, 19, 8, 12, 18, 8, 46, 2, 3, 9, 22, 14, 17, 2, 9, 3, 40, 39, 4, 5, 15, 41, 42, 23, 12, 50, 14, 31, 49, 10, 16, 27, 12};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(50, theObject.countWays(knob1, knob2),1048576L);
  }
  {
    int knob1ARRAY[] = {16, 18, 3, 3, 29, 13, 12, 8, 5, 12, 20, 23, 21, 15, 7, 26, 4, 4, 15, 1, 19, 27, 14, 2, 10, 11, 4, 2, 7, 24};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {8, 9, 7, 6, 14, 6, 25, 17, 11, 6, 10, 11, 10, 31, 15, 13, 8, 9, 30, 3, 9, 13, 28, 1, 5, 22, 2, 5, 14, 12};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(31, theObject.countWays(knob1, knob2),32768L);
  }
  {
    int knob1ARRAY[] = {21, 18, 23, 29, 32, 38, 6, 31, 2, 19, 11, 10, 20, 15, 17, 13, 2, 3, 22, 39, 8, 36, 14, 13, 18, 20, 30, 35, 10, 33, 42, 5, 8, 25, 3, 6, 8, 4, 22, 46, 20, 1, 14, 24, 11, 2};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {43, 9, 47, 14, 16, 19, 13, 15, 5, 9, 22, 21, 10, 7, 34, 27, 4, 6, 45, 19, 17, 18, 7, 26, 37, 41, 15, 17, 5, 16, 21, 11, 16, 12, 7, 12, 4, 9, 44, 23, 40, 3, 28, 12, 23, 1};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(47, theObject.countWays(knob1, knob2),4194304L);
  }
  {
    int knob1ARRAY[] = {1};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {2};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(0, theObject.countWays(knob1, knob2),2L);
  }
  {
    int knob1ARRAY[] = {1,1};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {2,3};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(1, theObject.countWays(knob1, knob2),2L);
  }
  {
    int knob1ARRAY[] = {1,1,1,1};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {2,3,4,5};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(2, theObject.countWays(knob1, knob2),0L);
  }
  {
    int knob1ARRAY[] = {6,6,6,4,1};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {1,2,4,5,3};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(3, theObject.countWays(knob1, knob2),0L);
  }
  {
    int knob1ARRAY[] = {1,1,2,2,11,11,8,8,3,3,4,4,5};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {2,3,11,8,12,13,9,10,4,5,7,6,14};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(4, theObject.countWays(knob1, knob2),16L);
  }
  {
    int knob1ARRAY[] = {1,2,3,4,5,6,7,8,9};
    vector <int> knob1( knob1ARRAY, knob1ARRAY+ARRSIZE(knob1ARRAY) );
    int knob2ARRAY[] = {2,3,4,5,6,7,8,9,10};
    vector <int> knob2( knob2ARRAY, knob2ARRAY+ARRSIZE(knob2ARRAY) );
    HatRack theObject;
    eq(5, theObject.countWays(knob1, knob2),0L);
  }

  puts("\033[1;33mPress any key to continue...\033[0m");
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

