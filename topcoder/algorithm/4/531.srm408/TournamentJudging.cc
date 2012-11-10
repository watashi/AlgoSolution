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

struct TournamentJudging {
	int getPoints(vector <int> rawScores, vector <int> conversionFactor);
};

int round(int a, int b) {
	return (a + b / 2) / b;
}

int TournamentJudging::getPoints(vector <int> rawScores, vector <int> conversionFactor) {
	int n = rawScores.size(), ret = 0;
	FOR (i, n) {
		ret += round(rawScores[i], conversionFactor[i]);
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
        int rawScoresARRAY[] = {10, 20, 30};
        vector <int> rawScores( rawScoresARRAY, rawScoresARRAY+ARRSIZE(rawScoresARRAY) );
        int conversionFactorARRAY[] = {10, 10, 5};
        vector <int> conversionFactor( conversionFactorARRAY, conversionFactorARRAY+ARRSIZE(conversionFactorARRAY) );
        TournamentJudging theObject;
        eq(0, theObject.getPoints(rawScores, conversionFactor),9);
    }
    {
        int rawScoresARRAY[] = {8, 16, 32};
        vector <int> rawScores( rawScoresARRAY, rawScoresARRAY+ARRSIZE(rawScoresARRAY) );
        int conversionFactorARRAY[] = {10, 10, 5};
        vector <int> conversionFactor( conversionFactorARRAY, conversionFactorARRAY+ARRSIZE(conversionFactorARRAY) );
        TournamentJudging theObject;
        eq(1, theObject.getPoints(rawScores, conversionFactor),9);
    }
    {
        int rawScoresARRAY[] = {60, 59};
        vector <int> rawScores( rawScoresARRAY, rawScoresARRAY+ARRSIZE(rawScoresARRAY) );
        int conversionFactorARRAY[] = {24, 24};
        vector <int> conversionFactor( conversionFactorARRAY, conversionFactorARRAY+ARRSIZE(conversionFactorARRAY) );
        TournamentJudging theObject;
        eq(2, theObject.getPoints(rawScores, conversionFactor),5);
    }
    {
        int rawScoresARRAY[] = {47, 42, 37, 30, 27, 21, 18};
        vector <int> rawScores( rawScoresARRAY, rawScoresARRAY+ARRSIZE(rawScoresARRAY) );
        int conversionFactorARRAY[] = {1, 2, 3, 4, 5, 6, 7};
        vector <int> conversionFactor( conversionFactorARRAY, conversionFactorARRAY+ARRSIZE(conversionFactorARRAY) );
        TournamentJudging theObject;
        eq(3, theObject.getPoints(rawScores, conversionFactor),100);
    }
    {
        int rawScoresARRAY[] = {0, 1000000, 5000, 1000000};
        vector <int> rawScores( rawScoresARRAY, rawScoresARRAY+ARRSIZE(rawScoresARRAY) );
        int conversionFactorARRAY[] = {1, 2, 1000000, 4};
        vector <int> conversionFactor( conversionFactorARRAY, conversionFactorARRAY+ARRSIZE(conversionFactorARRAY) );
        TournamentJudging theObject;
        eq(4, theObject.getPoints(rawScores, conversionFactor),750000);
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
