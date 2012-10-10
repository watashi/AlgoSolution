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
#define WATASHI_PC

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
#ifndef WATASHI_PC
#define errf(fmt, ...) do { } while (false)
#endif

struct FoxAndMountain {
	int count(int n, string history);
};

const int MAXN = 64;
const long long MOD = 1000000009LL;

int e[MAXN][2];
long long dp[MAXN][MAXN][MAXN];

int match(string a, string b) {
  while (a.substr(0, b.length()) != b) {
    b = b.substr(1);
  }
  return b.length();
}

void add(long long& a, long long b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int FoxAndMountain::count(int n, string history) {
  int m = history.size();
  for (int i = 0; i < m; ++i) {
    e[i][0] = match(history, history.substr(0, i) + "U");
    e[i][1] = match(history, history.substr(0, i) + "D");
  }
  e[m][0] = e[m][1] = m;

  MEMSET(dp, 0);
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= m; ++k) {
        if (j + 1 < MAXN + MAXN) {
          add(dp[i + 1][j + 1][e[k][0]], dp[i][j][k]);
        }
        if (j - 1 >= 0) {
          add(dp[i + 1][j - 1][e[k][1]], dp[i][j][k]);
        }
      }
    }
  }
  return dp[n][0][m];
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

template<typename S, typename T>
void eq(int id, S v1, T v2) {
	ostringstream s1, s2;

	s1 << v1;
	s2 << v2;

	errf("Case #%d: ", id);
	if (s1.str() == s2.str()) {
		errf("\033[1;32mPassed\033[0m\n");
	} else {
		errf("\033[1;31mFailed\033[0m\n");
		errf("\tReceived \"%s\"\n", s1.str().c_str());
		errf("\tExpected \"%s\"\n", s2.str().c_str());
	}
}

int main(int argc, char *argv[]) {
	    {
        FoxAndMountain theObject;
        eq(0, theObject.count(4, "UUDD"),1);
    }
    {
        FoxAndMountain theObject;
        eq(1, theObject.count(4, "DUUD"),0);
    }
    {
        FoxAndMountain theObject;
        eq(2, theObject.count(4, "UU"),1);
    }
    {
        FoxAndMountain theObject;
        eq(3, theObject.count(49, "U"),0);
    }
    {
        FoxAndMountain theObject;
        eq(4, theObject.count(20, "UUUDUUU"),990);
    }
    {
        FoxAndMountain theObject;
        eq(5, theObject.count(30, "DUDUDUDUDUDUDUDU"),3718);
    }
    {
        FoxAndMountain theObject;
        eq(6, theObject.count(50, "U"),946357703);
    }

	puts("\033[1;33mPress any key to continue...\033[0m");
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

