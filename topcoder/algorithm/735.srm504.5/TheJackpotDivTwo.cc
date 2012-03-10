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

struct TheJackpotDivTwo {
	vector <int> find(vector <int> money, int jackpot);
};

vector <int> TheJackpotDivTwo::find(vector <int> a, int b) {
	int n = a.size();
	sort(a.begin(), a.end());
	for (int i = 1; i <= n; ++i) {
		int c = min(b / i, i == n ? b / i : a[i] - a[i - 1]);
		for (int j = 0; j < i; ++j) {
			a[j] += c;
		}
		b -= i * c;
	}
	for (int i = 0; i < b; ++i) {
		++a[i];
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
        int moneyARRAY[] = {1, 2, 3, 4};
        vector <int> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        int retrunValueARRAY[] = {2, 3, 3, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivTwo theObject;
        eq(0, theObject.find(money, 2),retrunValue);
    }
    {
        int moneyARRAY[] = {4, 7};
        vector <int> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        int retrunValueARRAY[] = {5, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivTwo theObject;
        eq(1, theObject.find(money, 1),retrunValue);
    }
    {
        int moneyARRAY[] = {1};
        vector <int> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        int retrunValueARRAY[] = {101 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivTwo theObject;
        eq(2, theObject.find(money, 100),retrunValue);
    }
    {
        int moneyARRAY[] = {21, 85, 6, 54, 70, 100, 91, 60, 71};
        vector <int> money( moneyARRAY, moneyARRAY+ARRSIZE(moneyARRAY) );
        int retrunValueARRAY[] = {21, 21, 54, 60, 70, 71, 85, 91, 100 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheJackpotDivTwo theObject;
        eq(3, theObject.find(money, 15),retrunValue);
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
