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

struct CheapestRoute {
	vector <int> routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice);
};

const int MAXN = 100;
const int INF = 1000000007;

vector<PII> e[MAXN];
PII d[MAXN][MAXN];

PII operator+(const PII& lhs, const PII& rhs) {
	return PII(lhs.first + rhs.first, lhs.second + rhs.second);
}

vector <int> CheapestRoute::routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice) {
	int n = cellPrice.size();
	FOR (i, n) {
		e[i].clear();
	}
	FOR (i, n) {
		if (cellPrice[i] == -1) {
			continue;
		}
		if (i > 0) {
			e[i - 1].push_back(make_pair(i, cellPrice[i]));
		}
		if (i < n - 1) {
			e[i + 1].push_back(make_pair(i, cellPrice[i]));
		}
	}
	int m = enterCell.size();
	FOR (i, m) {
		if (cellPrice[exitCell[i]] != -1) {
			e[enterCell[i]].push_back(make_pair(exitCell[i], -1));
		}
	}

	FOR (i, n) {
		FOR (j, n) {
			d[i][j] = make_pair(INF, INF);
		}
	}
	d[0][0] = make_pair(0, 0);
	priority_queue<pair<PII, PII>, vector<pair<PII, PII> >, greater<pair<PII, PII> > > pq;
	pq.push(make_pair(d[0][0], make_pair(0, 0)));
	while (!pq.empty()) {
		PII t = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (d[x][y] != t) {
			continue;
		} else if (x == n - 1) {
			vector<int> ret;
			ret.push_back(t.first);
			ret.push_back(t.second);
			return ret;
		} else {
			FOREACH (i, e[x]) {
				int xx = i->first;
				int yy = y;
				PII tt;
				if (i->second == -1) {
					++yy;
					tt = t + make_pair(teleportPrice + y, 1);
				} else {
					tt = t + make_pair(i->second, 1);
				}
				if (xx < n && yy < n && tt < d[xx][yy]) {
					d[xx][yy] = tt;
					pq.push(make_pair(tt, make_pair(xx, yy)));
				}
			}
		}
	}

	return vector<int>();
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
        int cellPriceARRAY[] = {100};
        vector <int> cellPrice( cellPriceARRAY, cellPriceARRAY+ARRSIZE(cellPriceARRAY) );
        int enterCellARRAY[] = {0};
        vector <int> enterCell( enterCellARRAY, enterCellARRAY+ARRSIZE(enterCellARRAY) );
        int exitCellARRAY[] = {0};
        vector <int> exitCell( exitCellARRAY, exitCellARRAY+ARRSIZE(exitCellARRAY) );
        int retrunValueARRAY[] = {0, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheapestRoute theObject;
        eq(0, theObject.routePrice(cellPrice, enterCell, exitCell, 1000),retrunValue);
    }
    {
        int cellPriceARRAY[] = {0,-1,0,0};
        vector <int> cellPrice( cellPriceARRAY, cellPriceARRAY+ARRSIZE(cellPriceARRAY) );
        int enterCellARRAY[] = {0};
        vector <int> enterCell( enterCellARRAY, enterCellARRAY+ARRSIZE(enterCellARRAY) );
        int exitCellARRAY[] = {2};
        vector <int> exitCell( exitCellARRAY, exitCellARRAY+ARRSIZE(exitCellARRAY) );
        int retrunValueARRAY[] = {1000, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheapestRoute theObject;
        eq(1, theObject.routePrice(cellPrice, enterCell, exitCell, 1000),retrunValue);
    }
    {
        int cellPriceARRAY[] = {1,2,3};
        vector <int> cellPrice( cellPriceARRAY, cellPriceARRAY+ARRSIZE(cellPriceARRAY) );
        int retrunValueARRAY[] = {5, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheapestRoute theObject;
        eq(2, theObject.routePrice(cellPrice, vector <int>(), vector <int>(), 100),retrunValue);
    }
    {
        int cellPriceARRAY[] = {1,0,-1};
        vector <int> cellPrice( cellPriceARRAY, cellPriceARRAY+ARRSIZE(cellPriceARRAY) );
        int enterCellARRAY[] = {0};
        vector <int> enterCell( enterCellARRAY, enterCellARRAY+ARRSIZE(enterCellARRAY) );
        int exitCellARRAY[] = {2};
        vector <int> exitCell( exitCellARRAY, exitCellARRAY+ARRSIZE(exitCellARRAY) );
        CheapestRoute theObject;
        eq(3, theObject.routePrice(cellPrice, enterCell, exitCell, 0),vector <int>());
    }
    {
        int cellPriceARRAY[] = {4,2,1,0,5,6,0,3,0};
        vector <int> cellPrice( cellPriceARRAY, cellPriceARRAY+ARRSIZE(cellPriceARRAY) );
        int enterCellARRAY[] = {4,4,3,7,5,4,2,5,8,4};
        vector <int> enterCell( enterCellARRAY, enterCellARRAY+ARRSIZE(enterCellARRAY) );
        int exitCellARRAY[] = {7,3,5,0,5,4,5,0,8,3};
        vector <int> exitCell( exitCellARRAY, exitCellARRAY+ARRSIZE(exitCellARRAY) );
        int retrunValueARRAY[] = {14, 6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheapestRoute theObject;
        eq(4, theObject.routePrice(cellPrice, enterCell, exitCell, 8),retrunValue);
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
