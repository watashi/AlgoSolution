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

struct GetToTheTop {
	int collectSweets(int K, vector <int> sweets, vector <int> x, vector <int> y, vector <int> stairLength);
};

const int MAXN = 64;

int n, m;
vector<int> sweets;
int id[MAXN], sw[MAXN], dp[MAXN];
bool e[MAXN][MAXN], f[MAXN][MAXN], g[MAXN][MAXN];

inline int sqr(int x) {
	return x * x;
}

inline int dist(int x1, int y1, int z1, int x2, int y2, int z2) {
	int ret = sqr(y2 - y1);
	z1 += x1;
	z2 += x2;	
	if (z1 < x2) {
		return sqr(x2 - z1) + ret;
	} else if (z2 < x1) {
		return sqr(x1 - z2) + ret;
	} else {
		return ret;
	}
}

int dfs(int v, int tag) {
	int ret = sweets[v];
	id[v] = tag;
	FOR (i, n) {
		if (f[v][i] && id[i] == -1) {
			ret += dfs(i, tag);
		}
	}
	return ret;
}

int gao(int v) {
	if (dp[v] == -1) {
		dp[v] = 0;
		FOR (i, m) {
			if (g[v][i]) {
				dp[v] = max(dp[v], gao(i));
			}
		}
		dp[v] += sw[v];
	}
	return dp[v];
}

int GetToTheTop::collectSweets(int K, vector <int> sweets, vector <int> x, vector <int> y, vector <int> z) {
	n = sweets.size();
	::sweets = sweets;
	K *= K;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			e[i][j] = f[i][j] = false;
			if (dist(x[i], y[i], z[i], x[j], y[j], z[j]) <= K) {
				if (y[i] < y[j]) {
					e[i][j] = true;
				} else if (y[i] == y[j]) {
					f[i][j] = true;
				}
			}
		}
	}

	m = 0;
	fill(id, id + n, -1);
	for (int i = 0; i < n; ++i) {
		if (id[i] == -1) {
			sw[m] = dfs(i, m);
			++m;
		}
	}
	MEMSET(g, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (e[i][j]) {
				g[id[i]][id[j]] = true;
			}
		}
	}
	
	int ret = 0;
	fill(dp, dp + m, -1);
	for (int i = 0; i < n; ++i) {
		if (sqr(y[i]) <= K) {
			ret = max(ret, gao(id[i]));
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
        int sweetsARRAY[] = {1, 2, 3, 4, 3, 5};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        int xARRAY[] = {1, 1, 1, 4, 5, 5};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 3, 4, 1, 2, 3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int stairLengthARRAY[] = {2, 1, 1, 2, 1, 1};
        vector <int> stairLength( stairLengthARRAY, stairLengthARRAY+ARRSIZE(stairLengthARRAY) );
        GetToTheTop theObject;
        eq(0, theObject.collectSweets(2, sweets, x, y, stairLength),13);
    }
    {
        int sweetsARRAY[] = {2, 8, 7, 4, 1, 4, 7, 5, 11, 4};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        int xARRAY[] = {2, 9, 4, 6, 10, 5, 2, 8, 1, 10};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 1, 3, 3, 3, 5, 6, 6, 8, 9};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int stairLengthARRAY[] = {2, 2, 1, 2, 2, 2, 4, 3, 2, 2};
        vector <int> stairLength( stairLengthARRAY, stairLengthARRAY+ARRSIZE(stairLengthARRAY) );
        GetToTheTop theObject;
        eq(1, theObject.collectSweets(4, sweets, x, y, stairLength),47);
    }
    {
        int sweetsARRAY[] = {1, 3, 5, 7};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        int xARRAY[] = {1, 6, 2, 8};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2, 4, 1, 2};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int stairLengthARRAY[] = {4, 1, 7, 4};
        vector <int> stairLength( stairLengthARRAY, stairLengthARRAY+ARRSIZE(stairLengthARRAY) );
        GetToTheTop theObject;
        eq(2, theObject.collectSweets(10, sweets, x, y, stairLength),16);
    }
    {
        int sweetsARRAY[] = {80, 20, 15, 13, 10, 7, 8, 9, 1, 4, 3, 15, 14, 19, 22, 12, 6, 15, 10, 30, 1, 1};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        int xARRAY[] = {2, 8, 11, 17, 20, 14, 10, 16, 8, 14, 19, 6, 6, 6, 6, 15, 15, 15, 14, 20, 20, 20};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 2, 3, 2, 1, 4, 6, 7, 8, 8, 8, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int stairLengthARRAY[] = {2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector <int> stairLength( stairLengthARRAY, stairLengthARRAY+ARRSIZE(stairLengthARRAY) );
        GetToTheTop theObject;
        eq(3, theObject.collectSweets(3, sweets, x, y, stairLength),129);
    }
    {
        int sweetsARRAY[] = {0, 10, 11, 2, 0};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        int xARRAY[] = {1, 26, 29, 22, 3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 83, 88, 22, 5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int stairLengthARRAY[] = {11, 1, 23, 15, 8};
        vector <int> stairLength( stairLengthARRAY, stairLengthARRAY+ARRSIZE(stairLengthARRAY) );
        GetToTheTop theObject;
        eq(4, theObject.collectSweets(10, sweets, x, y, stairLength),0);
    }
    {
        int sweetsARRAY[] = {2, 0, 5};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        int xARRAY[] = {1, 8, 9};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {6, 6, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int stairLengthARRAY[] = {3, 6, 3};
        vector <int> stairLength( stairLengthARRAY, stairLengthARRAY+ARRSIZE(stairLengthARRAY) );
        GetToTheTop theObject;
        eq(5, theObject.collectSweets(5, sweets, x, y, stairLength),7);
    }
    {
        int sweetsARRAY[] = {2, 9, 9, 1, 9, 9, 8};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        int xARRAY[] = {10, 8, 6, 6, 8, 7, 3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {6, 7, 5, 4, 5, 2, 5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int stairLengthARRAY[] = {1, 1, 1, 1, 1, 1, 1};
        vector <int> stairLength( stairLengthARRAY, stairLengthARRAY+ARRSIZE(stairLengthARRAY) );
        GetToTheTop theObject;
        eq(6, theObject.collectSweets(2, sweets, x, y, stairLength),47);
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
