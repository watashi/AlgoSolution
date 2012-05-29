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

struct AliceBobShuffle {
	int countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd);
};

const int MAXN = 128;
const llint MOD = 1000000007LL;

llint dp[MAXN][MAXN][MAXN];

void add(llint& s, llint a) {
    s += a;
    if (s >= MOD) {
        s -= MOD;
    }
}

int AliceBobShuffle::countWays(vector <int> a, vector <int> b, vector <int> x, vector <int> y) {
    int na = a.size(), nb = b.size(), nx = x.size(), ny = y.size();
    int n = na + nb;
    if (n != nx + ny) { // orz = =||
        return 0LL;
    }
    a.push_back(-1);
    b.push_back(-2);
    x.push_back(-3);
    y.push_back(-4);
    // reverse(ALL(x));
    // reverse(ALL(y));
    MEMSET(dp, 0);
    dp[0][0][0] = 1LL;
    FOR (i, n) {
        FOR (j, na + 1) {
            int jj = i - j;
            if (jj < 0 || jj > nb) {
                continue;
            }
            FOR (k, nx + 1) {
                int kk = i - k;
                if (kk < 0 || kk > ny) {
                    continue;
                }
                if (false && dp[i][j][k] > 0) {
                    printf("[%d][%d][%d] %lld\n", i, j, k, dp[i][j][k]);
                }
                if (a[j] == x[k]) {
                    add(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
                }
                if (a[j] == y[kk]) {
                    add(dp[i + 1][j + 1][k], dp[i][j][k]);
                }
                if (b[jj] == x[k]) {
                    add(dp[i + 1][j][k + 1], dp[i][j][k]);
                }
                if (b[jj] == y[kk]) {
                    add(dp[i + 1][j][k], dp[i][j][k]);
                }
            }
        }
    }
    llint ret = 0;
    FOR (j, n) {
        FOR (k, n) {
            ret += dp[n][j][k];
        }
    }
    return ret % MOD;
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
        int AliceStartARRAY[] = {1, 3};
        vector <int> AliceStart( AliceStartARRAY, AliceStartARRAY+ARRSIZE(AliceStartARRAY) );
        int BobStartARRAY[] = {2, 4};
        vector <int> BobStart( BobStartARRAY, BobStartARRAY+ARRSIZE(BobStartARRAY) );
        int AliceEndARRAY[] = {2, 3};
        vector <int> AliceEnd( AliceEndARRAY, AliceEndARRAY+ARRSIZE(AliceEndARRAY) );
        int BobEndARRAY[] = {1, 4};
        vector <int> BobEnd( BobEndARRAY, BobEndARRAY+ARRSIZE(BobEndARRAY) );
        AliceBobShuffle theObject;
        eq(0, theObject.countWays(AliceStart, BobStart, AliceEnd, BobEnd),4);
    }
    {
        int AliceStartARRAY[] = {1, 2, 1};
        vector <int> AliceStart( AliceStartARRAY, AliceStartARRAY+ARRSIZE(AliceStartARRAY) );
        int BobStartARRAY[] = {1, 2};
        vector <int> BobStart( BobStartARRAY, BobStartARRAY+ARRSIZE(BobStartARRAY) );
        int AliceEndARRAY[] = {1, 2, 1};
        vector <int> AliceEnd( AliceEndARRAY, AliceEndARRAY+ARRSIZE(AliceEndARRAY) );
        int BobEndARRAY[] = {2, 1};
        vector <int> BobEnd( BobEndARRAY, BobEndARRAY+ARRSIZE(BobEndARRAY) );
        AliceBobShuffle theObject;
        eq(1, theObject.countWays(AliceStart, BobStart, AliceEnd, BobEnd),4);
    }
    {
        int AliceStartARRAY[] = {1};
        vector <int> AliceStart( AliceStartARRAY, AliceStartARRAY+ARRSIZE(AliceStartARRAY) );
        int BobStartARRAY[] = {2};
        vector <int> BobStart( BobStartARRAY, BobStartARRAY+ARRSIZE(BobStartARRAY) );
        int AliceEndARRAY[] = {3};
        vector <int> AliceEnd( AliceEndARRAY, AliceEndARRAY+ARRSIZE(AliceEndARRAY) );
        int BobEndARRAY[] = {4};
        vector <int> BobEnd( BobEndARRAY, BobEndARRAY+ARRSIZE(BobEndARRAY) );
        AliceBobShuffle theObject;
        eq(2, theObject.countWays(AliceStart, BobStart, AliceEnd, BobEnd),0);
    }
    {
        int AliceStartARRAY[] = {1, 2};
        vector <int> AliceStart( AliceStartARRAY, AliceStartARRAY+ARRSIZE(AliceStartARRAY) );
        int BobStartARRAY[] = {3};
        vector <int> BobStart( BobStartARRAY, BobStartARRAY+ARRSIZE(BobStartARRAY) );
        int AliceEndARRAY[] = {3};
        vector <int> AliceEnd( AliceEndARRAY, AliceEndARRAY+ARRSIZE(AliceEndARRAY) );
        int BobEndARRAY[] = {2, 1};
        vector <int> BobEnd( BobEndARRAY, BobEndARRAY+ARRSIZE(BobEndARRAY) );
        AliceBobShuffle theObject;
        eq(3, theObject.countWays(AliceStart, BobStart, AliceEnd, BobEnd),0);
    }
    {
        int AliceStartARRAY[] = {3, 3, 2, 4, 1, 3, 1, 2, 1, 1, 5, 5, 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 2};
        vector <int> AliceStart( AliceStartARRAY, AliceStartARRAY+ARRSIZE(AliceStartARRAY) );
        int BobStartARRAY[] = {4, 1, 4, 3, 4, 4, 4, 3, 2, 1, 6, 2, 2, 3, 2, 2, 1, 3, 2, 3};
        vector <int> BobStart( BobStartARRAY, BobStartARRAY+ARRSIZE(BobStartARRAY) );
        int AliceEndARRAY[] = {4, 1, 4, 3, 4, 4, 4, 1, 3, 1, 2, 2, 2, 3, 2, 1, 2, 1, 2, 2, 2};
        vector <int> AliceEnd( AliceEndARRAY, AliceEndARRAY+ARRSIZE(AliceEndARRAY) );
        int BobEndARRAY[] = {3, 3, 2, 3, 4, 2, 1, 2, 1, 1, 5, 6, 5, 1, 3, 1, 2, 3, 1, 1, 1, 3};
        vector <int> BobEnd( BobEndARRAY, BobEndARRAY+ARRSIZE(BobEndARRAY) );
        AliceBobShuffle theObject;
        eq(4, theObject.countWays(AliceStart, BobStart, AliceEnd, BobEnd),314159265);
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

