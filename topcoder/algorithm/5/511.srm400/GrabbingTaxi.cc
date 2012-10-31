#include <algorithm>
#include <iostream>
#include <sstream>
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

struct GrabbingTaxi {
	int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime);
};

int GrabbingTaxi::minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime) {
	int ret = walkTime * (abs(gX) + abs(gY));
	FOR(i, tXs.size()) {
		ret = min(ret, walkTime * (abs(tXs[i]) + abs(tYs[i])) +
			taxiTime * (abs(tXs[i] - gX) + abs(tYs[i] - gY)));
	}
	return ret;
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
        GrabbingTaxi theObject;
        eq(0, theObject.minTime(vector <int>(), vector <int>(), 3, 2, 10, 2),50);
    }
    {
        int tXsARRAY[] = {-2, -2};
        vector <int> tXs( tXsARRAY, tXsARRAY+ARRSIZE(tXsARRAY) );
        int tYsARRAY[] = {0, -2};
        vector <int> tYs( tYsARRAY, tYsARRAY+ARRSIZE(tYsARRAY) );
        GrabbingTaxi theObject;
        eq(1, theObject.minTime(tXs, tYs, -4, -2, 15, 3),42);
    }
    {
        int tXsARRAY[] = {3};
        vector <int> tXs( tXsARRAY, tXsARRAY+ARRSIZE(tXsARRAY) );
        int tYsARRAY[] = {0};
        vector <int> tYs( tYsARRAY, tYsARRAY+ARRSIZE(tYsARRAY) );
        GrabbingTaxi theObject;
        eq(2, theObject.minTime(tXs, tYs, 5, 0, 10, 20),50);
    }
    {
        int tXsARRAY[] = {34, -12, 1, 0, 21, -43, -98, 11, 86, -31};
        vector <int> tXs( tXsARRAY, tXsARRAY+ARRSIZE(tXsARRAY) );
        int tYsARRAY[] = {11, 5, -68, 69, -78, -49, -36, -2, 1, 70};
        vector <int> tYs( tYsARRAY, tYsARRAY+ARRSIZE(tYsARRAY) );
        GrabbingTaxi theObject;
        eq(3, theObject.minTime(tXs, tYs, -97, -39, 47, 13),2476);
    }
    {
        int tXsARRAY[] = {82, -60, 57, 98, 30, -67, 84, -42, -100, 62};
        vector <int> tXs( tXsARRAY, tXsARRAY+ARRSIZE(tXsARRAY) );
        int tYsARRAY[] = {-7, 90, 53, -56, -15, -87, 22, -3, -61, -30};
        vector <int> tYs( tYsARRAY, tYsARRAY+ARRSIZE(tYsARRAY) );
        GrabbingTaxi theObject;
        eq(4, theObject.minTime(tXs, tYs, 21, 15, 53, 2),1908);
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
