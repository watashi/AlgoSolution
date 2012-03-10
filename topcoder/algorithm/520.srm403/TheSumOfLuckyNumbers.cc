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

struct TheSumOfLuckyNumbers {
	vector <int> sum(int n);
};

const int MAXN = 1 << 20;

bool inited = false;
vector<int> lucky;
int dp[MAXN];
int pre[MAXN];

void gao(int n) {
	if (n < MAXN) {
		lucky.push_back(n);
		gao(n * 10 + 4);
		gao(n * 10 + 7);
	}
}

void init() {
	if (inited) {
		return;
	}
	inited = true;
	gao(0);
	sort(lucky.begin(), lucky.end());
	dp[0] = 0;
	for (int i = 1; i < MAXN; ++i) {
		dp[i] = MAXN;
		for (vector<int>::const_iterator j = lucky.begin(); j != lucky.end() && *j <= i; ++j) {
			if (dp[i - *j] + 1 < dp[i]) {
				dp[i] = dp[i - *j] + 1;
				pre[i] = *j;
			}
		}
	}
}

vector <int> TheSumOfLuckyNumbers::sum(int n) {
	vector<int> ret;
	init();	
	if (dp[n] != MAXN) {
		while (n > 0) {
			ret.push_back(pre[n]);
			n -= pre[n];
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
        int retrunValueARRAY[] = {4, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheSumOfLuckyNumbers theObject;
        eq(0, theObject.sum(11),retrunValue);
    }
    {
        int retrunValueARRAY[] = {4, 4, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheSumOfLuckyNumbers theObject;
        eq(1, theObject.sum(12),retrunValue);
    }
    {
        TheSumOfLuckyNumbers theObject;
        eq(2, theObject.sum(13),vector <int>());
    }
    {
        int retrunValueARRAY[] = {4, 4, 4, 44, 44 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheSumOfLuckyNumbers theObject;
        eq(3, theObject.sum(100),retrunValue);
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
