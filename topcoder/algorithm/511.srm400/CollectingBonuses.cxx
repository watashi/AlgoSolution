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

struct CollectingBonuses {
	double expectedBuy(string n, string k);
};

const long double GAMMA = 0.577215664901532860606512090082402431042;
const long double ONE = 1.0;

long double mylog(long long x, long long y) {
	if (ONE * x / y < 1.001) {
		x -= y;
		long double t = ONE, s = 0;
		for (int i = 1; i < 10; ++i) {
			t *= ONE * x / y;
			s += (i % 2 != 0 ? ONE : -ONE) * t / i;
		}
		return s;
	} else {
		return logl(ONE * x / y);
	}
}

double CollectingBonuses::expectedBuy(string _n, string _k) {
	long long n = strtoll(_n.c_str(), NULL, 0);
	long long k = strtoll(_k.c_str(), NULL, 0);
	long double ret = 0;
	if (k < (1 << 20)) {
		for (int i = 0; i < k; ++i) {
			ret += ONE / (n - i);
		}
	} else if (n - k < (1 << 16)) {
		for (int i = n - k; i >= 1; --i) {
			ret += ONE / i;
		}
		ret = mylog(n, 1) + GAMMA + ONE / 2 / n - ONE / 12 / n / n - ret;
	} else {
		ret = mylog(n, (n - k));
		ret -= ONE * k / 2 / n / (n - k);
		ret += ONE * k * (n + n - k) / 12 / n / n / (n - k) / (n - k);
	}
	return ret * n;
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
        CollectingBonuses theObject;
        eq(0, theObject.expectedBuy("1", "1"),1.0);
    }
    {
        CollectingBonuses theObject;
        eq(1, theObject.expectedBuy("2", "1"),1.0);
    }
    {
        CollectingBonuses theObject;
        eq(2, theObject.expectedBuy("2", "2"),3.0);
    }
    {
        CollectingBonuses theObject;
        eq(3, theObject.expectedBuy("4", "3"),4.333333333333333);
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
