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

struct TheJackpotDivOne {
	vector<long long> find(vector<long long> money, long long jackpot);
};

vector<long long> TheJackpotDivOne::find(vector<long long> a, long long b) {
	int n = a.size();
	int m = 0;
	long long div = 0LL;
	long long mod = 0LL;
	FOREACH (i, a) {
		div += *i / n;
		mod += *i % n;
	}
	div += mod / n;
	mod %= n;
	while (b > 0) {
		vector<long long>::iterator it = min_element(a.begin(), a.end());
		if (*it == *max_element(a.begin(), a.end())) {
			break;
		}
		long long c = min(b, div + 1 - *it);
		*it += c;
		b -= c;
		mod += c;
		div += mod / n;
		mod %= n;
		++m;
	}
	printf("m = %d\n", m);
	if (b > 0) {
		FOREACH (i, a) {
			*i += b / n;
		}
		FOR (i, b % n) {
			++a[i];
		}
	}
	sort(a.begin(), a.end());
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
        long moneyARRAY[] = {1L, 2L, 3L, 4L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {2L, 3L, 3L, 4L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(0, theObject.find(money, 2L),retrunValue);
    }
    {
        long moneyARRAY[] = {4L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {11L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(1, theObject.find(money, 7L),retrunValue);
    }
    {
        long moneyARRAY[] = {4L, 44L, 7L, 77L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {24L, 34L, 44L, 77L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(2, theObject.find(money, 47L),retrunValue);
    }
    {
        long moneyARRAY[] = {4L, 10L, 8L, 3L, 6L, 5L, 8L, 3L, 7L, 5L};
        vector<long long> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        long retrunValueARRAY[] = {105L, 106L, 106L, 106L, 106L, 106L, 106L, 106L, 106L, 106L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivOne theObject;
        eq(3, theObject.find(money, 1000L),retrunValue);
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
