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

struct SymmetricPie {
	int getLines(vector <int> dogs);
};

int SymmetricPie::getLines(vector <int> d) {
	int n = d.size();
	sort(d.begin(), d.end());
	int ret = 0;
	do {
		int cnt = 0, sum;
		for (int i = 1; i < n; ++i) {
			sum = 0;
			for (int j = i; j < n; ++j) {
				sum += d[j];
				if (sum == 50) {
					++cnt;
				}
			}
		}
		ret = max(ret, cnt);
	} while (next_permutation(d.begin(), d.end()));
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
        int dogsARRAY[] = {10,40,10,40};
        vector <int> dogs( dogsARRAY, dogsARRAY+ARRSIZE(dogsARRAY) );
        SymmetricPie theObject;
        eq(0, theObject.getLines(dogs),2);
    }
    {
        int dogsARRAY[] = {10,50,40};
        vector <int> dogs( dogsARRAY, dogsARRAY+ARRSIZE(dogsARRAY) );
        SymmetricPie theObject;
        eq(1, theObject.getLines(dogs),1);
    }
    {
        int dogsARRAY[] = {50,50};
        vector <int> dogs( dogsARRAY, dogsARRAY+ARRSIZE(dogsARRAY) );
        SymmetricPie theObject;
        eq(2, theObject.getLines(dogs),1);
    }
    {
        int dogsARRAY[] = {1,48,1,1,48,1};
        vector <int> dogs( dogsARRAY, dogsARRAY+ARRSIZE(dogsARRAY) );
        SymmetricPie theObject;
        eq(3, theObject.getLines(dogs),3);
    }
    {
        int dogsARRAY[] = {2,2,96};
        vector <int> dogs( dogsARRAY, dogsARRAY+ARRSIZE(dogsARRAY) );
        SymmetricPie theObject;
        eq(4, theObject.getLines(dogs),0);
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
