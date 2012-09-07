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

struct XorBoardDivTwo {
	int theMax(vector <string> board);
};

int XorBoardDivTwo::theMax(vector <string> board) {
    int r = board.size();
    int c = board[0].size();
    int y = 0;
    FOR (i, r) {
        FOR (j, c) {
            int x = 0;
            FOR (ii, r) {
                FOR (jj, c) {
                    if ((board[ii][jj] == '1') ^ (i == ii) ^ (j == jj)) {
                        ++x;
                    }
                }
            }
            y = max(x, y);
        }
    }
    return y;
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
        string boardARRAY[] = {"101",
            "010",
            "101"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        XorBoardDivTwo theObject;
        eq(0, theObject.theMax(board),9);
    }
    {
        string boardARRAY[] = {"111",
            "111",
            "111"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        XorBoardDivTwo theObject;
        eq(1, theObject.theMax(board),5);
    }
    {
        string boardARRAY[] = {"0101001",
            "1101011"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        XorBoardDivTwo theObject;
        eq(2, theObject.theMax(board),9);
    }
    {
        string boardARRAY[] = {"000",
            "001",
            "010",
            "011",
            "100",
            "101",
            "110",
            "111"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        XorBoardDivTwo theObject;
        eq(3, theObject.theMax(board),15);
    }
    {
        string boardARRAY[] = {"000000000000000000000000",
            "011111100111111001111110",
            "010000000100000001000000",
            "010000000100000001000000",
            "010000000100000001000000",
            "011111100111111001111110",
            "000000100000001000000010",
            "000000100000001000000010",
            "000000100000001000000010",
            "011111100111111001111110",
            "000000000000000000000000"}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        XorBoardDivTwo theObject;
        eq(4, theObject.theMax(board),105);
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

