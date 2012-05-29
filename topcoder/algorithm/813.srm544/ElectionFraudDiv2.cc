#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
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

struct ElectionFraudDiv2 {
	string IsFraudulent(vector <int> percentages);
};

string ElectionFraudDiv2::IsFraudulent(vector <int> p) {
    int n = (int)p.size();
    llint sl = 0, sr = 0;
    vector<llint> l, r;
    for (int i = 0; i < n; ++i) {
        l.push_back(max(0, p[i] * 2 - 1));
        r.push_back(min(200, p[i] * 2 + 1));    //
        sl += l.back();
        sr += r.back();
    }
    if (count(ALL(p), 0) == n - 1 && count(ALL(p), 100) == 1) {
        return "NO";
    } else if (sl <= 200 && 200 < sr) {
        return "NO";
    } else {
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
        int percentagesARRAY[] = {100};
        vector <int> percentages( percentagesARRAY, percentagesARRAY+ARRSIZE(percentagesARRAY) );
        ElectionFraudDiv2 theObject;
        eq(0, theObject.IsFraudulent(percentages),"NO");
    }
    {
        int percentagesARRAY[] = {34, 34, 34};
        vector <int> percentages( percentagesARRAY, percentagesARRAY+ARRSIZE(percentagesARRAY) );
        ElectionFraudDiv2 theObject;
        eq(1, theObject.IsFraudulent(percentages),"YES");
    }
    {
        int percentagesARRAY[] = {12, 12, 12, 12, 12, 12, 12, 12};
        vector <int> percentages( percentagesARRAY, percentagesARRAY+ARRSIZE(percentagesARRAY) );
        ElectionFraudDiv2 theObject;
        eq(2, theObject.IsFraudulent(percentages),"YES");
    }
    {
        int percentagesARRAY[] = {13, 13, 13, 13, 13, 13, 13, 13};
        vector <int> percentages( percentagesARRAY, percentagesARRAY+ARRSIZE(percentagesARRAY) );
        ElectionFraudDiv2 theObject;
        eq(3, theObject.IsFraudulent(percentages),"NO");
    }
    {
        int percentagesARRAY[] = {0, 1, 100};
        vector <int> percentages( percentagesARRAY, percentagesARRAY+ARRSIZE(percentagesARRAY) );
        ElectionFraudDiv2 theObject;
        eq(4, theObject.IsFraudulent(percentages),"NO");
    }
    {
        int percentagesARRAY[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8};
        vector <int> percentages( percentagesARRAY, percentagesARRAY+ARRSIZE(percentagesARRAY) );
        ElectionFraudDiv2 theObject;
        eq(5, theObject.IsFraudulent(percentages),"NO");
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

