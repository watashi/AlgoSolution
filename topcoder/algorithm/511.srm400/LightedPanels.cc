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

struct LightedPanels {
	int minTouch(vector <string> board);
};

const int MAXN = 10;
const int INF = 10000;

int a[MAXN], b[MAXN];
int c[1 << MAXN];

int LightedPanels::minTouch(vector <string> board) {
	int n = board.size(), m = board[0].size(), mask = (1 << m) - 1;
	fill(c, c + (1 << m), INF);
	FOR(i, 1 << m) {
		int j = ((i << 1) ^ i ^ (i >> 1)) & mask;
		c[j] = min(c[j], __builtin_popcount(i));
	}
	FOR(i, n) {
		a[i] = 0;
		FOR(j, m) {
			if (board[i][j] == '.') {
				a[i] ^= 1 << j;
			}
		}
	}

	int ans = INF, tmp;
	FOR(i, 1 << m) {
		tmp = 0;
		b[0] = i;
		copy(a, a + n, b + 1);
		FOR(j, n) {
			tmp += c[b[j]];
			b[j + 1] ^= b[j];
			b[j + 2] ^= b[j];
		}
		if (b[n] == 0) {
			ans = min(ans, tmp);
		}
	}
	return ans < INF ? ans : -1;
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
        string boardARRAY[] = {"*****",
            "*...*",
            "*...*",
            "*...*",
            "*****"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LightedPanels theObject;
        eq(0, theObject.minTouch(board),1);
    }
    {
        string boardARRAY[] = {".*"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LightedPanels theObject;
        eq(1, theObject.minTouch(board),-1);
    }
    {
        string boardARRAY[] = {"**.",
            "**.",
            "..."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LightedPanels theObject;
        eq(2, theObject.minTouch(board),2);
    }
    {
        string boardARRAY[] = {"*...",
            "**..",
            "..**",
            "...*"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LightedPanels theObject;
        eq(3, theObject.minTouch(board),10);
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
