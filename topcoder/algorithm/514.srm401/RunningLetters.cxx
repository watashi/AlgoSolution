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

struct RunningLetters {
	int newsLength(vector <string> running);
};

const int MAXN = 1 << 20;
int fail[MAXN];

void initFail(int len, const char pat[], int fail[]) {
	fail[0] = -1;
	for (int i = 1; i < len; ++i) {
		int k = fail[i - 1];
		while (k >= 0 && pat[k + 1] != pat[i]) {
			k = fail[k];
		}
		fail[i] = (pat[k + 1] == pat[i]) ? k + 1 : -1;
	}
}

int RunningLetters::newsLength(vector <string> running) {
	string s = "";
	for (vector<string>::const_iterator it = running.begin(); it != running.end(); ++it) {
		s += *it;
	}
	int n;
	string t;
	istringstream iss(s);
	s = "";
	while (iss >> n >> t) {
		for (int i = 0; i < n; ++i) {
			s += t;
		}
	}
	n = s.length();
	initFail(n, s.c_str(), fail);
	return n - (fail[n - 1] + 1);
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
        string runningARRAY[] = {"3 abc 1 ab"};
        vector <string> running( runningARRAY, runningARRAY+ARRSIZE(runningARRAY) );
        RunningLetters theObject;
        eq(0, theObject.newsLength(running),3);
    }
    {
        string runningARRAY[] = {"1 babaaba"};
        vector <string> running( runningARRAY, runningARRAY+ARRSIZE(runningARRAY) );
        RunningLetters theObject;
        eq(1, theObject.newsLength(running),5);
    }
    {
        string runningARRAY[] = {"1 ba 1 c 1 bacba 3 cba"};
        vector <string> running( runningARRAY, runningARRAY+ARRSIZE(runningARRAY) );
        RunningLetters theObject;
        eq(2, theObject.newsLength(running),3);
    }
    {
        string runningARRAY[] = {"42 runningletters 42 runningletters 1 running"};
        vector <string> running( runningARRAY, runningARRAY+ARRSIZE(runningARRAY) );
        RunningLetters theObject;
        eq(3, theObject.newsLength(running),14);
    }
    {
        string runningARRAY[] = {"1 b ", "1 a ", "1 b ", "1 a", " 1 b"};
        vector <string> running( runningARRAY, runningARRAY+ARRSIZE(runningARRAY) );
        RunningLetters theObject;
        eq(4, theObject.newsLength(running),2);
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
