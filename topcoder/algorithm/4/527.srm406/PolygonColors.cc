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

struct PolygonColors {
	int getWays(int N, vector <int> colors);
};

const int MAXN = 64;
const long long MOD = 100000007LL;
long long dp[MAXN][MAXN][2];

int n;
vector<int> c;

long long gao(int s, int t, bool r) {
	long long &ret = dp[s][t][r];
	if (ret == -1) {
		if (t - s <= 1) {
			ret = 1;
		} else if (r) {
			ret = (c[s] == c[t] ? 1 : 2) * gao(s, t, false);
		} else {
			ret = gao(s + 1, t, true);
			for (int i = s + 2; i < t; ++i) {
				if (c[s] != c[i]) {
					ret += gao(s, i, false) * gao(i, t, true);
				}
			}
		}
		ret %= MOD;
		errf("[%d][%d][%d] = %lld\n", s, t, r, ret);
	}
	return ret;
}

int PolygonColors::getWays(int N, vector <int> colors) {
	::n = N;
	::c = colors;
	FOR (i, n) {
		if (c[i] == c[(i + 1) % n]) {
			return 0;
		}
	}
	MEMSET(dp, -1);
	return (int)gao(0, n - 1, false);
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
        int colorsARRAY[] = {1, 2, 0};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        PolygonColors theObject;
        eq(0, theObject.getWays(3, colors),1);
    }
    {
        int colorsARRAY[] = {1, 2, 3, 0};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        PolygonColors theObject;
        eq(1, theObject.getWays(4, colors),3);
    }
    {
        int colorsARRAY[] = {0, 1, 1, 1, 1};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        PolygonColors theObject;
        eq(2, theObject.getWays(5, colors),0);
    }
    {
        int colorsARRAY[] = {0,1,2,6,4,5,6,7,1,9,10,11,12,13,14,10};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        PolygonColors theObject;
        eq(3, theObject.getWays(16, colors),96791474);
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
