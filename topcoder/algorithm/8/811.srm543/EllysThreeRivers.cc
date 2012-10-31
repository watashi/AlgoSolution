#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
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

struct EllysThreeRivers {
	double getMin(int length, int walk, vector <int> width, vector <int> swim);
};

double w1, w2, w3, v0, v1, v2, v3;

double eval1(double a, double b) {
    return hypot(w1, a - b) / v1 + b / v0;
}

double eval2(double a, double b) {
    return hypot(w2, a - b) / v2 + hypot(w3, b) / v3;
}

template<typename F>
double ternary(double h, F f) {
    double l = 0, r = h;
    for (int i = 0; i < 100; ++i) {
        double m1 = (l + l + r) / 3;
        double m2 = (l + r + r) / 3;
        if (f(h, m1) < f(h, m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return f(h, r);
}

double eval(double h, double m) {
    return ternary(h - m, eval1) + ternary(m, eval2);
}

double EllysThreeRivers::getMin(int length, int walk, vector <int> width, vector <int> swim) {
    v0 = walk;
    w1 = width[0];
    w2 = width[1];
    w3 = width[2];
    v1 = swim[0];
    v2 = swim[1];
    v3 = swim[2];
    return ternary(length, eval);
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
        int widthARRAY[] = {5, 2, 3};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int swimARRAY[] = {5, 2, 7};
        vector <int> swim( swimARRAY, swimARRAY+ARRSIZE(swimARRAY) );
        EllysThreeRivers theObject;
        eq(0, theObject.getMin(10, 8, width, swim),3.2063518370413364);
    }
    {
        int widthARRAY[] = {91, 911, 85};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int swimARRAY[] = {28, 97, 19};
        vector <int> swim( swimARRAY, swimARRAY+ARRSIZE(swimARRAY) );
        EllysThreeRivers theObject;
        eq(1, theObject.getMin(1000, 100, width, swim),21.549321613601297);
    }
    {
        int widthARRAY[] = {777, 888, 999};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int swimARRAY[] = {11, 12, 13};
        vector <int> swim( swimARRAY, swimARRAY+ARRSIZE(swimARRAY) );
        EllysThreeRivers theObject;
        eq(2, theObject.getMin(666, 4, width, swim),228.26633673141083);
    }
    {
        int widthARRAY[] = {2, 3, 4};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int swimARRAY[] = {77, 88, 99};
        vector <int> swim( swimARRAY, swimARRAY+ARRSIZE(swimARRAY) );
        EllysThreeRivers theObject;
        eq(3, theObject.getMin(6, 100, width, swim),0.12049782476139667);
    }
    {
        int widthARRAY[] = {444, 588, 263};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int swimARRAY[] = {67, 97, 26};
        vector <int> swim( swimARRAY, swimARRAY+ARRSIZE(swimARRAY) );
        EllysThreeRivers theObject;
        eq(4, theObject.getMin(873, 54, width, swim),26.365540023205206);
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

