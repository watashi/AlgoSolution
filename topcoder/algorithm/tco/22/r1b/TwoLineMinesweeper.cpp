#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
// BEGIN CUT HERE
#define __WATASHI__
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

struct TwoLineMinesweeper {
  vector <string> solve(vector <int> firstLine);
};

vector <string> TwoLineMinesweeper::solve(vector <int> v) {
  int n = v.size();
  vector<string> ret;
  FOR(k, 2) {
    string s;
    s.push_back(k == 0 ? '-' : '*');
    for (int i = 0; i < n; ++i) {
      int r = v[i];
      if (s[i] == '*') {
        --r;
      }
      if (i > 0 && s[i - 1] == '*') {
        --r;
      }
      if (r == 0) {
        s.push_back('-');
      }
      else if (r == 1) {
        s.push_back('*');
      }
      else {
        s.clear();
        break;
      }
    }
    if (!s.empty() && s.back() == '-') {
      s.pop_back();
      ret.push_back(s);
    }
  }
  sort(ALL(ret));
  return ret;
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
        int firstLineARRAY[] = {0, 0, 0, 0, 0, 0};
        vector <int> firstLine( firstLineARRAY, firstLineARRAY+ARRSIZE(firstLineARRAY) );
        string retrunValueARRAY[] = {"------" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TwoLineMinesweeper theObject;
        eq(0, theObject.solve(firstLine),retrunValue);
    }
    {
        int firstLineARRAY[] = {0, 0, 1, 1, 1, 0};
        vector <int> firstLine( firstLineARRAY, firstLineARRAY+ARRSIZE(firstLineARRAY) );
        string retrunValueARRAY[] = {"---*--" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TwoLineMinesweeper theObject;
        eq(1, theObject.solve(firstLine),retrunValue);
    }
    {
        int firstLineARRAY[] = {1, 1};
        vector <int> firstLine( firstLineARRAY, firstLineARRAY+ARRSIZE(firstLineARRAY) );
        string retrunValueARRAY[] = {"*-", "-*" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TwoLineMinesweeper theObject;
        eq(2, theObject.solve(firstLine),retrunValue);
    }
    {
        int firstLineARRAY[] = {2, 2, 2, 2, 2};
        vector <int> firstLine( firstLineARRAY, firstLineARRAY+ARRSIZE(firstLineARRAY) );
        string retrunValueARRAY[] = {"**-**" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TwoLineMinesweeper theObject;
        eq(3, theObject.solve(firstLine),retrunValue);
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
