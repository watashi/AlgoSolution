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

struct CandyGame {
	int maximumCandy(vector <string> graph, int target);
};

const int INF = 2000000001;
const int MAXN = 100;

int n;
vector<string> g;
bool mark[MAXN];

pair<long long, int> gao(int v) {
	pair<long long, int> ret, tmp;
	int d = MAXN;
	
	mark[v] = true;
	FOR (i, n) {
		if (g[v][i] == 'Y' && !mark[i]) {
			tmp = gao(i);
			d = min(d, tmp.second);
			ret.first += tmp.first + (1LL << (tmp.second - 1));
			ret.second = max(ret.second, tmp.second);
		}
	}
	++ret.second;

	return ret;
}

int CandyGame::maximumCandy(vector <string> graph, int target) {
	n = graph.size();
	g = graph;
	fill(mark, mark + n, false);
	long long m = gao(target).first;
	FOR (i, n) {
		if (!mark[i]) {
			return -1;
		}
	}
	return m >= INF ? -1 : m;
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
        string graphARRAY[] = {"NYN", "YNY", "NYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        CandyGame theObject;
        eq(0, theObject.maximumCandy(graph, 1),2);
    }
    {
        string graphARRAY[] = {"NYN", "YNY", "NYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        CandyGame theObject;
        eq(1, theObject.maximumCandy(graph, 2),3);
    }
    {
        string graphARRAY[] = {"NYYY", "YNNN", "YNNN", "YNNN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        CandyGame theObject;
        eq(2, theObject.maximumCandy(graph, 0),3);
    }
    {
        string graphARRAY[] = {"NYYY", "YNNN", "YNNN", "YNNN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        CandyGame theObject;
        eq(3, theObject.maximumCandy(graph, 1),4);
    }
    {
        string graphARRAY[] = {"NYNNNYN",
            "YNYNYNN",
            "NYNYNNN",
            "NNYNNNN",
            "NYNNNNN",
            "YNNNNNY",
            "NNNNNYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        CandyGame theObject;
        eq(4, theObject.maximumCandy(graph, 0),11);
    }
    {
        string graphARRAY[] = {"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "YNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYN",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNY",
            "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        CandyGame theObject;
        eq(5, theObject.maximumCandy(graph, 0),-1);
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
