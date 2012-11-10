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

struct FlipGame {
	int minOperations(vector <string> board);
};

int pp(const string& s) {
    int ret = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '1') {
            ret = i + 1;
        }
    }
    return ret;
}

int FlipGame::minOperations(vector <string> a) {
    int r = a.size(), c = a[0].size();
    int ans = 0;
    while (true) {
        int k = 0;
        FOR (i, r) {
            k = max(k, pp(a[i]));
            FOR (j, k) {
                a[i][j] ^= 1;
            }
        }
        if (k > 0) {
            ++ans;
        } else {
            break;
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
        string boardARRAY[] = {"1000",
            "1110",
            "1111"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FlipGame theObject;
        eq(0, theObject.minOperations(board),1);
    }
    {
        string boardARRAY[] = {"1111",
            "1111",
            "1111"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FlipGame theObject;
        eq(1, theObject.minOperations(board),1);
    }
    {
        string boardARRAY[] = {"00",
            "00",
            "00"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FlipGame theObject;
        eq(2, theObject.minOperations(board),0);
    }
    {
        string boardARRAY[] = {"00000000",
            "00100000",
            "01000000",
            "00001000",
            "00000000"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FlipGame theObject;
        eq(3, theObject.minOperations(board),4);
    }
    {
        string boardARRAY[] = {"000000000000001100000000000000",
            "000000000000011110000000000000",
            "000000000000111111000000000000",
            "000000000001111111100000000000",
            "000000000011111111110000000000",
            "000000000111111111111000000000",
            "000000001100111111001100000000",
            "000000011000011110000110000000",
            "000000111100111111001111000000",
            "000001111111111111111111100000",
            "000011111111111111111111110000",
            "000111111111000000111111111000",
            "001111111111100001111111111100",
            "011111111111110011111111111110",
            "111111111111111111111111111111"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FlipGame theObject;
        eq(4, theObject.minOperations(board),29);
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

