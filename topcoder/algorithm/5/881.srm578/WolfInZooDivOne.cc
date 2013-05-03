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

struct WolfInZooDivOne {
  int count(int N, vector <string> L, vector <string> R);
};

vector<int> parse(const vector<string>& v) {
  vector<int> ret;
  string str;
  FOREACH (i, v) {
    str += *i;
  }
  istringstream iss(str);
  int tmp;
  while (iss >> tmp) {
    ret.push_back(tmp);
  }
  return ret;
}

typedef long long llint;
const int MAXN = 303;
const llint MOD = 1000000007;

llint dp[MAXN][MAXN];

int WolfInZooDivOne::count(int N, vector <string> L, vector <string> R) {
  vector<int> vl = parse(L), vr = parse(R);
  int n = vl.size(), m = N;

  vector<int> v;
  FOR (i, m + 1) {
    v.push_back(i - 1);
  }
  FOR (i, n) {
    v[vr[i] + 1] = min(v[vr[i] + 1], vl[i]);
  }
  for (int i = m; i > 0; --i) {
    v[i - 1] = min(v[i - 1], v[i]);
  }

  MEMSET(dp, 0);
  for (int i = 1; i <= m; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j < i; ++j) {
      dp[i][j] = 0;
      for (int k = 0; k <= v[i]; ++k) {
        dp[i][j] += dp[j][k];
      }
      dp[i][j] %= MOD;
    }
  }

  llint ans = 1;
  FOR (i, MAXN) {
    FOR (j, MAXN) {
      ans += dp[i][j];
    }
  }
  return ans % MOD;
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
        string LARRAY[] = {"0"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"4"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(0, theObject.count(5, L, R),16);
    }
    {
        string LARRAY[] = {"0 1"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"2 4"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(1, theObject.count(5, L, R),21);
    }
    {
        string LARRAY[] = {"0 4 2 7"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"3 9 5 9"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(2, theObject.count(10, L, R),225);
    }
    {
        string LARRAY[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
        vector <string> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        string RARRAY[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
        vector <string> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        WolfInZooDivOne theObject;
        eq(3, theObject.count(100, L, R),6419882);
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
