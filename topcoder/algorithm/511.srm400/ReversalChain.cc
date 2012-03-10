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

struct ReversalChain {
	int minReversal(string init, string goal);
};

const int MAXN = 52;
const int INF = 1000000007;

int n;
int dp[MAXN][MAXN][MAXN][MAXN][2];
string init, goal;

int gao(int a, int b, int c, int d, int e) {
	int &ret = dp[a][b][c][d][e];
	if (ret != -1) {
	} else if (a == b) {
		ret = init[a] == goal[c] ? 0 : INF;
	} else {
		ret = INF;
		if (init[a] == goal[c]) {
			ret = min(ret, gao(a + 1, b, c + 1, d, 0) + (e == 0 ? 0 : 1));
		}
		if (init[b] == goal[d]) {
			ret = min(ret, gao(a, b - 1, c, d - 1, 0) + (e == 0 ? 0 : 1));
		}
		if (init[a] == goal[d]) {
			ret = min(ret, gao(a + 1, b, c, d - 1, 1) + (e == 1 ? 0 : 1));
		}
		if (init[b] == goal[c]) {
			ret = min(ret, gao(a, b - 1, c + 1, d, 1) + (e == 1 ? 0 : 1));
		}
	}
	return ret;
}

int ReversalChain::minReversal(string init, string goal) {
	n = init.size();
	::init = init;
	::goal = goal;
	memset(dp, 0xff, sizeof(dp));
	int ans = gao(0, n - 1, 0, n - 1, 0);
	return ans < INF / 2 ? ans : -1;
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
        ReversalChain theObject;
        eq(0, theObject.minReversal("1100", "0110"),1);
    }
    {
        ReversalChain theObject;
        eq(1, theObject.minReversal("111000", "101010"),2);
    }
    {
        ReversalChain theObject;
        eq(2, theObject.minReversal("0", "1"),-1);
    }
    {
        ReversalChain theObject;
        eq(3, theObject.minReversal("10101", "10101"),0);
    }
    {
        ReversalChain theObject;
        eq(4, theObject.minReversal("111000111000", "001100110011"),4);
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
