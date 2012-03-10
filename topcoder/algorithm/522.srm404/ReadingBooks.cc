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

struct ReadingBooks {
	int countBooks(vector <string> readParts);
};

int ReadingBooks::countBooks(vector <string> readParts) {
	int ret = 0;
	for (int i = 0; i + 3 <= (int)readParts.size(); ) {
		if (count(readParts.begin() + i, readParts.begin() + i + 3, "introduction") > 0 &&
			count(readParts.begin() + i, readParts.begin() + i + 3, "story") > 0 &&
			count(readParts.begin() + i, readParts.begin() + i + 3, "edification") > 0) {
			++ret;
			i += 3;
		} else {
			++i;
		}
	}
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
        string readPartsARRAY[] = {"introduction", "story", "introduction", "edification"};
        vector <string> readParts( readPartsARRAY, readPartsARRAY+ARRSIZE(readPartsARRAY) );
        ReadingBooks theObject;
        eq(0, theObject.countBooks(readParts),1);
    }
    {
        string readPartsARRAY[] = {"introduction", "story", "edification", "introduction", "story", "edification"};
        vector <string> readParts( readPartsARRAY, readPartsARRAY+ARRSIZE(readPartsARRAY) );
        ReadingBooks theObject;
        eq(1, theObject.countBooks(readParts),2);
    }
    {
        string readPartsARRAY[] = {"introduction", "story", "introduction", "edification", "story", "introduction"};
        vector <string> readParts( readPartsARRAY, readPartsARRAY+ARRSIZE(readPartsARRAY) );
        ReadingBooks theObject;
        eq(2, theObject.countBooks(readParts),1);
    }
    {
        string readPartsARRAY[] = {"introduction", "story", "introduction", "edification", "story",
            "story", "edification", "edification", "edification", "introduction",
            "introduction", "edification", "story", "introduction", "story",
            "edification", "edification", "story", "introduction", "edification",
            "story", "story", "edification", "introduction", "story"};
        vector <string> readParts( readPartsARRAY, readPartsARRAY+ARRSIZE(readPartsARRAY) );
        ReadingBooks theObject;
        eq(3, theObject.countBooks(readParts),5);
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
