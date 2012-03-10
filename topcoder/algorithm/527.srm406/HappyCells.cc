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

struct HappyCells {
	vector <int> getHappy(vector <string> grid);
};

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};
const int dx[4] = {-1, -1, 1, 1};
const int dy[4] = {-1, 1, -1, 1};

vector <int> HappyCells::getHappy(vector <string> grid) {
	int r = grid.size();
	int c = grid[0].size();
	vector<int> ret(3, 0);
	FOR (i, r) {
		FOR (j, c) {
			if (grid[i][j] != '.') {
				continue;
			}
			int f = 0;
			FOR (k, 4) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (0 <= x && x < r && 0 <= y && y < c && grid[x][y] == '.') {
					f |= 1;
				}
			}
			FOR (k, 4) {
				int x = i + di[k];
				int y = j + dj[k];
				if (0 <= x && x < r && 0 <= y && y < c && grid[x][y] == '.') {
					f |= 2;
				}
			}
			if (f < 3) {
				++ret[f];
			}
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
        string gridARRAY[] = {
           "XXX",
           "X.X",
           "XXX"
           };
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        int retrunValueARRAY[] = {1, 0, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HappyCells theObject;
        eq(0, theObject.getHappy(grid),retrunValue);
    }
    {
        string gridARRAY[] = {"."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        int retrunValueARRAY[] = {1, 0, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HappyCells theObject;
        eq(1, theObject.getHappy(grid),retrunValue);
    }
    {
        string gridARRAY[] = {
           "XXXXXX",
           "X.XXXX",
           "XXX.XX",
           "X..XXX",
           "XXXXXX"
           };
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        int retrunValueARRAY[] = {1, 1, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HappyCells theObject;
        eq(2, theObject.getHappy(grid),retrunValue);
    }
    {
        string gridARRAY[] = {"..."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        int retrunValueARRAY[] = {0, 0, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        HappyCells theObject;
        eq(3, theObject.getHappy(grid),retrunValue);
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
