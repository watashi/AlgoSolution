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

struct OlympicCandles {
	int numberOfNights(vector <int> candles);
};

int OlympicCandles::numberOfNights(vector <int> candles) {
	int n = candles.size();
	FOR (i, n) {
		sort(candles.rbegin(), candles.rend());
		FOR (j, i + 1) {
			if (candles[j]-- == 0) {
				return i;
			}
		}
	}
	return n;
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
        int candlesARRAY[] = {2, 2, 2};
        vector <int> candles( candlesARRAY, candlesARRAY+ARRSIZE(candlesARRAY) );
        OlympicCandles theObject;
        eq(0, theObject.numberOfNights(candles),3);
    }
    {
        int candlesARRAY[] = {2, 2, 2, 4};
        vector <int> candles( candlesARRAY, candlesARRAY+ARRSIZE(candlesARRAY) );
        OlympicCandles theObject;
        eq(1, theObject.numberOfNights(candles),4);
    }
    {
        int candlesARRAY[] = {5, 2, 2, 1};
        vector <int> candles( candlesARRAY, candlesARRAY+ARRSIZE(candlesARRAY) );
        OlympicCandles theObject;
        eq(2, theObject.numberOfNights(candles),3);
    }
    {
        int candlesARRAY[] = {1, 2, 3, 4, 5, 6};
        vector <int> candles( candlesARRAY, candlesARRAY+ARRSIZE(candlesARRAY) );
        OlympicCandles theObject;
        eq(3, theObject.numberOfNights(candles),6);
    }
    {
        int candlesARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector <int> candles( candlesARRAY, candlesARRAY+ARRSIZE(candlesARRAY) );
        OlympicCandles theObject;
        eq(4, theObject.numberOfNights(candles),4);
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
