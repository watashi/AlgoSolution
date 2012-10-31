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

struct TheBrickTowerMediumDivOne {
	vector <int> find(vector <int> heights);
};

const int MAXN = 64;

vector <int> TheBrickTowerMediumDivOne::find(vector <int> heights) {
    int n = heights.size();
    map<int, vector<int> > mp;
    for (int i = 0; i < n; ++i) {
        mp[heights[i]].push_back(i);
    }
    vector<int> pre;
    for (map<int, vector<int> >::const_iterator it = mp.begin(); it != mp.end(); ++it) {
        vector<int> idx = it->second;
        vector<int> cur = pre;
        cur.insert(cur.end(), idx.begin(), idx.end());
        for (int i = 0; i <= (int)idx.size(); ++i) {
            vector<int> tmp = pre;
            tmp.insert(tmp.begin(), idx.begin(), idx.begin() + i);
            tmp.insert(tmp.end(), idx.begin() + i, idx.end());
            cur = min(cur, tmp);
        }
        pre = cur;
    }
    return pre;
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
        int heightsARRAY[] = {4, 7, 5};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(0, theObject.find(heights),retrunValue);
    }
    {
        int heightsARRAY[] = {4, 4, 4, 4, 4, 4, 4};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 1, 2, 3, 4, 5, 6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(1, theObject.find(heights),retrunValue);
    }
    {
        int heightsARRAY[] = {2, 3, 3, 2};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 3, 1, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(2, theObject.find(heights),retrunValue);
    }
    {
        int heightsARRAY[] = {13, 32, 38, 25, 43, 47, 6};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        int retrunValueARRAY[] = {0, 6, 3, 1, 2, 4, 5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheBrickTowerMediumDivOne theObject;
        eq(3, theObject.find(heights),retrunValue);
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

