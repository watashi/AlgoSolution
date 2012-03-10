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

struct SubFibonacci {
	int maxElements(vector <int> S);
};


const llint INF = 1000000007LL;
typedef pair<llint, llint> PLL;
vector<PLL> fib;

PLL operator+(const PLL& lhs, const PLL& rhs) {
	return PLL(lhs.first + rhs.first, lhs.second + rhs.second);
}

void init() {
	fib.clear();
	fib.push_back(PLL(1, 0));
	fib.push_back(PLL(0, 1));
	for (int i = 2; ; ++i) {
		fib.push_back(fib[i - 1] + fib[i - 2]);
	//	printf("<%lld, %lld>\n", fib[i].first, fib[i].second);
		if (fib[i].first > INF && fib[i].second > INF) {
			break;
		}
	}
	// printf("sizeof(fib) = %d\n", fib.size());
}

int gao(int n, set<long long> s, int m) {
	int ret = m;
	if (n > 0 && !s.empty()) {
		long long a = *s.begin();
		for (long long c = a; s.upper_bound(c) != s.end(); ) {
			c = *s.upper_bound(c);
			for (int i = 1; i < (int)fib.size() && fib[i].first * a < c; ++i) {
				if ((c - fib[i].first * a) % fib[i].second == 0) {
					long long b = (c - fib[i].first * a) / fib[i].second;
				//	printf("%lld %lld => %lld\n", a, b, c);
					set<long long> t = s;
					for (int j = 0; j < (int)fib.size(); ++j) {
						t.erase(fib[j].first * a + fib[j].second * b);
					}
				//	printf("diff = %d\n", s.size() - t.size());
					ret = max(ret, gao(n - 1, t, m + (int)(s.size() - t.size())));
				}
			}
		}
		s.erase(a);
		ret = max(ret, gao(n, s, m));
		ret = max(ret, gao(n - 1, s, m + 1));
	}
	return ret;
}

int SubFibonacci::maxElements(vector <int> S) {
	init();
	sort(S.begin(), S.end());
	int ret = 0;
	for (int i = 0; i <= (int)S.size(); ++i) {
		set<long long> a(S.begin(), S.begin() + i);
		set<long long> b(S.begin() + i, S.end());
		ret = max(ret, gao(1, a, 0) + gao(1, b, 0));
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
        int SARRAY[] = {8, 1, 20, 3, 10};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        SubFibonacci theObject;
        eq(0, theObject.maxElements(S),5);
    }
    {
        int SARRAY[] = {19, 47, 50, 58, 77, 99};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        SubFibonacci theObject;
        eq(1, theObject.maxElements(S),4);
    }
    {
        int SARRAY[] = {512};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        SubFibonacci theObject;
        eq(2, theObject.maxElements(S),1);
    }
    {
        int SARRAY[] = {3, 5, 7, 10, 13, 15, 20, 90};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        SubFibonacci theObject;
        eq(3, theObject.maxElements(S),7);
    }
    {
        int SARRAY[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        SubFibonacci theObject;
        eq(4, theObject.maxElements(S),10);
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
