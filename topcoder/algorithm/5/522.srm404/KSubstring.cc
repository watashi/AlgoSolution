#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <limits>
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

struct KSubstring {
	vector <int> maxSubstring(int A0, int X, int Y, int M, int n);
};

const int MAXN = 32768;
const long long INF = 12345678987654321LL;
long long a[MAXN], s[MAXN];

vector <int> KSubstring::maxSubstring(int A0, int X, int Y, int M, int n) {
	a[0] = A0;
	for (int i = 1; i < n; ++i) {
		a[i] = (a[i - 1] * X + Y) % M;
	}
	s[0] = 0;
	partial_sum(a, a + n, s + 1);
	
	vector<int> ret(2);
	ret[0] = numeric_limits<int>::max();
	ret[1] = -1;
	for (int k = 1; k + k <= n; ++k) {
		set<long long> st;
		st.insert(-INF);
		st.insert(INF);
		for (int i = k + k; i <= n; ++i) {
			st.insert(s[i - k] - s[i - k - k]);
			set<long long>::const_iterator it = st.lower_bound(s[i] - s[i - k]);
			if (ret[0] >= *it - (s[i] - s[i - k])) {
				ret[0] = *it - (s[i] - s[i - k]);
				ret[1] = k;
			}
			--it;
			if (ret[0] >= (s[i] - s[i - k]) - *it) {
				ret[0] = (s[i] - s[i - k]) - *it;
				ret[1] = k;
			}
		}
	}
	swap(ret[0], ret[1]);
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
        int retrunValueARRAY[] = {2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KSubstring theObject;
        eq(0, theObject.maxSubstring(5, 3, 4, 25, 5),retrunValue);
    }
    {
        int retrunValueARRAY[] = {5, 161 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KSubstring theObject;
        eq(1, theObject.maxSubstring(8, 19, 17, 2093, 12),retrunValue);
    }
    {
        int retrunValueARRAY[] = {244, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KSubstring theObject;
        eq(2, theObject.maxSubstring(53, 13, 9, 65535, 500),retrunValue);
    }
    {
        int retrunValueARRAY[] = {35, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        KSubstring theObject;
        eq(3, theObject.maxSubstring(12, 34, 55, 7890, 123),retrunValue);
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
