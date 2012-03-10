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

struct CorporationSalary {
	long long totalSalary(vector <string> relations);
};

const int MAXN = 64;
vector<int> e[MAXN];
int c[MAXN];
long long s[MAXN];

long long CorporationSalary::totalSalary(vector <string> r) {
	int n = r.size();
	FOR (i, n) {
		c[i] = 0;
		e[i].clear();
	}
	FOR (i, n) {
		FOR (j, n) {
			if (r[i][j] == 'Y') {
				e[j].push_back(i);
				++c[i];
			}
		}
	}

	queue<int> q;
	MEMSET(s, 0);
	FOR (i, n) {
		if (c[i] == 0) {
			q.push(i);
			s[i] = 1LL;
		}
	}

	while (!q.empty()) {
		int i = q.front();
		q.pop();
		FOREACH (j, e[i]) {
			s[*j] += s[i];
			if (--c[*j] == 0) {
				q.push(*j);
			}
		}
	}
	return accumulate(s, s + n, 0LL);
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
        string relationsARRAY[] = {"N"};
        vector <string> relations( relationsARRAY, relationsARRAY+ARRSIZE(relationsARRAY) );
        CorporationSalary theObject;
        eq(0, theObject.totalSalary(relations),1L);
    }
    {
        string relationsARRAY[] = {"NNYN",
            "NNYN",
            "NNNN",
            "NYYN"};
        vector <string> relations( relationsARRAY, relationsARRAY+ARRSIZE(relationsARRAY) );
        CorporationSalary theObject;
        eq(1, theObject.totalSalary(relations),5L);
    }
    {
        string relationsARRAY[] = {"NNNNNN",
            "YNYNNY",
            "YNNNNY",
            "NNNNNN",
            "YNYNNN",
            "YNNYNN"};
        vector <string> relations( relationsARRAY, relationsARRAY+ARRSIZE(relationsARRAY) );
        CorporationSalary theObject;
        eq(2, theObject.totalSalary(relations),17L);
    }
    {
        string relationsARRAY[] = {"NYNNYN",
            "NNNNNN",
            "NNNNNN",
            "NNYNNN",
            "NNNNNN",
            "NNNYYN"};
        vector <string> relations( relationsARRAY, relationsARRAY+ARRSIZE(relationsARRAY) );
        CorporationSalary theObject;
        eq(3, theObject.totalSalary(relations),8L);
    }
    {
        string relationsARRAY[] = {"NNNN",
            "NNNN",
            "NNNN",
            "NNNN"};
        vector <string> relations( relationsARRAY, relationsARRAY+ARRSIZE(relationsARRAY) );
        CorporationSalary theObject;
        eq(4, theObject.totalSalary(relations),4L);
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
