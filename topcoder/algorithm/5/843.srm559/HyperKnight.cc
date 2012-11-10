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

struct HyperKnight {
	long long countCells(int a, int b, int numRows, int numColumns, int k);
};

const llint INF = 2000000007LL;

typedef pair<llint, llint> Range;

#define MP make_pair

long long cnt(const Range& r) {
  return max(0LL, r.second - r.first);
}

Range intersection(const Range& l, const Range& r) {
  return MP(max(l.first, r.first), min(l.second, r.second));
}

long long HyperKnight::countCells(int a, int b, int r, int c, int k) {
  vector<pair<Range, Range> > v;
  const pair<Range, Range> init = MP(MP(0, r), MP(0, c));
  FOR (i, 2) {
    FOR (j, 2) {
      FOR (k, 2) {
        pair<Range, Range> t = init;
        t.first.first += a;
        t.first.second += a;
        t.second.first += b;
        t.second.second += b;
        v.push_back(t);
        a = -a;
      }
      b = -b;
    }
    swap(a, b);
  }

  long long dp[1 << 8];
  for (int i = 0; i < (1 << 8); ++i) {
    pair<Range, Range> r = init;
    for (int j = 0; j < 8; ++j) {
      if (i & (1 << j)) {
        r.first = intersection(r.first, v[j].first);
        r.second = intersection(r.second, v[j].second);
      }
    }
    dp[i] = cnt(r.first) * cnt(r.second);
  }

  long long ans = 0;
  for (int i = (1 << 8) - 1; i >= 0; --i) {
    for (int j = (1 << 8) - 1; j > i; --j) {
      if ((i & j) == i) {
        dp[i] -= dp[j];
      }
    }
    if (__builtin_popcount(i) == k) {
      ans += dp[i];
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
        HyperKnight theObject;
        eq(0, theObject.countCells(2, 1, 8, 8, 4),20L);
    }
    {
        HyperKnight theObject;
        eq(1, theObject.countCells(3, 2, 8, 8, 2),16L);
    }
    {
        HyperKnight theObject;
        eq(2, theObject.countCells(1, 3, 7, 11, 0),0L);
    }
    {
        HyperKnight theObject;
        eq(3, theObject.countCells(3, 2, 10, 20, 8),56L);
    }
    {
        HyperKnight theObject;
        eq(4, theObject.countCells(1, 4, 100, 10, 6),564L);
    }
    {
        HyperKnight theObject;
        eq(5, theObject.countCells(2, 3, 1000000000, 1000000000, 8),999999988000000036L);
    }
    {
        HyperKnight theObject;
        eq(5, theObject.countCells(12, 63, 1000000000, 1000000000, 1),999999988000000036L);
    }
    {
        HyperKnight theObject;
        eq(5, theObject.countCells(12, 63, 1000000000, 1000000000, 5),999999988000000036L);
    }
    {
        HyperKnight theObject;
        eq(5, theObject.countCells(12, 63, 1000000000, 1000000000, 7),999999988000000036L);
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

