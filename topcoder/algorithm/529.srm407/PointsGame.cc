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

struct PointsGame {
	double gameValue(vector <int> pointsX, vector <int> pointsY);
};

int n;
vector<int> x;
vector<int> y;

double gaoa(int a, int b);
double gaob(int a, int b);

// double rem[2][1 << 12][1 << 12]; // MLE

double gao(int a, int b) {
	double ret = 0.0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((a & (1 << i)) != 0 && (b & (1 << j)) != 0) {
				ret += hypot(x[i] - x[j], y[i] - y[j]);
			}
		}
	}
	return ret;
}

map<PII, double> rema;

double gaoa(int a, int b) {
	if (rema.count(PII(a, b)) != 0) {
		return rema[PII(a, b)];
	} else if ((a ^ b) == (1 << n) - 1) {
		return rema[PII(a, b)] = gao(a, b);
	} else {
		double &ret = rema[PII(a, b)];
		ret = 0.0;
		for (int i = 0; i < n; ++i) {
			if ((a & (1 << i)) == 0 && (b & (1 << i)) == 0) {
				ret = max(ret, gaob(a ^ (1 << i), b));
			}
		}
		return ret;
	}
}

map<PII, double> remb;

double gaob(int a, int b) {
	if (remb.count(PII(a, b)) != 0) {
		return remb[PII(a, b)];
	} else if ((a ^ b) == (1 << n) - 1) {
		return remb[PII(a, b)] = gao(a, b);
	} else {
		double &ret = remb[PII(a, b)];
		ret = 1e100;
		for (int i = 0; i < n; ++i) {
			if ((a & (1 << i)) == 0 && (b & (1 << i)) == 0) {
				ret = min(ret, gaoa(a, b ^ (1 << i)));
			}
		}
		return ret;
	}
}

double PointsGame::gameValue(vector <int> pointsX, vector <int> pointsY) {
	n = pointsX.size();
	x = pointsX;
	y = pointsY;
	rema.clear();
	remb.clear();
	return gaoa(0, 0);
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
        int pointsXARRAY[] = {0,0};
        vector <int> pointsX( pointsXARRAY, pointsXARRAY+ARRSIZE(pointsXARRAY) );
        int pointsYARRAY[] = {0,1};
        vector <int> pointsY( pointsYARRAY, pointsYARRAY+ARRSIZE(pointsYARRAY) );
        PointsGame theObject;
        eq(0, theObject.gameValue(pointsX, pointsY),1.0);
    }
    {
        int pointsXARRAY[] = {0,0,1,1};
        vector <int> pointsX( pointsXARRAY, pointsXARRAY+ARRSIZE(pointsXARRAY) );
        int pointsYARRAY[] = {0,5,0,5};
        vector <int> pointsY( pointsYARRAY, pointsYARRAY+ARRSIZE(pointsYARRAY) );
        PointsGame theObject;
        eq(1, theObject.gameValue(pointsX, pointsY),12.198039027185569);
    }
    {
        int pointsXARRAY[] = {0,0,0,0};
        vector <int> pointsX( pointsXARRAY, pointsXARRAY+ARRSIZE(pointsXARRAY) );
        int pointsYARRAY[] = {0,1,5,6};
        vector <int> pointsY( pointsYARRAY, pointsYARRAY+ARRSIZE(pointsYARRAY) );
        PointsGame theObject;
        eq(2, theObject.gameValue(pointsX, pointsY),12.0);
    }
    {
        int pointsXARRAY[] = {0,1,2,3};
        vector <int> pointsX( pointsXARRAY, pointsXARRAY+ARRSIZE(pointsXARRAY) );
        int pointsYARRAY[] = {0,0,0,0};
        vector <int> pointsY( pointsYARRAY, pointsYARRAY+ARRSIZE(pointsYARRAY) );
        PointsGame theObject;
        eq(3, theObject.gameValue(pointsX, pointsY),6.0);
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
