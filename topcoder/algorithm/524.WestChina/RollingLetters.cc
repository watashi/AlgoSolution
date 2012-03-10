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

struct RollingLetters {
	long long getTime(vector <string> reels, string requiredText);
};

long long extGcd(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		long long g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

long long RollingLetters::getTime(vector <string> reels, string requiredText) {
	int n = reels.size();
	long long a = 0, b = 1, g, x, y, z;
	FOR (i, n) {
		long long c = find(reels[i].begin(), reels[i].end(), requiredText[i]) - reels[i].begin();
		long long d = reels[i].length();
		if (c == d) {
			return -1;
		}
		g = extGcd(b, d, x, y);
		z = a - c;
		if (z % g != 0) {
			return -1;
		}
		printf("%lld %lld %lld\n", z / g, y, z / g * y);
		z = z / g * y;
		b = b / g * d;
	//	a = c + d * z;	// ov
		a = ((c + (d % b) * (z % b)) % b + b) % b;
		printf("%lld %lld\n", a, b);
	}
	return a;
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
        string reelsARRAY[] = {"XYZ", "DEF", "OPRS"};
        vector <string> reels( reelsARRAY, reelsARRAY+ARRSIZE(reelsARRAY) );
        RollingLetters theObject;
        eq(0, theObject.getTime(reels, "YES"),7L);
    }
    {
        string reelsARRAY[] = {"ABC","ABC"};
        vector <string> reels( reelsARRAY, reelsARRAY+ARRSIZE(reelsARRAY) );
        RollingLetters theObject;
        eq(1, theObject.getTime(reels, "AB"),-1L);
    }
    {
        string reelsARRAY[] = {"ABC"};
        vector <string> reels( reelsARRAY, reelsARRAY+ARRSIZE(reelsARRAY) );
        RollingLetters theObject;
        eq(2, theObject.getTime(reels, "X"),-1L);
    }
    {
        string reelsARRAY[] = {"CPKHFQEYXVMODNRTSGUBLJ", "TJLSURVHFQPAXGCEI", "JXNSGADPEWICKLFMVOQ", "UOFVKGQIJRECMWXADTPNL",
           "OREWASJFLY", "HBEC", "ESDRVXCNQUFWKGTOLH", "CPLTAMBHYSQDVJIORNW", "CG"};
        vector <string> reels( reelsARRAY, reelsARRAY+ARRSIZE(reelsARRAY) );
        RollingLetters theObject;
        eq(3, theObject.getTime(reels, "CAIIEHLQC"),4088392L);
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
