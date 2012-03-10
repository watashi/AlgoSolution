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

struct RoadReform {
	int findMaxDeadendCount(vector <string> roads);
};

const int MAXN = 16;
bool e[MAXN][MAXN];
bool dp[1 << MAXN];

int RoadReform::findMaxDeadendCount(vector <string> roads) {
	int n = roads.size();
	int ans = n == 2 ? n : 0;
	FOR(i, n) FOR(j, n) e[i][j] = roads[i][j] == '1';
	fill(dp, dp + (1 << n), false);
	FOR(i, n) dp[1 << i] = true;
	FOR(i, (1 << n)) {
		if (!dp[i]) continue;
		int ii = i;
		FOR(j, n) {
			if (i & (1 << j)) continue;
			FOR(k, n) {
				if (e[j][k] && (i & (1 << k))) {
					dp[i ^ (1 << j)] = true;
					ii ^= (1 << j);
					break;
				}
			}
		}
		if (ii == (1 << n) - 1) ans = max(ans, n - __builtin_popcount(i));
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
        string roadsARRAY[] = {"01",
            "10"};
        vector <string> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        RoadReform theObject;
        eq(0, theObject.findMaxDeadendCount(roads),2);
    }
    {
        string roadsARRAY[] = {"01000", 
            "10100",
            "01010",
            "00101",
            "00010"};
        vector <string> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        RoadReform theObject;
        eq(1, theObject.findMaxDeadendCount(roads),2);
    }
    {
        string roadsARRAY[] = {"01111",
            "10000",
            "10000",
            "10000",
            "10000"};
        vector <string> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        RoadReform theObject;
        eq(2, theObject.findMaxDeadendCount(roads),4);
    }
    {
        string roadsARRAY[] = {"0111",
            "1011",
            "1101",
            "1110"};
        vector <string> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        RoadReform theObject;
        eq(3, theObject.findMaxDeadendCount(roads),3);
    }
    {
        string roadsARRAY[] = {"0100000001",
            "1010000000",
            "0101000000",
            "0010100000",
            "0001010000",
            "0000101000",
            "0000010100",
            "0000001010",
            "0000000101",
            "1000000010"};
        vector <string> roads( roadsARRAY, roadsARRAY+ARRSIZE(roadsARRAY) );
        RoadReform theObject;
        eq(4, theObject.findMaxDeadendCount(roads),2);
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
