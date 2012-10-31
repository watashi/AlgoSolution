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

struct TheBrickTowerHardDivTwo {
	int find(int C, int K, int H);
};

long long MOD = 1234567891LL;
long long dp[50][10][4][4][4][4];

int diff(int a, int b, int c, int d) {
    int t[4] = {a, b, c, d};
    int ret = 0;
    FOR (i, 4) {
        FOR (j, i) {
            if ((i ^ j) != 3 && t[i] == t[j]) {
                ++ret;
            }
        }
    }
    return ret;
}

int TheBrickTowerHardDivTwo::find(int C, int K, int H) {
    long long ans = 0;
    MEMSET(dp, 0);
    FOR (h, H) {
        FOR (k, K + 1) {
            FOR (a, C) FOR (b, C) FOR (c, C) FOR (d, C) {
                if (h == 0 && k == diff(a, b, c, d)) {
                    dp[h][k][a][b][c][d] = 1;
                }
                ans = (ans + dp[h][k][a][b][c][d]) % MOD;
                FOR (aa, C) FOR (bb, C) FOR (cc, C) FOR (dd, C) {
                    int x = diff(aa, bb, cc, dd);
                    x += (a == aa ? 1 : 0) +
                         (b == bb ? 1 : 0) +
                         (c == cc ? 1 : 0) +
                         (d == dd ? 1 : 0);
                    if (k + x <= K) {
                        dp[h + 1][k + x][aa][bb][cc][dd] =
                            (dp[h + 1][k + x][aa][bb][cc][dd] + dp[h][k][a][b][c][d]) % MOD;
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
        TheBrickTowerHardDivTwo theObject;
        eq(0, theObject.find(2, 0, 2),4);
    }
    {
        TheBrickTowerHardDivTwo theObject;
        eq(1, theObject.find(1, 7, 19),1);
    }
    {
        TheBrickTowerHardDivTwo theObject;
        eq(2, theObject.find(2, 3, 1),14);
    }
    {
        TheBrickTowerHardDivTwo theObject;
        eq(3, theObject.find(4, 7, 47),1008981254);
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

