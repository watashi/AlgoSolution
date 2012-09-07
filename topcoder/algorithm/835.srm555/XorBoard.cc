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

const int MAXN = 1600;
const long long MOD = 555555555LL;

long long c[MAXN][MAXN];
long long dp[MAXN][MAXN];

void init() {
    MEMSET(c, 0);
    for (int i = 0; i < MAXN; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) {
                c[i][j] -= MOD;
            }
        }
    }
    MEMSET(dp, 0);
    dp[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 2; j < MAXN; j += 2) {
            dp[i][j] = dp[i][j - 2] + dp[i - 1][j];
            if (dp[i][j] >= MOD) {
                dp[i][j] -= MOD;
            }
        }
    }
}

long long gao(int n, int m, int k) {
    return c[n][k] * dp[n][m - k] % MOD;
}

struct XorBoard {
	int count(int H, int W, int Rcount, int Ccount, int S);
};

int XorBoard::count(int H, int W, int Rcount, int Ccount, int S) {
    init();
    long long ans = 0;
    for (int i = Rcount % 2; i <= Rcount && i <= H; i += 2) {
        for (int j = Ccount % 2; j <= Ccount && j <= W; j += 2) {
            int k = i * W + j * H - 2 * i * j;
            if (k == S) {
                // printf("%d %d\n", i, j);
                ans += gao(H, Rcount, i) * gao(W, Ccount, j) % MOD;
            }
        }
    }
    return ans % MOD;
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
        XorBoard theObject;
        eq(0, theObject.count(2, 2, 2, 2, 4),4);
    }
    {
        XorBoard theObject;
        eq(1, theObject.count(2, 2, 0, 0, 1),0);
    }
    {
        XorBoard theObject;
        eq(2, theObject.count(10, 20, 50, 40, 200),333759825);
    }
    {
        XorBoard theObject;
        eq(3, theObject.count(1200, 1000, 800, 600, 4000),96859710);
    }
    {
        XorBoard theObject;
        eq(4, theObject.count(555, 555, 555, 555, 5550),549361755);
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

