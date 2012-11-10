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

const double EPS = 1e-8;
const int INF = 1000000007;

struct NCool {
	int nCoolPoints(vector <int> x, vector <int> y, int n);
};

int floor(int a, int b);
int ceil(int a, int b);

int floor(int a, int b) {
	return a >= 0 ? a / b : -ceil(-a, b);
}

int ceil(int a, int b) {
	return a >= 0 ? (a + b - 1) / b : -floor(-a, b);
}

// 353.41pt (1y)
int NCool::nCoolPoints(vector <int> x, vector <int> y, int n) {
	int s;
	vector<pair<int, int> > v;
	s = x.size();
	for (int i = 0; i < s; ++i) {
		v.push_back(make_pair(x[i], y[i]));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	s = v.size();

	double cx = 0, cy = 0;
	for (int i = 0; i < s; ++i) {
		cx += v[i].first;
		cy += v[i].second;
	}
	cx = cx / s + EPS;
	cy = cy / s + EPS;
	
	vector<pair<double, pair<int, int> > > w;
	for (int i = 0; i < s; ++i) {
		w.push_back(make_pair(atan2(v[i].second - cy, v[i].first - cx), v[i]));
	}
	sort(w.begin(), w.end());
	for (int i = 0; i < s; ++i) {
		v[i] = w[i].second;
	}
	v.push_back(v.front());

	int x1 = *min_element(x.begin(), x.end()), x2 = *max_element(x.begin(), x.end());
	map<pair<int, int>, int> mp;
	for (int xx = x1; xx <= x2; ++xx) {
		int y1 = -INF, y2 = INF;
		for (int i = 0; i < s; ++i) {
			if (v[i].first == xx && v[i + 1].first == xx) {
				y1 = max(y1, min(v[i].second, v[i + 1].second));
				y2 = min(y2, max(v[i].second, v[i + 1].second));
			} else if (v[i].first <= xx && xx <= v[i + 1].first) {
				y1 = max(y1, v[i].second + 
					ceil((v[i + 1].second - v[i].second) * (xx - v[i].first),
						v[i + 1].first - v[i].first));
			} else if (v[i + 1].first <= xx && xx <= v[i].first) {
				y2 = min(y2, v[i + 1].second +
					floor((v[i].second - v[i + 1].second) * (xx - v[i + 1].first),
						v[i].first - v[i + 1].first));
			}
		}
		for (int yy = y1; yy <= y2; ++yy) {
			++mp[make_pair(xx % (n - 1), yy % (n - 1))];
		}
	}

	int ans = 0;
	for (map<pair<int, int>, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
		if (it->second > 1) {
			ans += it->second;
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
        int xARRAY[] = {0, 1, 2, 7, 7};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {3, 1, 6, 1, 5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        NCool theObject;
        eq(0, theObject.nCoolPoints(x, y, 6),21);
    }
    {
        int xARRAY[] = {0, 1, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 0, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        NCool theObject;
        eq(1, theObject.nCoolPoints(x, y, 2),3);
    }
    {
        int xARRAY[] = {0, 0, 1, 2, 2, 1, 0, 0, 2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 1, 2, 2, 1, 0, 0, 0, 2};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        NCool theObject;
        eq(2, theObject.nCoolPoints(x, y, 3),6);
    }
    {
        int xARRAY[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 0, 2, 0, 2, 0, 2, 0, 2, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        NCool theObject;
        eq(3, theObject.nCoolPoints(x, y, 5),4);
    }
    {
        int xARRAY[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 0, 2, 0, 2, 0, 2, 0, 2, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        NCool theObject;
        eq(4, theObject.nCoolPoints(x, y, 4),10);
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
