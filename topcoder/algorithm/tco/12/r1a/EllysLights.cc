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

struct EllysLights {
  int getMinimum(string initial, vector <string> switches);
};

const int MAXN = 100;

struct DisjointSet {
  int p[MAXN], s[MAXN], t[MAXN];

  static inline int RE(int i) { return -1 - i; }

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      s[i] = 1;
      t[i] = 0;
    }
  }

  int getp(int i) {
    if (i < 0) {
      return RE(getp(RE(i)));
    } else if (i == p[i]) {
      return i;
    } else {
      return p[i] = getp(p[i]);
    }
  }

  int setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    if (i == j) {
      return 0;
    } else if (i == RE(j)) {
      return -1;
    } else {
      if (i < 0) {
        i = RE(i);
        j = RE(j);
      }
      p[i] = j;
      if (j >= 0) {
        s[j] += s[i];
        t[j] += t[i];
      } else {
        s[RE(j)] += t[i];
        t[RE(j)] += s[i];
      }
      return 1;
    }
  }
} ds;

int EllysLights::getMinimum(string s, vector <string> t) {
  int n = s.size(), m = t.size();
  int yes = m, no = m + 1;
  ds.init(m + 2);
  ds.s[yes] = ds.s[no] = 0;
  ds.setp(yes, DisjointSet::RE(no));
  FOR (i, n) {
    vector<int> v;
    FOR (j, m) {
      if (t[j][i] == 'Y') {
        v.push_back(j);
      }
    }
    errf("[%c] ", s[i]);
    errf("%d, ", v);
    switch (v.size()) {
      case 0:
        if (s[i] == 'Y') {
          return -1;
        }
        break;
      case 1:
        if (ds.setp(v[0], s[i] == 'Y' ? yes : no) == -1) {
          return -1;
        }
        break;
      case 2:
        if (ds.setp(v[0], s[i] == 'Y' ? DisjointSet::RE(v[1]) : v[1]) == -1) {
          return -1;
        }
        break;
    }
  }
  int ans = 0;
  for (int i = 0; i < m + 2; ++i) {
    if (ds.getp(i) == i) {
      if (ds.getp(yes) == i) {
        ans += ds.s[i];
      } else if (ds.getp(no) == i) {
        ans += ds.t[i];
      } else {
        ans += min(ds.s[i], ds.t[i]);
      }
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
        string switchesARRAY[] = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(0, theObject.getMinimum("YNYNNN", switches),2);
    }
    {
        string switchesARRAY[] = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(1, theObject.getMinimum("YNYNYN", switches),4);
    }
    {
        string switchesARRAY[] = {"YNY", "NYN"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(2, theObject.getMinimum("YYN", switches),-1);
    }
    {
        string switchesARRAY[] = {"NYNYNYNYNYNYNYNY",
            "YNYNYNYNYNYNYNYN",
            "NNNNNNNNNNNNNNNN",
            "YNNNNNNNNNNNNNNN",
            "NYNNNNNNNNNNNNNN",
            "NNYNNNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNN",
            "NNNNYNNNNNNNNNNN",
            "NNNNNYNNNNNNNNNN",
            "NNNNNNYNNNNNNNNN",
            "NNNNNNNYNNNNNNNN",
            "NNNNNNNNYNNNNNNN",
            "NNNNNNNNNYNNNNNN",
            "NNNNNNNNNNYNNNNN",
            "NNNNNNNNNNNYNNNN",
            "NNNNNNNNNNNNYNNN",
            "NNNNNNNNNNNNNYNN",
            "NNNNNNNNNNNNNNYN",
            "NNNNNNNNNNNNNNNY"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(3, theObject.getMinimum("NNYNYNYYYNNYYYYN", switches),6);
    }
    {
        string switchesARRAY[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
            "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
            "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
            "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
            "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
            "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
            "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
            "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
            "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
            "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
            "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(4, theObject.getMinimum("NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY", switches),7);
    }
    {
        string switchesARRAY[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
            "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
            "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
            "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
            "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
            "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
            "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
            "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
            "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
            "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
            "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
            "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
            "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
            "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"};
        vector <string> switches( switchesARRAY, switchesARRAY+ARRSIZE(switchesARRAY) );
        EllysLights theObject;
        eq(5, theObject.getMinimum("NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN", switches),-1);
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
