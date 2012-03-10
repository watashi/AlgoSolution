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

struct RevealTriangle {
	vector <string> calcTriangle(vector <string> questionMarkTriangle);
};

inline char calc(char a, char s) {
	if (a <= s) {
		return '0' + (s - a);
	} else {
		return '0' + (s - a + 10);
	}
}

vector <string> RevealTriangle::calcTriangle(vector <string> q) {
	int n = q.size();
	for (int i = n - 2; i >= 0; --i) {
		int k = q[i].find_first_not_of('?');
		for (int j = k - 1; j >= 0; --j) {
			q[i][j] = calc(q[i][j + 1], q[i + 1][j]);
		}
		for (int j = k + 1; j < (int)q[i].length(); ++j) {
			q[i][j] = calc(q[i][j - 1], q[i + 1][j - 1]);
		}
	}
	return q;
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
        string questionMarkTriangleARRAY[] = {"4??", 
            "?2", 
            "1"};
        vector <string> questionMarkTriangle( questionMarkTriangleARRAY, questionMarkTriangleARRAY+ARRSIZE(questionMarkTriangleARRAY) );
        string retrunValueARRAY[] = {"457", "92", "1" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RevealTriangle theObject;
        eq(0, theObject.calcTriangle(questionMarkTriangle),retrunValue);
    }
    {
        string questionMarkTriangleARRAY[] = {"1"};
        vector <string> questionMarkTriangle( questionMarkTriangleARRAY, questionMarkTriangleARRAY+ARRSIZE(questionMarkTriangleARRAY) );
        string retrunValueARRAY[] = {"1" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RevealTriangle theObject;
        eq(1, theObject.calcTriangle(questionMarkTriangle),retrunValue);
    }
    {
        string questionMarkTriangleARRAY[] = {"???2", "??2", "?2", "2"};
        vector <string> questionMarkTriangle( questionMarkTriangleARRAY, questionMarkTriangleARRAY+ARRSIZE(questionMarkTriangleARRAY) );
        string retrunValueARRAY[] = {"0002", "002", "02", "2" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RevealTriangle theObject;
        eq(2, theObject.calcTriangle(questionMarkTriangle),retrunValue);
    }
    {
        string questionMarkTriangleARRAY[] = {"??5?", "??9", "?4", "6"};
        vector <string> questionMarkTriangle( questionMarkTriangleARRAY, questionMarkTriangleARRAY+ARRSIZE(questionMarkTriangleARRAY) );
        string retrunValueARRAY[] = {"7054", "759", "24", "6" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        RevealTriangle theObject;
        eq(3, theObject.calcTriangle(questionMarkTriangle),retrunValue);
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
