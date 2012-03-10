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

struct OrderedSuperString {
	int getLength(vector <string> words);
};

int OrderedSuperString::getLength(vector <string> words) {
	string ret = "";
	int pos = 0;
	FOREACH (w, words) {
		for (int i = pos; i <= (int)ret.length(); ++i) {
			int len = min((int)ret.length() - i, (int)w->length());
			if (strncmp(ret.c_str() + i, w->c_str(), len) == 0) {
				if (len < (int)w->length()) {
					ret += w->substr(len);
				}
				pos = i;
				break;
			}
		}
	}
	return (int)ret.length();
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
        string wordsARRAY[] = {"abc","ca"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        OrderedSuperString theObject;
        eq(0, theObject.getLength(words),4);
    }
    {
        string wordsARRAY[] = {"a","a","b","a"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        OrderedSuperString theObject;
        eq(1, theObject.getLength(words),3);
    }
    {
        string wordsARRAY[] = {"abcdef", "ab","bc", "de","ef"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        OrderedSuperString theObject;
        eq(2, theObject.getLength(words),6);
    }
    {
        string wordsARRAY[] = {"ab","bc", "de","ef","abcdef"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        OrderedSuperString theObject;
        eq(3, theObject.getLength(words),12);
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
