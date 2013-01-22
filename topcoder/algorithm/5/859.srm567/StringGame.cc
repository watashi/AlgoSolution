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

struct StringGame {
  vector <int> getWinningStrings(vector <string> S);
};

bool gao(int n, vector<vector<int> > v) {
  vector<int> cur;
  for (int i = 1; i < n; ++i) {
    cur.push_back(i);
    FOR (j, 26) {
      v[i][j] -= v[0][j];
    }
  }
  while (!cur.empty()) {
    int pos = -1;
    FOR (j, 26) {
      bool gt = false, lt = false;
      for (vector<int>::const_iterator i = cur.begin(); i != cur.end(); ++i) {
        if (v[*i][j] > 0) {
          gt = true;
        }
        if (v[*i][j] < 0) {
          lt = true;
        }
      }
      if (!gt && lt) {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      break;
    } else {
      vector<int> pre(cur);
      cur.clear();
      for (vector<int>::const_iterator i = pre.begin(); i != pre.end(); ++i) {
        if (v[*i][pos] == 0) {
          cur.push_back(*i);
        }
      }
    }
  }
  return cur.empty();
}

vector <int> StringGame::getWinningStrings(vector <string> s) {
  int n = s.size();
  int m = s[0].size();
  vector<vector<int> > v;
  FOR (i, n) {
    vector<int> w(26, 0);
    FOR (j, m) {
      ++w[s[i][j] - 'a'];
    }
    v.push_back(w);
  }
  vector<int> ans;
  FOR (i, n) {
    swap(v[0], v[i]);
    if (gao(n, v)) {
      ans.push_back(i);
    }
    swap(v[0], v[i]);
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
        string SARRAY[] = {"a", "b", "c", "d"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        int retrunValueARRAY[] = {0, 1, 2, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StringGame theObject;
        eq(0, theObject.getWinningStrings(S),retrunValue);
    }
    {
        string SARRAY[] = {"aabbcc", "aaabbb", "aaaccc"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        int retrunValueARRAY[] = {1, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StringGame theObject;
        eq(1, theObject.getWinningStrings(S),retrunValue);
    }
    {
        string SARRAY[] = {"ab", "ba"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        StringGame theObject;
        eq(2, theObject.getWinningStrings(S),vector <int>());
    }
    {
        string SARRAY[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        int retrunValueARRAY[] = {1, 3, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StringGame theObject;
        eq(3, theObject.getWinningStrings(S),retrunValue);
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
