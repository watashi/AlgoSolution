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
#define FOREACH(i, n) for (typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
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

struct FoldThePaper {
	int getValue(vector <string> paper);
};

void gao(vector<set<int> > v, set<set<int> >& s, set<vector<set<int> > >& done) {
	if (v.front() > v.back()) {
		reverse(v.begin(), v.end());
	}
	if (!done.insert(v).second) {
		return;
	}
	FOREACH (w, v) {
		s.insert(*w);
	}
	int n = v.size();
	for (int i = 1; i < n; ++i) {
		vector<set<int> > w(max(i, n - i));
		for (int j = 0; j < n; ++j) {
			w[j >= i ? j - i : i - j - 1].insert(v[j].begin(), v[j].end());
		}
		gao(w, s, done);
	}
}

int FoldThePaper::getValue(vector <string> paper) {
	vector<vector<int> > v;
	FOREACH (row, paper) {
		vector<int> w;
		istringstream iss(*row);
		int cell;
		while (iss >> cell) {
			w.push_back(cell);
		}
		v.push_back(w);
	}
	int r = v.size();
	int c = v[0].size();
	set<set<int> > sr, sc;
	vector<set<int> > vr(r), vc(c);
	FOR (i, r) vr[i].insert(i);
	FOR (i, c) vc[i].insert(i);
	set<vector<set<int> > > dummy;
	gao(vr, sr, dummy);
	dummy.clear();
	gao(vc, sc, dummy);
	int ret = v[0][0];
	FOREACH (mr, sr) {
		FOREACH (mc, sc) {
			int sum = 0;
			FOREACH (i, *mr) {
				FOREACH (j, *mc) {
					sum += v[*i][*j];
				}
			}
			ret = max(ret, sum);
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
        string paperARRAY[] = {
           "1 1 1",
           "1 1 1"
           };
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        FoldThePaper theObject;
        eq(0, theObject.getValue(paper),6);
    }
    {
        string paperARRAY[] = {
           "1 -1",
           "1 -1"
           };
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        FoldThePaper theObject;
        eq(1, theObject.getValue(paper),2);
    }
    {
        string paperARRAY[] = {
           "1 -1 -1 1",
           "-1 -1 -1 -1",
           "-1 -1 -1 -1",
           "1 -1 -1 1"
           };
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        FoldThePaper theObject;
        eq(2, theObject.getValue(paper),4);
    }
    {
        string paperARRAY[] = {
           "20 13 -2 100",
           "-12 0 4 -3",
           "4 1 -36 21"
           };
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        FoldThePaper theObject;
        eq(3, theObject.getValue(paper),131);
    }
    {
        string paperARRAY[] = {
           "0"
           };
        vector <string> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        FoldThePaper theObject;
        eq(4, theObject.getValue(paper),0);
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
