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

struct FactoVisors {
	int getNum(vector <int> divisors, vector <int> multiples);
};

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int FactoVisors::getNum(vector <int> divisors, vector <int> multiples) {
	int g = 0;
	FOREACH (i, multiples) {
		g = gcd(g, *i);
	}
	int n = g;
	FOREACH (i, divisors) {
		if (g % *i != 0) {
			return 0;
		} else {
			n = gcd(n, g / *i);
		}
	}
	int m = 0;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			++m;
			if (i * i < n) {
				++m;
			}
		}
	}
	return m;
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
        int divisorsARRAY[] = {1};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        int multiplesARRAY[] = {100};
        vector <int> multiples( multiplesARRAY, multiplesARRAY+ARRSIZE(multiplesARRAY) );
        FactoVisors theObject;
        eq(0, theObject.getNum(divisors, multiples),9);
    }
    {
        int divisorsARRAY[] = {6,9};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        int multiplesARRAY[] = {18};
        vector <int> multiples( multiplesARRAY, multiplesARRAY+ARRSIZE(multiplesARRAY) );
        FactoVisors theObject;
        eq(1, theObject.getNum(divisors, multiples),1);
    }
    {
        int divisorsARRAY[] = {6,9};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        int multiplesARRAY[] = {96,180};
        vector <int> multiples( multiplesARRAY, multiplesARRAY+ARRSIZE(multiplesARRAY) );
        FactoVisors theObject;
        eq(2, theObject.getNum(divisors, multiples),0);
    }
    {
        int divisorsARRAY[] = {2,4};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        int multiplesARRAY[] = {256};
        vector <int> multiples( multiplesARRAY, multiplesARRAY+ARRSIZE(multiplesARRAY) );
        FactoVisors theObject;
        eq(3, theObject.getNum(divisors, multiples),7);
    }
    {
        int divisorsARRAY[] = {1000,10000,100000};
        vector <int> divisors( divisorsARRAY, divisorsARRAY+ARRSIZE(divisorsARRAY) );
        int multiplesARRAY[] = {1000000000};
        vector <int> multiples( multiplesARRAY, multiplesARRAY+ARRSIZE(multiplesARRAY) );
        FactoVisors theObject;
        eq(4, theObject.getNum(divisors, multiples),25);
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
