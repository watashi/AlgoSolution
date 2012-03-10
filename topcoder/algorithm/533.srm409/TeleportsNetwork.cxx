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

struct TeleportsNetwork {
	int distribute(int teleportCount, vector <int> citiesX, vector <int> citiesY);
};

const int MAXN = 100;
const int INF = 1000000007;	// !!
vector<int> e[MAXN];

inline llint sqr(llint x) {
	return x * x;
}

int gao(int v, int d, int& c) {
	int ret = -INF;
	if (e[v].empty()) {
		ret = 0;
	} else {
		// WA12
		vector<int> tmp;
		FOREACH (w, e[v]) {
			tmp.push_back(gao(*w, d, c));
		}
		int a = *min_element(ALL(tmp));
		int b = *max_element(ALL(tmp));
		if (a + b <= -3) {
			ret = a + 1;
		} else {
			ret = b + 1;
		}
	}
	if (ret == d) {
		ret = -d - 1;
		++c;
	}
	return ret;
}

int TeleportsNetwork::distribute(int teleportCount, vector <int> citiesX, vector <int> citiesY) {
	int n = citiesX.size();
	fill(e, e + n, vector<int>());
	for (int i = 1; i < n; ++i) {
		int k = -1;
		llint dk = sqr(INF);	// ** RE7
		llint d = sqr(citiesX[i] - citiesX[0]) + sqr(citiesY[i] - citiesY[0]);
		for (int j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}
			llint d0 = sqr(citiesX[j] - citiesX[0]) + sqr(citiesY[j] - citiesY[0]);
			if (d0 >= d) {
				continue;
			}
			llint di = sqr(citiesX[j] - citiesX[i]) + sqr(citiesY[j] - citiesY[i]);
			if (di < dk
					|| (di == dk && citiesX[j] < citiesX[k])
					|| (di == dk && citiesX[j] == citiesX[k] && citiesY[j] < citiesY[k])) {
				k = j;
				dk = di;
			}
		}
		e[k].push_back(i);
	//	errf("%d => %d\n", i, k);
	}

	int l = 0, r = n;

	while (l < r) {
		int m = (l + r) / 2;
		int c = 0;
		if (gao(0, m, c) == -m - 1) {
			--c;
		}
		if (c > teleportCount) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	return r;
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
        int citiesXARRAY[] = {0,1,1,1,2,2};
        vector <int> citiesX( citiesXARRAY, citiesXARRAY+ARRSIZE(citiesXARRAY) );
        int citiesYARRAY[] = {1,0,1,2,0,2};
        vector <int> citiesY( citiesYARRAY, citiesYARRAY+ARRSIZE(citiesYARRAY) );
        TeleportsNetwork theObject;
        eq(0, theObject.distribute(2, citiesX, citiesY),1);
    }
    {
        int citiesXARRAY[] = {0,1,1,1,2,2};
        vector <int> citiesX( citiesXARRAY, citiesXARRAY+ARRSIZE(citiesXARRAY) );
        int citiesYARRAY[] = {1,0,1,2,0,2};
        vector <int> citiesY( citiesYARRAY, citiesYARRAY+ARRSIZE(citiesYARRAY) );
        TeleportsNetwork theObject;
        eq(1, theObject.distribute(1, citiesX, citiesY),2);
    }
    {
        int citiesXARRAY[] = {0,1,1,1,2,3,3,4};
        vector <int> citiesX( citiesXARRAY, citiesXARRAY+ARRSIZE(citiesXARRAY) );
        int citiesYARRAY[] = {1,1,2,0,0,0,2,1};
        vector <int> citiesY( citiesYARRAY, citiesYARRAY+ARRSIZE(citiesYARRAY) );
        TeleportsNetwork theObject;
        eq(2, theObject.distribute(0, citiesX, citiesY),5);
    }
    {
        int citiesXARRAY[] = {0,1,2,3,4};
        vector <int> citiesX( citiesXARRAY, citiesXARRAY+ARRSIZE(citiesXARRAY) );
        int citiesYARRAY[] = {0,0,0,0,0};
        vector <int> citiesY( citiesYARRAY, citiesYARRAY+ARRSIZE(citiesYARRAY) );
        TeleportsNetwork theObject;
        eq(3, theObject.distribute(1, citiesX, citiesY),1);
    }
    {
        int citiesXARRAY[] = {64,200,384,294,175,107,303,374,224,220,223,99,442};
        vector <int> citiesX( citiesXARRAY, citiesXARRAY+ARRSIZE(citiesXARRAY) );
        int citiesYARRAY[] = {79,161,83,281,344,217,184,336,431,262,75,474,257};
        vector <int> citiesY( citiesYARRAY, citiesYARRAY+ARRSIZE(citiesYARRAY) );
        TeleportsNetwork theObject;
        eq(4, theObject.distribute(4, citiesX, citiesY),1);
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

/*
Problem: 1000
Test Case: 12
Succeeded: No
Execution Time: 1 ms
Args:
{4, {246, 66, 385, 14, 110, 318, 437, 316, 107, 38, 146, 239, 385, 328, 436, 188, 15, 9, 68, 34, 102, 8, 94, 175, 260, 377, 350, 413, 440, 428, 454, 339, 320, 358, 140, 204, 318, 287, 303, 233, 181, 114, 194, 249, 307, 400, 431, 448, 79, 151}, {16, 53, 42, 92, 86, 104, 94, 193, 169, 212, 216, 233, 247, 319, 317, 299, 259, 318, 330, 372, 368, 443, 440, 435, 359, 364, 410, 410, 220, 385, 375, 378, 399, 391, 467, 455, 48, 54, 24, 119, 57, 233, 193, 276, 255, 88, 75, 75, 427, 161}}

Expected:
4

Received:
5
*/
/// END CUT HERE
