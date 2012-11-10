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

struct MagicalSpheres {
	int divideWork(int spheresCount, int fakeSpheresCount, int gnomesAvailable);
};

llint facexp(llint n, llint p) {
	llint m = 0;
	for (int i = 1; n > 0; --i) {
		m += n / p;
		n /= p;
	}
	return m;
}

map<int, int> factor(int n) {
	map<int, int> ret;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			++ret[i];
			n /= i;
		}
	}
	if (n > 1) {
		++ret[n];
	}
	return ret;
}

int MagicalSpheres::divideWork(int spheresCount, int fakeSpheresCount, int gnomesAvailable) {
	llint m = spheresCount;
	llint n = fakeSpheresCount;
	
	while (true) {
		bool flag = true;
		map<int, int> f = factor(gnomesAvailable);
		FOREACH (fi, f) {
			llint c = facexp(m + n, fi->first) - facexp(m, fi->first) - facexp(n, fi->first);
			if (c < fi->second) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return gnomesAvailable;
		} else {
			--gnomesAvailable;
		}
	}

	return -1;
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
        MagicalSpheres theObject;
        eq(0, theObject.divideWork(3, 1, 3),2);
    }
    {
        MagicalSpheres theObject;
        eq(1, theObject.divideWork(3, 3, 50),20);
    }
    {
        MagicalSpheres theObject;
        eq(2, theObject.divideWork(4, 3, 4),1);
    }
    {
        MagicalSpheres theObject;
        eq(3, theObject.divideWork(15634, 456, 5000),4990);
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
