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

struct TheUltimatePackages {
  vector <int> count(int N, int D, vector <int> Xprefix, vector <int> Yprefix, int L, int seed);
};

vector <int> TheUltimatePackages::count(int N, int D, vector <int> Xprefix, vector <int> Yprefix, int L, int seed) {
  vector<int> X(D), Y(D);
  int XL = Xprefix.size();

  for (int i = 0; i < XL; ++i) {
    X[i] = Xprefix[i];
    Y[i] = Yprefix[i];
  }

  long long state = seed;
  for (int i = XL; i < D; ++i) {
    state = (state * 1103515245 + 12345) % (1LL << 31);
    int elen = 1 + state % L;
    state = (state * 1103515245 + 12345) % (1LL << 31);
    Y[i] = state % (N - elen);
    X[i] = Y[i] + elen;
  }

  map<int, int> mp;
  {
    vector<vector<int>> e(N);
    FOR(i, D) {
      e[X[i]].push_back(Y[i]);
    }
    set<int> s;
    FOR(i, N) {
      s.insert(i);
      for (auto j : e[i]) {
        s.erase(j);
      }
      if (s.size() == 1) {
        ++mp[i];
      }
    }
  }
  {
    vector<vector<int>> e(N);
    FOR(i, D) {
      e[Y[i]].push_back(X[i]);
    }
    set<int> s;
    for (int i = N - 1; i >= 0; --i) {
      s.insert(i);
      for (auto j : e[i]) {
        s.erase(j);
      }
      if (s.size() == 1) {
        ++mp[i];
      }
    }
  }

  vector<int> ret = { 0, 0 };
  for (const auto& i : mp) {
    if (i.second == 2) {
      ret[0] += 1;
      ret[1] += i.first;
    }
  }

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
        int XprefixARRAY[] = {1, 3, 2, 4};
        vector <int> Xprefix( XprefixARRAY, XprefixARRAY+ARRSIZE(XprefixARRAY) );
        int YprefixARRAY[] = {0, 2, 1, 3};
        vector <int> Yprefix( YprefixARRAY, YprefixARRAY+ARRSIZE(YprefixARRAY) );
        int retrunValueARRAY[] = {5, 10 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheUltimatePackages theObject;
        eq(0, theObject.count(5, 4, Xprefix, Yprefix, 1, 47),retrunValue);
    }
    {
        int XprefixARRAY[] = {1, 2, 3, 4, 4, 4};
        vector <int> Xprefix( XprefixARRAY, XprefixARRAY+ARRSIZE(XprefixARRAY) );
        int YprefixARRAY[] = {0, 0, 0, 1, 3, 2};
        vector <int> Yprefix( YprefixARRAY, YprefixARRAY+ARRSIZE(YprefixARRAY) );
        int retrunValueARRAY[] = {2, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheUltimatePackages theObject;
        eq(1, theObject.count(5, 6, Xprefix, Yprefix, 1, 64),retrunValue);
    }
    {
        int XprefixARRAY[] = {2, 2, 3, 4};
        vector <int> Xprefix( XprefixARRAY, XprefixARRAY+ARRSIZE(XprefixARRAY) );
        int YprefixARRAY[] = {0, 1, 2, 2};
        vector <int> Yprefix( YprefixARRAY, YprefixARRAY+ARRSIZE(YprefixARRAY) );
        int retrunValueARRAY[] = {1, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheUltimatePackages theObject;
        eq(2, theObject.count(5, 4, Xprefix, Yprefix, 1, 32532),retrunValue);
    }
    {
        int XprefixARRAY[] = {3, 3, 2};
        vector <int> Xprefix( XprefixARRAY, XprefixARRAY+ARRSIZE(XprefixARRAY) );
        int YprefixARRAY[] = {0, 2, 1};
        vector <int> Yprefix( YprefixARRAY, YprefixARRAY+ARRSIZE(YprefixARRAY) );
        int retrunValueARRAY[] = {1, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheUltimatePackages theObject;
        eq(3, theObject.count(4, 3, Xprefix, Yprefix, 1, 2555),retrunValue);
    }
    {
        int retrunValueARRAY[] = {0, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheUltimatePackages theObject;
        eq(4, theObject.count(7, 0, vector <int>(), vector <int>(), 1, 0),retrunValue);
    }
    {
        int XprefixARRAY[] = {1, 1, 1, 1};
        vector <int> Xprefix( XprefixARRAY, XprefixARRAY+ARRSIZE(XprefixARRAY) );
        int YprefixARRAY[] = {0, 0, 0, 0};
        vector <int> Yprefix( YprefixARRAY, YprefixARRAY+ARRSIZE(YprefixARRAY) );
        int retrunValueARRAY[] = {2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheUltimatePackages theObject;
        eq(5, theObject.count(2, 4, Xprefix, Yprefix, 1, 0),retrunValue);
    }
    {
        int XprefixARRAY[] = {2, 3, 4};
        vector <int> Xprefix( XprefixARRAY, XprefixARRAY+ARRSIZE(XprefixARRAY) );
        int YprefixARRAY[] = {1, 2, 3};
        vector <int> Yprefix( YprefixARRAY, YprefixARRAY+ARRSIZE(YprefixARRAY) );
        int retrunValueARRAY[] = {0, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheUltimatePackages theObject;
        eq(6, theObject.count(7, 12, Xprefix, Yprefix, 5, 4747),retrunValue);
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
