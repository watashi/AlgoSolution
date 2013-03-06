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

struct DistinctRemainders {
  int howMany(long long N, int M);
};

const llint MOD = 1000000007LL;
const int MAXN = 100;

long long extGcd(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

long long modInv(long long a, long long m) {
	long long x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}

int DistinctRemainders::howMany(long long N, int M) {
  map<llint, llint> dp[MAXN];
  dp[0][0] = 1;
  for (int i = 0; i < M; ++i) {
    for (int j = i; j >= 0; --j) {
      for (map<llint, llint>::const_iterator k = dp[j].begin(); k != dp[j].end(); ++k) {
        dp[j + 1][k->first + i] = (dp[j + 1][k->first + i] + k->second) % MOD;
      }
    }
  }
  llint ans = 0, fact = 1;
  for (int i = 1; i <= M; ++i) {
    fact = fact * i % MOD;
    for (map<llint, llint>::const_iterator j = dp[i].begin(); j != dp[i].end(); ++j) {
      if (j->first <= N && (N - j->first) % M == 0) {
        llint n = (N - j->first) / M + (i - 1);
        llint tmp = fact * j->second % MOD;
        FOR (k, i - 1) {
          tmp *= (n - k) % MOD;
          tmp %= MOD;
          tmp *= modInv(k + 1, MOD);
          tmp %= MOD;
        }
        ans += tmp;
      }
    }
  }
  ans %= MOD;
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
        DistinctRemainders theObject;
        eq(0, theObject.howMany(3L, 2),5);
    }
    {
        DistinctRemainders theObject;
        eq(1, theObject.howMany(3L, 3),9);
    }
    {
        DistinctRemainders theObject;
        eq(2, theObject.howMany(58L, 1),1);
    }
    {
        DistinctRemainders theObject;
        eq(3, theObject.howMany(572L, 7),922572833);
    }
    {
        DistinctRemainders theObject;
        eq(4, theObject.howMany(1000000000000000000L, 20),240297629);
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
