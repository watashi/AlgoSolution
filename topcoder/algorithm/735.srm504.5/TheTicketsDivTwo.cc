#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <list>
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

struct TheTicketsDivTwo {
	double find(int n, int m, int k);
};

double gao(int n, int m, list<int>& lst) {
	if (n == 0 || lst.size() == 1) {
		return lst.front() == m ? 1.0 : 0.0; 
	} else {
		int h = lst.front();
		double ret = h == m ? 1.0 / 6.0 : 0.0;
		lst.pop_front();
		ret += 2.0 / 6.0 * gao(n - 1, m, lst);
		lst.push_back(h);
		ret += 3.0 / 6.0 * gao(n - 1, m, lst);
		lst.pop_back();
		lst.push_front(h);
		return ret;
	}
}

double TheTicketsDivTwo::find(int n, int m, int k) {
	list<int> lst;
	FOR (i, n) {
		lst.push_back(i);
	}
	return gao(k, m - 1, lst);
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
        TheTicketsDivTwo theObject;
        eq(0, theObject.find(2, 1, 1),0.16666666666666666);
    }
    {
        TheTicketsDivTwo theObject;
        eq(1, theObject.find(2, 1, 2),0.5833333333333334);
    }
    {
        TheTicketsDivTwo theObject;
        eq(2, theObject.find(7, 7, 4),0.0);
    }
    {
        TheTicketsDivTwo theObject;
        eq(3, theObject.find(4, 2, 10),0.25264033564814814);
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
