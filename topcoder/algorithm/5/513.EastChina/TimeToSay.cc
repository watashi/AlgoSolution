#include <algorithm>
#include <iostream>
#include <sstream>
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

struct TimeToSay {
	int maximumJoy(vector <int> lostHealth, vector <int> joy);
};

int TimeToSay::maximumJoy(vector <int> lostHealth, vector <int> joy) {
	int n = joy.size();
	vector<int> dp(100, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 99; j >= lostHealth[i]; --j) {
			dp[j] = max(dp[j], dp[j - lostHealth[i]] + joy[i]);
		}
	}
	return dp[99];
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
        int lostHealthARRAY[] = {1, 21, 79};
        vector <int> lostHealth( lostHealthARRAY, lostHealthARRAY+ARRSIZE(lostHealthARRAY) );
        int joyARRAY[] = {20, 30, 25};
        vector <int> joy( joyARRAY, joyARRAY+ARRSIZE(joyARRAY) );
        TimeToSay theObject;
        eq(0, theObject.maximumJoy(lostHealth, joy),50);
    }
    {
        int lostHealthARRAY[] = {100};
        vector <int> lostHealth( lostHealthARRAY, lostHealthARRAY+ARRSIZE(lostHealthARRAY) );
        int joyARRAY[] = {20};
        vector <int> joy( joyARRAY, joyARRAY+ARRSIZE(joyARRAY) );
        TimeToSay theObject;
        eq(1, theObject.maximumJoy(lostHealth, joy),0);
    }
    {
        int lostHealthARRAY[] = {100, 15, 1, 2, 3, 4, 6, 5};
        vector <int> lostHealth( lostHealthARRAY, lostHealthARRAY+ARRSIZE(lostHealthARRAY) );
        int joyARRAY[] = {49, 40, 1, 2, 3, 4, 5, 4};
        vector <int> joy( joyARRAY, joyARRAY+ARRSIZE(joyARRAY) );
        TimeToSay theObject;
        eq(2, theObject.maximumJoy(lostHealth, joy),59);
    }
    {
        int lostHealthARRAY[] = {100, 50, 20, 13};
        vector <int> lostHealth( lostHealthARRAY, lostHealthARRAY+ARRSIZE(lostHealthARRAY) );
        int joyARRAY[] = {20, 30, 40, 50};
        vector <int> joy( joyARRAY, joyARRAY+ARRSIZE(joyARRAY) );
        TimeToSay theObject;
        eq(3, theObject.maximumJoy(lostHealth, joy),120);
    }
    {
        int lostHealthARRAY[] = {100, 26, 13, 17, 24, 33, 100, 99};
        vector <int> lostHealth( lostHealthARRAY, lostHealthARRAY+ARRSIZE(lostHealthARRAY) );
        int joyARRAY[] = {34, 56, 21, 1, 24, 34, 100, 99};
        vector <int> joy( joyARRAY, joyARRAY+ARRSIZE(joyARRAY) );
        TimeToSay theObject;
        eq(4, theObject.maximumJoy(lostHealth, joy),135);
    }
    {
        int lostHealthARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector <int> lostHealth( lostHealthARRAY, lostHealthARRAY+ARRSIZE(lostHealthARRAY) );
        int joyARRAY[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
        vector <int> joy( joyARRAY, joyARRAY+ARRSIZE(joyARRAY) );
        TimeToSay theObject;
        eq(5, theObject.maximumJoy(lostHealth, joy),1200);
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
