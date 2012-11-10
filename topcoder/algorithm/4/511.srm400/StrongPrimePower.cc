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

struct StrongPrimePower {
	vector <int> baseAndExponent(string n);
};

bool isprime(long long x) {
	for (long long i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

long long log(long long x, long long p) {
	long long q = 0;
	while (x % p == 0) {
		x /= p;
		++q;
	}
	return x == 1 ? q : -1;
}

vector <int> StrongPrimePower::baseAndExponent(string n) {
	vector<int> ret;
	long long x = strtoll(n.c_str(), NULL, 0);
	for (int q = 64; q > 1; --q) {
		long long p = pow((double)x, 1.0 / q);
		if (p > 1 && log(x, p) == q && isprime(p)) {
			if (isprime(p)) {
				ret.push_back(p);
				ret.push_back(q);
			}
			return ret;
		}
		++p;
		if (p > 1 && log(x, p) == q && isprime(p)) {
			ret.push_back(p);
			ret.push_back(q);
			return ret;
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
        int retrunValueARRAY[] = {3, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StrongPrimePower theObject;
        eq(0, theObject.baseAndExponent("27"),retrunValue);
    }
    {
        StrongPrimePower theObject;
        eq(1, theObject.baseAndExponent("10"),vector <int>());
    }
    {
        StrongPrimePower theObject;
        eq(2, theObject.baseAndExponent("7"),vector <int>());
    }
    {
        StrongPrimePower theObject;
        eq(3, theObject.baseAndExponent("1296"),vector <int>());
    }
    {
        int retrunValueARRAY[] = {2, 59 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StrongPrimePower theObject;
        eq(4, theObject.baseAndExponent("576460752303423488"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {999999937, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StrongPrimePower theObject;
        eq(5, theObject.baseAndExponent("999999874000003969"),retrunValue);
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
