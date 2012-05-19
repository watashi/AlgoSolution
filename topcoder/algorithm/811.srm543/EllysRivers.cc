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

struct EllysRivers {
	double getMin(int length, int walk, vector <int> width, vector <int> speed);
};

const double INF = 1e100;

double EllysRivers::getMin(int length, int walk, vector <int> width, vector <int> speed) {
    int n = length + 1;
    int m = width.size();
    vector<double> cur(n, INF);
    cur[0] = 0.0;
    for (int i = 0; i < m; ++i) {
        vector<double> pre(n, INF);
        cur.swap(pre);
        for (int j = 0, k = 0; j < n; ++j) {
            cur[j] = pre[k] + hypot(width[i], abs(j - k)) / speed[i];
            while (k + 1 < n) {
                int kk = k + 1;
                double tmp = pre[kk] + hypot(width[i], abs(j - kk)) / speed[i];
                if (cur[j] > tmp) {
                    cur[j] = tmp;
                    ++k;
                } else {
                    break;
                }
            }
        }
    }
    double ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, cur[i] + abs(length - i) / (double)walk);
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
        int widthARRAY[] = {5, 2, 3};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {5, 2, 7};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(0, theObject.getMin(10, 3, width, speed),3.231651964071508);
    }
    {
        int widthARRAY[] = {911};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {207};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(1, theObject.getMin(10000, 211, width, speed),48.24623664712219);
    }
    {
        int widthARRAY[] = {100, 200, 300, 400};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {11, 12, 13, 14};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(2, theObject.getMin(1337, 2, width, speed),128.57830549575695);
    }
    {
        int widthARRAY[] = {11, 12, 13, 14};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {100, 200, 300, 400};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(3, theObject.getMin(77, 119, width, speed),0.3842077071089629);
    }
    {
        int widthARRAY[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
        vector <int> width( widthARRAY, widthARRAY+ARRSIZE(widthARRAY) );
        int speedARRAY[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
        vector <int> speed( speedARRAY, speedARRAY+ARRSIZE(speedARRAY) );
        EllysRivers theObject;
        eq(4, theObject.getMin(7134, 1525, width, speed),214.6509731258811);
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

