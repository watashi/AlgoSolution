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

struct MuddyRoad2 {
	int theCount(int N, int muddyCount);
};

const int MAXN = 567;
const int MOD = 555555555;

int dp[MAXN][MAXN][2][2];

void inc(int& lhs, int rhs) {
    lhs += rhs;
    if (lhs >= MOD) {
        lhs -= MOD;
    }
}

int MuddyRoad2::theCount(int N, int muddyCount) {
    int ans = 0;
    MEMSET(dp, 0);
    dp[0][0][0][1] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= muddyCount; ++j) {
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    if (i == N - 1 && j == muddyCount && y == 0) {
                        inc(ans, dp[i][j][x][y]);
                    }
                    inc(dp[i + 1][j][y][(x + y) % 2], dp[i][j][x][y]);
                    if (i + 1 != N - 1) {
                        inc(dp[i + 1][j + 1][y][0], dp[i][j][x][y]);
                    }
                }
            }
        }
    }
    return ans;
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
        MuddyRoad2 theObject;
        eq(0, theObject.theCount(5, 1),2);
    }
    {
        MuddyRoad2 theObject;
        eq(1, theObject.theCount(5, 2),2);
    }
    {
        MuddyRoad2 theObject;
        eq(2, theObject.theCount(10, 4),65);
    }
    {
        MuddyRoad2 theObject;
        eq(3, theObject.theCount(314, 78),498142902);
    }
    {
        MuddyRoad2 theObject;
        eq(4, theObject.theCount(555, 222),541606281);
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

