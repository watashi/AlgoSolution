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

struct IdealString {
	string construct(int length);
};

int length;
vector<int> v;

void gao(int n, int m, int s, string& ans) {
	if (n == 0) {
		vector<char> w(length, '.');
		FOR (i, v.size()) {
			w[v[i] - 1] = 'A' + i;
		}
		int k = 0;
		FOR (i, v.size()) {
			FOR (j, v[i] - 1) {
				while (w[k] != '.') {
					++k;
				}
				w[k] = 'A' + i;
			}
		}
		string tmp(w.begin(), w.end());
		if (ans == "" || ans > tmp) {
			ans = tmp;
		}
	} else {
		for (int i = m; i <= n && i <= s; ++i) {
			v.push_back(i);
			gao(n - i, i + 1, s + i, ans);
			v.pop_back();
		}
	}
}

string IdealString::construct(int length) {
	string ans = "";
	::length = length;
	gao(length, 1, 1, ans);
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
        IdealString theObject;
        eq(0, theObject.construct(1),"A");
    }
    {
        IdealString theObject;
        eq(1, theObject.construct(3),"ABB");
    }
    {
        IdealString theObject;
        eq(2, theObject.construct(2),"");
    }
    {
        IdealString theObject;
        eq(3, theObject.construct(6),"ABCBCC");
    }
    {
        IdealString theObject;
        eq(4, theObject.construct(7),"ABBCCCC");
    }
    {
        IdealString theObject;
        eq(5, theObject.construct(5),"");
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
