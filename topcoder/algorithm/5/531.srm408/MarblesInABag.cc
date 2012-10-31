#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstring>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
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

struct MarblesInABag {
	double getProbability(int redCount, int blueCount);
};

const int MAXN = 4096;

double MarblesInABag::getProbability(int redCount, int blueCount) {
	int n = redCount + blueCount, m = blueCount;
	double dp[2][MAXN], *pre = dp[0], *cur = dp[1];
	fill(cur, cur + m + 1, 0.0);
	cur[1] = 1.0;
	for (int i = 3; i <= n; i += 2) {
		swap(pre, cur);
		fill(cur, cur + m + 1, 0.0);
		for (int j = 2; j <= i && j <= m; ++j) {
			double p = 1.0 * j / i;
			cur[j] = p * pre[j - 2] + (1 - p) * pre[j - 1];
		}
	}
	return cur[m];
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
        MarblesInABag theObject;
        eq(0, theObject.getProbability(1, 2),0.3333333333333333);
    }
    {
        MarblesInABag theObject;
        eq(1, theObject.getProbability(2, 3),0.13333333333333333);
    }
    {
        MarblesInABag theObject;
        eq(2, theObject.getProbability(2, 5),0.22857142857142856);
    }
    {
        MarblesInABag theObject;
        eq(3, theObject.getProbability(11, 6),0.0);
    }
    {
        MarblesInABag theObject;
        eq(4, theObject.getProbability(4, 11),0.12183372183372182);
    }

	puts("\033[1;33mPress any key to continue...\033[0m");
	getchar();

	return 0;
}

/*
 * first second iterator
 * push_back priority_queue
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE
