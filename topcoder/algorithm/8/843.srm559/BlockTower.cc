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

struct BlockTower {
	int getTallest(vector <int> blockHeights);
};

const int MAXN = 64;
int os[MAXN], es[MAXN];

int BlockTower::getTallest(vector <int> h) {
  int n = h.size();
  es[0] = 0;
  for (int i = 0; i < n; ++i) {
    es[i + 1] = es[i] + (h[i] + 1) % 2 * h[i];
  }
  os[n] = 0;
  for (int i = n - 1; i >= 0; --i) {
    os[i] = os[i + 1] + h[i] % 2 * h[i];
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, es[i] + os[i]);
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
        int blockHeightsARRAY[] = {4,7};
        vector <int> blockHeights( blockHeightsARRAY, blockHeightsARRAY+ARRSIZE(blockHeightsARRAY) );
        BlockTower theObject;
        eq(0, theObject.getTallest(blockHeights),11);
    }
    {
        int blockHeightsARRAY[] = {7,4};
        vector <int> blockHeights( blockHeightsARRAY, blockHeightsARRAY+ARRSIZE(blockHeightsARRAY) );
        BlockTower theObject;
        eq(1, theObject.getTallest(blockHeights),7);
    }
    {
        int blockHeightsARRAY[] = {7};
        vector <int> blockHeights( blockHeightsARRAY, blockHeightsARRAY+ARRSIZE(blockHeightsARRAY) );
        BlockTower theObject;
        eq(2, theObject.getTallest(blockHeights),7);
    }
    {
        int blockHeightsARRAY[] = {4};
        vector <int> blockHeights( blockHeightsARRAY, blockHeightsARRAY+ARRSIZE(blockHeightsARRAY) );
        BlockTower theObject;
        eq(3, theObject.getTallest(blockHeights),4);
    }
    {
        int blockHeightsARRAY[] = {48,1,50,1,50,1,48};
        vector <int> blockHeights( blockHeightsARRAY, blockHeightsARRAY+ARRSIZE(blockHeightsARRAY) );
        BlockTower theObject;
        eq(4, theObject.getTallest(blockHeights),196);
    }
    {
        int blockHeightsARRAY[] = {49,2,49,2,49};
        vector <int> blockHeights( blockHeightsARRAY, blockHeightsARRAY+ARRSIZE(blockHeightsARRAY) );
        BlockTower theObject;
        eq(5, theObject.getTallest(blockHeights),147);
    }
    {
        int blockHeightsARRAY[] = {44,3,44,3,44,47,2,47,2,47,2};
        vector <int> blockHeights( blockHeightsARRAY, blockHeightsARRAY+ARRSIZE(blockHeightsARRAY) );
        BlockTower theObject;
        eq(6, theObject.getTallest(blockHeights),273);
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

