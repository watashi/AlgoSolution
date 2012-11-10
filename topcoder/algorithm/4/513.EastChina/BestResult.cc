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

struct BestResult {
	vector <int> findBestResult(vector <string> teams);
};

const int MAXN = 64;
int g[MAXN], s[MAXN], b[MAXN];

vector <int> BestResult::findBestResult(vector <string> teams) {
	int n = teams.size();
	for (int i = 0; i < n; ++i) {
		sscanf(teams[i].c_str(), "%d%d%d", &g[i], &s[i], &b[i]);
	}
	for (int i = 1; i < n; ++i) {
		g[i] -= g[0];
		s[i] -= s[0];
		b[i] -= b[0];
	}
	
	int ans = n;
	vector<int> gsb(3);
	for (int gg = 1; gg <= 1000; ++gg) {
		for (int ss = 1; ss <= gg; ++ss) {
			map<int, int> bb;
			bb[0] = 0;
			for (int i = 1; i < n; ++i) {
				int d = gg * g[i] + ss * s[i] + b[i];
				if (d > 0) {
					++bb[0];
				}
				if (b[i] > 0 && d <= 0) {
					++bb[-d / b[i] + 1];
				}
				if (b[i] < 0 && d > 0) {
					--bb[(d - 1) / -b[i] + 1];
				}
			}
			int pos = 0;
			for (map<int, int>::const_iterator it = bb.begin(); it != bb.end() && it->first < ss; ++it) {
				pos += it->second;
				if (pos < ans) {
					ans = pos;
					gsb[0] = gg;
					gsb[1] = ss;
					gsb[2] = it->first + 1;
				}
			}
		}
	}
	printf("ans = %d\n", ans);
	return gsb;
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
        string teamsARRAY[] = {"1 1 1", "0 1 2", "2 1 0"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {1, 1, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(0, theObject.findBestResult(teams),retrunValue);
    }
    {
        string teamsARRAY[] = {"0 0 0", "1 1 1"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {1, 1, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(1, theObject.findBestResult(teams),retrunValue);
    }
    {
        string teamsARRAY[] = {"0 1 2", "1 0 0", "0 0 4"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {2, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(2, theObject.findBestResult(teams),retrunValue);
    }
    {
        string teamsARRAY[] = {"0 3 0", "0 0 4", "3 0 0"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {2, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(3, theObject.findBestResult(teams),retrunValue);
    }
    {
        string teamsARRAY[] = {"24 0 0", "5 6 7", "5 45 5", "4 4 64"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {4, 1, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(4, theObject.findBestResult(teams),retrunValue);
    }
    {
        string teamsARRAY[] = { "1 2 0", "5 4 0", "3 0 1", "0 4 5", "2 3 4" };
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {7, 1, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(5, theObject.findBestResult(teams),retrunValue);
    }
    {
        string teamsARRAY[] = { "6 4 8", "2 0 4", "3 8 1", "0 6 5", "3 6 10", "5 6 7", "8 2 7" };
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {3, 2, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(6, theObject.findBestResult(teams),retrunValue);
    }
    {
        string teamsARRAY[] = { "7 8 5", "8 2 7", "3 10 0", "10 8 0", "5 2 7", "1 10 10", "9 7 1", "5 8 0" }
           ;
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int retrunValueARRAY[] = {3, 2, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BestResult theObject;
        eq(7, theObject.findBestResult(teams),retrunValue);
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
