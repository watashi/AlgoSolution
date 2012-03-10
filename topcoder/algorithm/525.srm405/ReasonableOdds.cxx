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

struct ReasonableOdds {
	string check(int p1, int pDraw, int p2, int k);
};

const double EPS = 1e-6;
double c[10][10];

void init() {
	FOR (i, 10) {
		c[i][0] = 1;
		FOR (j, i) {
			c[i][j + 1] = c[i - 1][j] + c[i - 1][j + 1];
		}
	}
}

double gao(int n, int m, double p) {
	return c[n][m] * pow(p, m) * pow(1 - p, n - m);
}

double win(int n, double p, double q) {
	double r = 0.0;
	FOR (i, n + 1) {
		FOR (j, i) {
			r += gao(n, i, p) * gao(n, j, q);
		}
	}
	return r;
}

double find(int n, double p, double q) {
	double l = 0.0, r = 1.1;
	FOR (loop, 100) {
		double m = (l + r) / 2;
		if (win(n, m, p) < q) {
			l = m;
		} else {
			r = m;
		}
	}
	return (l + r) / 2;
}

string ReasonableOdds::check(int p1, int pDraw, int p2, int k) {
	if (p1 == 0 || p2 == 0 || p1 == 100 || p2 == 100) {
		return "YES";
	} else if (pDraw == 0) {
		return "NO";
	} else {
		init();	
		double x = 0.0, y = 0.0;
		FOR (loop, 1000) {
			x = find(k, y, p1 / 100.0);
			y = find(k, x, p2 / 100.0);
			//	errf("x = %lf, y = %lf\n", x, y);
			if (x > 1 || y > 1) {
				return "NO";
			}
		}
		return "YES";
	}
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
		ReasonableOdds theObject;
		eq(0, theObject.check(0, 100, 0, 1),"YES");
	}
	{
		ReasonableOdds theObject;
		eq(1, theObject.check(50, 0, 50, 1),"NO");
	}
	{
		ReasonableOdds theObject;
		eq(2, theObject.check(30, 0, 70, 5),"NO");
	}
	{
		ReasonableOdds theObject;
		eq(3, theObject.check(30, 10, 60, 2),"NO");
	}
	{
		ReasonableOdds theObject;
		eq(4, theObject.check(30, 40, 30, 2),"YES");
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
