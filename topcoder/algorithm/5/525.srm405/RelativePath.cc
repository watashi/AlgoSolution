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

struct RelativePath {
	string makeRelative(string path, string currentDir);
};

vector<string> split(string s) {
	FOREACH (i, s) {
		if (*i == '/') {
			*i = ' ';
		}
	}
	istringstream iss(s);
	vector<string> ret;
	while (iss >> s) {
		ret.push_back(s);
	}
	return ret;
}

string RelativePath::makeRelative(string path, string currentDir) {
	vector<string> a = split(path);
	vector<string> b = split(currentDir);
	int n = 0;
	while (n < (int)a.size() && n < (int)b.size() && a[n] == b[n]) {
		++n;
	}
	string ret = "";
	for (int i = n; i < (int)b.size(); ++i) {
		ret += '/';
		ret += "..";
	}
	for (int i = n; i < (int)a.size(); ++i) {
		ret += '/';
		ret += a[i];
	}
	return ret.substr(1);
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
        RelativePath theObject;
        eq(0, theObject.makeRelative("/home/top/data/file", "/home/user/pictures"),"../../top/data/file");
    }
    {
        RelativePath theObject;
        eq(1, theObject.makeRelative("/home/user/movies/title", "/home/user/pictures"),"../movies/title");
    }
    {
        RelativePath theObject;
        eq(2, theObject.makeRelative("/file", "/"),"file");
    }
    {
        RelativePath theObject;
        eq(3, theObject.makeRelative("/a/b/a/b/a/b", "/a/b/a/a/b/a/b"),"../../../../b/a/b");
    }
    {
        RelativePath theObject;
        eq(4, theObject.makeRelative("/root/root/root", "/root"),"root/root");
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
