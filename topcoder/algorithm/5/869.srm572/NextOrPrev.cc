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

struct NextOrPrev {
  int getMinimum(int nextCost, int prevCost, string start, string goal);
};

int NextOrPrev::getMinimum(int nextCost, int prevCost, string s, string t) {
  map<char, char> mp;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (mp.count(s[i]) > 0 && mp[s[i]] != t[i]) {
      return -1;
    } else {
      mp[s[i]] = t[i];
    }
  }
  char end = 'a';
  map<char, vector<char> > todo;
  for (map<char, char>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
    if (it->second < end) {
      return -1;
    } else {
      end = it->second;
    }
    todo[it->second].push_back(it->first);
  }
  int ans = 0;
  for (map<char, vector<char> >::const_iterator it = todo.begin(); it != todo.end(); ++it) {
    ans += max(0, it->first - it->second.front()) * nextCost;
    ans += max(0, it->second.back() - it->first) * prevCost;
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
        NextOrPrev theObject;
        eq(0, theObject.getMinimum(5, 8, "ae", "bc"),21);
    }
    {
        NextOrPrev theObject;
        eq(1, theObject.getMinimum(5, 8, "ae", "cb"),-1);
    }
    {
        NextOrPrev theObject;
        eq(2, theObject.getMinimum(1, 1, "srm", "srm"),0);
    }
    {
        NextOrPrev theObject;
        eq(3, theObject.getMinimum(10, 1, "acb", "bdc"),30);
    }
    {
        NextOrPrev theObject;
        eq(4, theObject.getMinimum(10, 1, "zyxw", "vuts"),16);
    }
    {
        NextOrPrev theObject;
        eq(5, theObject.getMinimum(563, 440, "ptrbgcnlaizo", "rtscedkiahul"),10295);
    }
    {
        NextOrPrev theObject;
        eq(6, theObject.getMinimum(126, 311, "yovlkwpjgsna", "zpwnkytjisob"),-1);
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
