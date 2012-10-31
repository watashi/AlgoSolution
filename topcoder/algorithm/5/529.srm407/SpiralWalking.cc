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

struct SpiralWalking {
	int totalPoints(vector <string> levelMap);
};

const int MAXN = 64;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int a[MAXN][MAXN];

int SpiralWalking::totalPoints(vector <string> levelMap) {
	int r = levelMap.size();
	int c = levelMap[0].length();
	FOR (i, r) FOR (j, c) a[i][j] = levelMap[i][j] - '0';
	int x = 0, y = 0, z = 0, ret = 0;
	FOR (t, r * c - 1) {
		FOR (k, 4) {
			int xx = x + dx[(z + k) & 3];
			int yy = y + dy[(z + k) & 3];
			if (0 <= xx && xx < r && 0 <= yy && yy < c && a[xx][yy] != -1) {
				if (k == 0) {
					ret += a[x][y];
				}
				z = (z + k) & 3;
				break;
			}
		}
		a[x][y] = -1;
		x += dx[z];
		y += dy[z];
	}
	return ret + a[x][y];
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
        string levelMapARRAY[] = {"111",
            "111",
            "111"};
        vector <string> levelMap( levelMapARRAY, levelMapARRAY+ARRSIZE(levelMapARRAY) );
        SpiralWalking theObject;
        eq(0, theObject.totalPoints(levelMap),5);
    }
    {
        string levelMapARRAY[] = {"101",
            "110"};
        vector <string> levelMap( levelMapARRAY, levelMapARRAY+ARRSIZE(levelMapARRAY) );
        SpiralWalking theObject;
        eq(1, theObject.totalPoints(levelMap),3);
    }
    {
        string levelMapARRAY[] = {"00",
            "10"};
        vector <string> levelMap( levelMapARRAY, levelMapARRAY+ARRSIZE(levelMapARRAY) );
        SpiralWalking theObject;
        eq(2, theObject.totalPoints(levelMap),1);
    }
    {
        string levelMapARRAY[] = {"86850",
            "76439",
            "15863",
            "24568",
            "45679",
            "71452",
            "05483"};
        vector <string> levelMap( levelMapARRAY, levelMapARRAY+ARRSIZE(levelMapARRAY) );
        SpiralWalking theObject;
        eq(3, theObject.totalPoints(levelMap),142);
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
