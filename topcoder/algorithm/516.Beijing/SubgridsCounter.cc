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

struct SubgridsCounter {
	int howMany(vector <int> x, vector <int> y);
};

int SubgridsCounter::howMany(vector <int> x, vector <int> y) {
	int n = x.size();
	map<int, set<int> > x2y, y2x;
	set<pair<int, int> > s;
	FOR (i, n) {
		x2y[x[i]].insert(y[i]);
		y2x[y[i]].insert(x[i]);
		s.insert(make_pair(x[i], y[i]));
	}
	int ret = 0;
	FOR (i, n) {
		FOREACH (j, x2y[x[i]]) {
			if (*j < y[i]) {
				int d = y[i] - *j;
				if (s.count(make_pair(x[i] - d, y[i] - d)) > 0 &&
					s.count(make_pair(x[i] - d, y[i]    )) > 0 &&
					s.count(make_pair(x[i] - d, y[i] + d)) > 0 &&
					s.count(make_pair(x[i]    , y[i] - d)) > 0 &&
					s.count(make_pair(x[i]    , y[i] + d)) > 0 &&
					s.count(make_pair(x[i] + d, y[i] - d)) > 0 &&
					s.count(make_pair(x[i] + d, y[i]    )) > 0 &&
					s.count(make_pair(x[i] + d, y[i] + d)) > 0) {
					++ret;
				}
			}
		}
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
        int xARRAY[] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        SubgridsCounter theObject;
        eq(0, theObject.howMany(x, y),4);
    }
    {
        int xARRAY[] = {7,0,14,0,7,14,14,0,7};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {14,0,14,14,7,7,0,7,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        SubgridsCounter theObject;
        eq(1, theObject.howMany(x, y),1);
    }
    {
        int xARRAY[] = {6,6,3,0,0,3,0,3,6,1,2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {6,3,0,0,6,3,3,6,0,1,2}
           ;
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        SubgridsCounter theObject;
        eq(2, theObject.howMany(x, y),1);
    }
    {
        int xARRAY[] = {6,0,4,0,20,0,0,4,12,6,6,12,12,6,0,12,4,6,4,4,20,20,20,6,6,4,20,4,20,12,12,0,12,0,20};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {4,10,10,9,10,25,0,16,25,0,18,0,4,10,4,16,4,16,25,18,9,4,18,9,25,0,0,9,25,9,18,16,10,18,16};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        SubgridsCounter theObject;
        eq(3, theObject.howMany(x, y),1);
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
