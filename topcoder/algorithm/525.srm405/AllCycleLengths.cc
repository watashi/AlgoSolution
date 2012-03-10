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

struct AllCycleLengths {
	string findAll(vector <string> arcs);
};

const int MAXN = 32;
bool a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

string AllCycleLengths::findAll(vector <string> arcs) {
	MEMSET(a, 0);
	MEMSET(b, 0);
	int n = arcs.size();
	FOR (i, n) FOR (j, n) a[i][j] = arcs[i][j] == 'Y';
	FOR (i, n) b[i][i] = true;
	int g = 0;
	string s = "";
	FOR (t, 1000) {
		MEMSET(c, 0);
		FOR (i, n) FOR(j, n) FOR(k, n) c[i][j] |= a[i][k] & b[k][j];
		memcpy(b, c, sizeof(c));
		bool flag = false;
		FOR (i, n) flag |= c[i][i];
		if (flag) {
			s += '1';
			g = gcd(g, t + 1);
		} else {
			s += '0';
		}
	}
	while ((int)s.length() > g && s[s.length() - 1] == s[s.length() - 1 - g]) {
		s.erase(s.end() - 1);
	}
	s = s.substr(0, s.length() - g) + "(" + s.substr(s.length() - g) + ")";
	return s;
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
        string arcsARRAY[] = {"NYNN", "NNYY", "NNNY", "YNNN"};
        vector <string> arcs( arcsARRAY, arcsARRAY+ARRSIZE(arcsARRAY) );
        AllCycleLengths theObject;
        eq(0, theObject.findAll(arcs),"00110(1)");
    }
    {
        string arcsARRAY[] = {"NY", "YN"};
        vector <string> arcs( arcsARRAY, arcsARRAY+ARRSIZE(arcsARRAY) );
        AllCycleLengths theObject;
        eq(1, theObject.findAll(arcs),"(01)");
    }
    {
        string arcsARRAY[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"};
        vector <string> arcs( arcsARRAY, arcsARRAY+ARRSIZE(arcsARRAY) );
        AllCycleLengths theObject;
        eq(2, theObject.findAll(arcs),"0(1)");
    }
    {
        string arcsARRAY[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"};
        vector <string> arcs( arcsARRAY, arcsARRAY+ARRSIZE(arcsARRAY) );
        AllCycleLengths theObject;
        eq(3, theObject.findAll(arcs),"010(1)");
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
