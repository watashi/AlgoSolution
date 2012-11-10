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

struct TheTicketsDivOne {
	double find(int n, int m);
};

const double YES = 1.0 / 6.0;
const double NO = 2.0 / 6.0;
const double ROT = 3.0 / 6.0;

typedef pair<double, double> PDD;

const int MAXN = 1024;

PDD operator+(const PDD& lhs, const PDD& rhs) {
	return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

PDD operator*(const double& lhs, const PDD& rhs) {
	return make_pair(lhs * rhs.first, lhs * rhs.second);
}

void gao(int n, const double a[MAXN], double b[MAXN]) {
	static PDD c[MAXN];
	c[0] = PDD(ROT, YES);
	for (int i = 1; i < n; ++i) {
		c[i] = ROT * c[i - 1] + NO * PDD(0, a[i - 1]);
//		printf("c[%d][%d] = %lf %lf\n", n, i, c[i].first, c[i].second);
	}
	b[n - 1] = c[n - 1].second / (1 - c[n - 1].first);
	for (int i = 0; i < n; ++i) {
		b[i] = c[i].first * b[n - 1] + c[i].second;
//		printf("a[%d][%d] = %lf\n", n, i, b[i]);
	}
}

double a[MAXN][MAXN];

double TheTicketsDivOne::find(int n, int m) {
	a[1][0] = 1.0;
	for (int i = 2; i <= n; ++i) {
		gao(i, a[i - 1], a[i]);
	}
	return a[n][m - 1];
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
        TheTicketsDivOne theObject;
        eq(0, theObject.find(2, 1),0.4444444444444444);
    }
    {
        TheTicketsDivOne theObject;
        eq(1, theObject.find(2, 2),0.5555555555555556);
    }
    {
        TheTicketsDivOne theObject;
        eq(2, theObject.find(1, 1),1.0);
    }
    {
        TheTicketsDivOne theObject;
        eq(3, theObject.find(3, 2),0.31746031746031744);
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
