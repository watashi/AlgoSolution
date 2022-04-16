#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
#define __WATASHI__
// BEGIN CUT HERE
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
// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct HIndex {
  int cheat(vector <int> realCitations, int budget, int citationPrice);
};

int HIndex::cheat(vector <int> v, int budget, int citationPrice) {
  int n = v.size();
  int m = budget / citationPrice;
  sort(v.rbegin(), v.rend());
  FOR (i, n) {
    int r = m;
    FOR(j, i + 1) {
      if (v[j] < i + 1) {
        r -= i + 1 - v[j];
      }
    }
    if (r < 0) {
      return i;
    }
  }
  return n;
}

// BEGIN CUT HERE
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
        int realCitationsARRAY[] = {25, 3, 5, 3, 8, 0};
        vector <int> realCitations( realCitationsARRAY, realCitationsARRAY+ARRSIZE(realCitationsARRAY) );
        HIndex theObject;
        eq(0, theObject.cheat(realCitations, 447, 1000),3);
    }
    {
        int realCitationsARRAY[] = {25, 3, 5, 3, 8, 0};
        vector <int> realCitations( realCitationsARRAY, realCitationsARRAY+ARRSIZE(realCitationsARRAY) );
        HIndex theObject;
        eq(1, theObject.cheat(realCitations, 1447, 1000),4);
    }
    {
        int realCitationsARRAY[] = {0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
        vector <int> realCitations( realCitationsARRAY, realCitationsARRAY+ARRSIZE(realCitationsARRAY) );
        HIndex theObject;
        eq(2, theObject.cheat(realCitations, 140000, 10000),4);
    }
    {
        int realCitationsARRAY[] = {0, 0, 0};
        vector <int> realCitations( realCitationsARRAY, realCitationsARRAY+ARRSIZE(realCitationsARRAY) );
        HIndex theObject;
        eq(3, theObject.cheat(realCitations, 999999999, 1000000000),0);
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
// END CUT HERE
