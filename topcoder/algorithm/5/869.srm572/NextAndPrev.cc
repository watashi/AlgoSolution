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

struct NextAndPrev {
  int getMinimum(int nextCost, int prevCost, string start, string goal);
};

int NextAndPrev::getMinimum(int nextCost, int prevCost, string start, string goal) {
  int n = start.size();
  map<int, int> mp;
  bool diff = false;
  set<int> st;
  FOR (i, n) {
    int s = start[i] - 'a';
    int t = goal[i] - 'a';
    if (s != t) {
      diff = true;
    }
    st.insert(t);
    if (mp.count(s) > 0 && mp[s] != t) {
      return -1;
    } else {
      mp[s] = t;
    }
  }
  if (diff && st.size() == 26) { // !IMPORTANT!
    return -1;
  }
  int ans = -1;
  FOR (ibase, 26) {
    FOR (jbase, 26) {
      int end = -1;
      map<int, vector<int> > todo;
      FOR (i, 26) {
        int l = (i + ibase) % 26;
        if (mp.count(l) != 0) {
          int r = mp[l];
          int j = (r - jbase + 26) % 26;
          if (j < end) {
            goto NEXT;
          } else {
            end = j;
          }
          todo[j].push_back(i);
        }
      }

      for (int off = -1; off <= 1; ++off) { // !IMPORTANT!
        int tmp = 0;
        for (map<int, vector<int> >::const_iterator i = todo.begin(); i != todo.end(); ++i) {
          int top = ibase + *min_element(ALL(i->second));
          int bot = ibase + *max_element(ALL(i->second));
          int dest = 26 * off + jbase + i->first;
          if (dest < top) {
            tmp += (bot - dest) * prevCost;
          } else if (dest > bot) {
            tmp += (dest - top) * nextCost;
          } else {
            tmp += (bot - dest) * prevCost;
            tmp += (dest - top) * nextCost;
          }
        }
        if (ans == -1 || ans > tmp) {
          ans = tmp;
        }
      }
NEXT:
      continue;
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
        NextAndPrev theObject;
        eq(0, theObject.getMinimum(5, 8, "aeaae", "bcbbc"),21);
    }
    {
        NextAndPrev theObject;
        eq(1, theObject.getMinimum(5, 8, "aeaae", "bccbc"),-1);
    }
    {
        NextAndPrev theObject;
        eq(2, theObject.getMinimum(1, 1, "srm", "srm"),0);
    }
    {
        NextAndPrev theObject;
        eq(3, theObject.getMinimum(1000, 39, "a", "b"),975);
    }
    {
        NextAndPrev theObject;
        eq(4, theObject.getMinimum(123, 456, "pqrs", "abab"),-1);
    }
    {
        NextAndPrev theObject;
        eq(5, theObject.getMinimum(100, 19, "topcoder", "ssszsffs"),676);
    }
    {
        NextAndPrev theObject;
        eq(6, theObject.getMinimum(1, 1000, "csk", "wog"),64);
    }
    {
        NextAndPrev theObject;
        eq(7, theObject.getMinimum(7, 6, "qwerty", "jjjjjj"),125);
    }
    {
        NextAndPrev theObject;
        eq(8, theObject.getMinimum(306, 26, "me", "ii"),572);
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
