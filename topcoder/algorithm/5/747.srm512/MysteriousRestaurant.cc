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

struct MysteriousRestaurant {
	int maxDays(vector <string> prices, int budget);
};

const int MAXN = 64;
int a[MAXN][MAXN];

int MysteriousRestaurant::maxDays(vector <string> prices, int budget) {
	int n = prices.size();
	int m = prices[0].length();
	FOR (i, n) {
		FOR (j, m) {
			if (isdigit(prices[i][j])) {
				a[i][j] = prices[i][j] - '0';
			} else if (isupper(prices[i][j])) {
				a[i][j] = 10 + prices[i][j] - 'A';
			} else {
				a[i][j] = 36 + prices[i][j] - 'a';
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		vector<vector<int> > b(7, vector<int>(m, 0));
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < m; ++k) {
				b[j % 7][k] += a[j][k];
			}
		}
		int s = 0;
		for (int j = 0; j < 7; ++j) {
			s += *min_element(b[j].begin(), b[j].end());
		}
		if (s <= budget) {
			ret = i;
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
        string pricesARRAY[] = {"26", "14", "72", "39", "32", "85", "06"};
        vector <string> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        MysteriousRestaurant theObject;
        eq(0, theObject.maxDays(prices, 13),5);
    }
    {
        string pricesARRAY[] = {"26", "14", "72", "39", "32", "85", "06", "91"};
        vector <string> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        MysteriousRestaurant theObject;
        eq(1, theObject.maxDays(prices, 20),8);
    }
    {
        string pricesARRAY[] = {"SRM", "512"};
        vector <string> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        MysteriousRestaurant theObject;
        eq(2, theObject.maxDays(prices, 4),0);
    }
    {
        string pricesARRAY[] = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
        vector <string> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        MysteriousRestaurant theObject;
        eq(3, theObject.maxDays(prices, 256),10);
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
