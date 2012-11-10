#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
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

struct WaterEqualizer {
	double minTime(vector <int> waterVolumes);
};

double WaterEqualizer::minTime(vector <int> waterVolumes) {
	double sum = accumulate(waterVolumes.begin(), waterVolumes.end(), 0);
	double ave = sum / waterVolumes.size();
	sum = 0;
	for (int i = 0; i < (int)waterVolumes.size(); ++i) {
		sum += max(waterVolumes[i] - ave, 0.0);
	}
	return sum;
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
        int waterVolumesARRAY[] = {1, 2};
        vector <int> waterVolumes( waterVolumesARRAY, waterVolumesARRAY+ARRSIZE(waterVolumesARRAY) );
        WaterEqualizer theObject;
        eq(0, theObject.minTime(waterVolumes),0.5);
    }
    {
        int waterVolumesARRAY[] = {1, 2, 1, 2};
        vector <int> waterVolumes( waterVolumesARRAY, waterVolumesARRAY+ARRSIZE(waterVolumesARRAY) );
        WaterEqualizer theObject;
        eq(1, theObject.minTime(waterVolumes),1.0);
    }
    {
        int waterVolumesARRAY[] = {10, 1};
        vector <int> waterVolumes( waterVolumesARRAY, waterVolumesARRAY+ARRSIZE(waterVolumesARRAY) );
        WaterEqualizer theObject;
        eq(2, theObject.minTime(waterVolumes),4.5);
    }
    {
        int waterVolumesARRAY[] = {1, 2, 3, 4};
        vector <int> waterVolumes( waterVolumesARRAY, waterVolumesARRAY+ARRSIZE(waterVolumesARRAY) );
        WaterEqualizer theObject;
        eq(3, theObject.minTime(waterVolumes),2.0);
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
