#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
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

struct CuttingBitString {
	int getmin(string S);
};

const int INF = 1000000007;

int CuttingBitString::getmin(string S) {
    vector<string> v;
    for (long long i = 1; i < 1LL << 60; i *= 5) {
        string t = "";
        for (long long j = i; j > 0; j >>= 1) {
            t += (char)('0' + j % 2);
        }
        reverse(t.begin(), t.end());
        // puts(t.c_str());
        // printf("%d\n", t.length());
        v.push_back(t);
    }
    vector<int> dp(S.length() + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < (int)S.length(); ++i) {
        for (int j = 0; j < (int)v.size(); ++j) {
            if (S.substr(i, v[j].length()) == v[j]) {
                dp[i + v[j].length()] = min(dp[i + v[j].length()], dp[i] + 1);
            }
        }
    }
    return dp[S.length()] == INF ? -1 : dp[S.length()];
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
        CuttingBitString theObject;
        eq(0, theObject.getmin("101101101"),3);
    }
    {
        CuttingBitString theObject;
        eq(1, theObject.getmin("1111101"),1);
    }
    {
        CuttingBitString theObject;
        eq(2, theObject.getmin("00000"),-1);
    }
    {
        CuttingBitString theObject;
        eq(3, theObject.getmin("110011011"),3);
    }
    {
        CuttingBitString theObject;
        eq(4, theObject.getmin("1000101011"),-1);
    }
    {
        CuttingBitString theObject;
        eq(5, theObject.getmin("111011100110101100101110111"),5);
    }

	puts("\033[1;33mPress any key to continue...\033[0m");
	getchar();

	return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE

