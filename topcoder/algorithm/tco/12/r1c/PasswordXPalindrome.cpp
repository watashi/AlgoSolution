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

struct PasswordXPalindrome {
  int minSwaps(string password);
};

const int MAXN = 26;

struct DisjointSet {
  int p[MAXN], s[MAXN];

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      s[i] = 1;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    p[i] = j;
    if (i != j) {
      s[j] += s[i];
      return true;
    } else {
      return false;
    }
  }
} ds;

int PasswordXPalindrome::minSwaps(string pass) {
  map<char, vector<int> > mp;
  FOR (i, pass.size()) {
    mp[pass[i]].push_back(i);
  }
  char mid = '.';
  int pos = -1;
  FOREACH (i, mp) {
    if (i->second.size() == 1) {
      if (mid == '.') {
        mid = i->first;
        pos = i->second[0];
      } else {
        return -1;
      }
    }
  }

  int ans = 0;
  int m = pass.size() / 2;
  if (pos != -1 && pos != m) {
    swap(pass[pos], pass[m]);
    ++ans;
  }
  ds.init(26);
  FOR (i, m) {
    ds.setp(pass[i] - 'a', pass[pass.size() - 1 - i] - 'a');
  }
  FOR (i, 26) {
    if (ds.getp(i) == i) {
      ans += ds.s[i] - 1;
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
        PasswordXPalindrome theObject;
        eq(0, theObject.minSwaps("levle"),1);
    }
    {
        PasswordXPalindrome theObject;
        eq(1, theObject.minSwaps("racecar"),0);
    }
    {
        PasswordXPalindrome theObject;
        eq(2, theObject.minSwaps("abcdadcb"),3);
    }
    {
        PasswordXPalindrome theObject;
        eq(3, theObject.minSwaps("msmscielciel"),5);
    }
    {
        PasswordXPalindrome theObject;
        eq(4, theObject.minSwaps("hicanyouguesstodaywriter"),-1);
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
