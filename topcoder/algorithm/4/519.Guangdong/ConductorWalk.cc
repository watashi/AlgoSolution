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

struct ConductorWalk {
	vector <int> getObserverRecords(vector <int> orderSeat, vector <int> orderTime, int inspectorSeat);
};

vector <int> ConductorWalk::getObserverRecords(vector <int> orderSeat, vector <int> orderTime, int inspectorSeat) {
	int n = orderSeat.size(), t = 0;
	vector<int> ret;
	FOR(i, n) {
		t = max(t, orderTime[i]);
		if (orderSeat[i] > inspectorSeat) {
			ret.push_back(t + inspectorSeat);
			ret.push_back(t + orderSeat[i] + orderSeat[i] - inspectorSeat);
		} else if (orderSeat[i] == inspectorSeat) {
			ret.push_back(t + inspectorSeat);
		}
		t += 2 * orderSeat[i];
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
        int orderSeatARRAY[] = {1, 3};
        vector <int> orderSeat( orderSeatARRAY, orderSeatARRAY+ARRSIZE(orderSeatARRAY) );
        int orderTimeARRAY[] = {5, 105};
        vector <int> orderTime( orderTimeARRAY, orderTimeARRAY+ARRSIZE(orderTimeARRAY) );
        int retrunValueARRAY[] = {107, 109 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConductorWalk theObject;
        eq(0, theObject.getObserverRecords(orderSeat, orderTime, 2),retrunValue);
    }
    {
        int orderSeatARRAY[] = {10, 20, 30};
        vector <int> orderSeat( orderSeatARRAY, orderSeatARRAY+ARRSIZE(orderSeatARRAY) );
        int orderTimeARRAY[] = {0, 5, 10};
        vector <int> orderTime( orderTimeARRAY, orderTimeARRAY+ARRSIZE(orderTimeARRAY) );
        int retrunValueARRAY[] = {1, 19, 21, 59, 61, 119 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConductorWalk theObject;
        eq(1, theObject.getObserverRecords(orderSeat, orderTime, 1),retrunValue);
    }
    {
        int orderSeatARRAY[] = {1};
        vector <int> orderSeat( orderSeatARRAY, orderSeatARRAY+ARRSIZE(orderSeatARRAY) );
        int orderTimeARRAY[] = {0};
        vector <int> orderTime( orderTimeARRAY, orderTimeARRAY+ARRSIZE(orderTimeARRAY) );
        int retrunValueARRAY[] = {1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConductorWalk theObject;
        eq(2, theObject.getObserverRecords(orderSeat, orderTime, 1),retrunValue);
    }
    {
        int orderSeatARRAY[] = {1};
        vector <int> orderSeat( orderSeatARRAY, orderSeatARRAY+ARRSIZE(orderSeatARRAY) );
        int orderTimeARRAY[] = {0};
        vector <int> orderTime( orderTimeARRAY, orderTimeARRAY+ARRSIZE(orderTimeARRAY) );
        ConductorWalk theObject;
        eq(3, theObject.getObserverRecords(orderSeat, orderTime, 100),vector <int>());
    }
    {
        int orderSeatARRAY[] = {5, 5, 4, 5, 10, 5, 3, 7, 4};
        vector <int> orderSeat( orderSeatARRAY, orderSeatARRAY+ARRSIZE(orderSeatARRAY) );
        int orderTimeARRAY[] = {4, 18, 36, 43, 61, 78, 90, 101, 113};
        vector <int> orderTime( orderTimeARRAY, orderTimeARRAY+ARRSIZE(orderTimeARRAY) );
        int retrunValueARRAY[] = {8, 10, 22, 24, 40, 48, 50, 65, 77, 85, 87, 105, 111, 119 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConductorWalk theObject;
        eq(4, theObject.getObserverRecords(orderSeat, orderTime, 4),retrunValue);
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
