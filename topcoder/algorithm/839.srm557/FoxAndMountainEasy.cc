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

struct FoxAndMountainEasy {
	string possible(int n, int h0, int hn, string history);
};

string FoxAndMountainEasy::possible(int n, int h0, int hn, string history) {
  int s = 0, t = 0;
  for (int i = 0; i < (int)history.length(); ++i) {
    if (history[i] == 'U') {
      ++t;
    } else if (history[i] == 'D') {
      --t;
    }
    while (t < 0) {
      ++s;
      ++t;
    }
  }
  n -= (int)history.size();

  if (h0 < s) {
    n -= s - h0;
  } else {
    t = h0 + (t - s);
  }
  n -= abs(hn - t);

  return n >= 0 && n % 2 == 0 ? "YES" : "NO";
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
        FoxAndMountainEasy theObject;
        eq(0, theObject.possible(4, 0, 4, "UU"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(1, theObject.possible(4, 0, 4, "D"),"NO");
    }
    {
        FoxAndMountainEasy theObject;
        eq(2, theObject.possible(4, 100000, 100000, "DDU"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(3, theObject.possible(4, 0, 0, "DDU"),"NO");
    }
    {
        FoxAndMountainEasy theObject;
        eq(4, theObject.possible(20, 20, 20, "UDUDUDUDUD"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(5, theObject.possible(20, 0, 0, "UUUUUUUUUU"),"YES");
    }
    {
        FoxAndMountainEasy theObject;
        eq(6, theObject.possible(20, 0, 0, "UUUUUUUUUUU"),"NO");
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

