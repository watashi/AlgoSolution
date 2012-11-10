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

struct EvilRobot {
	string createProgram(int N, int robotX, int robotY, int trapX, int trapY);
};

const string ERR = "I'LL GET YOU NEXT TIME";

string EvilRobot::createProgram(int N, int robotX, int robotY, int trapX, int trapY) {
	long long x = trapX - robotX;
	long long y = trapY - robotY;
	if (x < 0 || y < 0) {
		return ERR;
	}
	string ans = ERR;
	long long c = (x + y) / N;
	for (int i = 0; i <= N; ++i) {
		long long x1 = i;
		long long y1 = N - i;
		long long x2 = x - x1 * c;
		long long y2 = y - y1 * c;
		if (x2 < 0 || x2 > x1 || y2 < 0 || y2 > y1) {
			continue;
		}
		string tmp = "";
		FOR (j, x2) {
			tmp += 'R';
		}
		FOR (j, y2) {
			tmp += 'U';
		}
		FOR (j, x1 - x2) {
			tmp += 'R';
		}
		FOR (j, y1 - y2) {
			tmp += 'U';
		}
		if (ans == ERR || ans > tmp) {
			ans = tmp;
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
        EvilRobot theObject;
        eq(0, theObject.createProgram(3, 1, 1, 3, 4),"RUU");
    }
    {
        EvilRobot theObject;
        eq(1, theObject.createProgram(10, 1, 1, 1, 4),"UUURRRRRRR");
    }
    {
        EvilRobot theObject;
        eq(2, theObject.createProgram(3, 2, 1, 1, 1),"I'LL GET YOU NEXT TIME");
    }
    {
        EvilRobot theObject;
        eq(3, theObject.createProgram(5, 2, 2, 12, 12),"I'LL GET YOU NEXT TIME");
    }
    {
        EvilRobot theObject;
        eq(4, theObject.createProgram(48, 3, 0, 3000000, 5000000),"RRRRRRRRRUUUUUUUUUUUUUUUUUUUURRRRRRRRRUUUUUUUUUU");
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
