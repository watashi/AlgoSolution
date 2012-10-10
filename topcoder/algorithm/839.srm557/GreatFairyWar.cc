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

struct GreatFairyWar {
	int minHP(vector <int> dps, vector <int> hp);
};

int GreatFairyWar::minHP(vector <int> dps, vector <int> hp) {
  int n = (int)dps.size(), t = 0, s = 0;
  FOR (i, n) {
    t += hp[i];
    s += dps[i] * t;
  }
  return s;
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
        int dpsARRAY[] = {1,2};
        vector <int> dps( dpsARRAY, dpsARRAY+ARRSIZE(dpsARRAY) );
        int hpARRAY[] = {3,4};
        vector <int> hp( hpARRAY, hpARRAY+ARRSIZE(hpARRAY) );
        GreatFairyWar theObject;
        eq(0, theObject.minHP(dps, hp),17);
    }
    {
        int dpsARRAY[] = {1,1,1,1,1,1,1,1,1,1};
        vector <int> dps( dpsARRAY, dpsARRAY+ARRSIZE(dpsARRAY) );
        int hpARRAY[] = {1,1,1,1,1,1,1,1,1,1};
        vector <int> hp( hpARRAY, hpARRAY+ARRSIZE(hpARRAY) );
        GreatFairyWar theObject;
        eq(1, theObject.minHP(dps, hp),55);
    }
    {
        int dpsARRAY[] = {20,12,10,10,23,10};
        vector <int> dps( dpsARRAY, dpsARRAY+ARRSIZE(dpsARRAY) );
        int hpARRAY[] = {5,7,7,5,7,7};
        vector <int> hp( hpARRAY, hpARRAY+ARRSIZE(hpARRAY) );
        GreatFairyWar theObject;
        eq(2, theObject.minHP(dps, hp),1767);
    }
    {
        int dpsARRAY[] = {5,7,7,5,7,7};
        vector <int> dps( dpsARRAY, dpsARRAY+ARRSIZE(dpsARRAY) );
        int hpARRAY[] = {20,12,10,10,23,10};
        vector <int> hp( hpARRAY, hpARRAY+ARRSIZE(hpARRAY) );
        GreatFairyWar theObject;
        eq(3, theObject.minHP(dps, hp),1998);
    }
    {
        int dpsARRAY[] = {30,2,7,4,7,8,21,14,19,12};
        vector <int> dps( dpsARRAY, dpsARRAY+ARRSIZE(dpsARRAY) );
        int hpARRAY[] = {2,27,18,19,14,8,25,13,21,30};
        vector <int> hp( hpARRAY, hpARRAY+ARRSIZE(hpARRAY) );
        GreatFairyWar theObject;
        eq(4, theObject.minHP(dps, hp),11029);
    }
    {
        int dpsARRAY[] = {1};
        vector <int> dps( dpsARRAY, dpsARRAY+ARRSIZE(dpsARRAY) );
        int hpARRAY[] = {1};
        vector <int> hp( hpARRAY, hpARRAY+ARRSIZE(hpARRAY) );
        GreatFairyWar theObject;
        eq(5, theObject.minHP(dps, hp),1);
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

