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

struct PickAndDelete {
	int count(vector <string> S);
};

long long MOD = 1000000007LL;

/*
long long pow(long long a, long long b) {
	long long c = 1LL;
	while (b > 0) {
		if (b & 1) {
			c = c * a % MOD;
		}
		b >>= 1;
		a = a * a % MOD;
	}
	return c;
}
*/

const int MAXN = 218;
long long pp[MAXN];
long long c[MAXN][MAXN];

int PickAndDelete::count(vector <string> S) {
	string s;
	for (int i = 0; i < (int)S.size(); ++i) {
		s += S[i];
	}
	istringstream iss(s);
	long long a;
	int n = 0;
	map<long long, long long> mp;
	while (iss >> a) {
		++mp[a];
		++n;
	}

	for (int i = 0; i <= n; ++i) {
		c[i][0] = 1LL;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}

	vector<long long> dp(n + 1, 0);
	dp[0] = 1;
	long long last = 0;
	int m = 0;
	for (map<long long, long long>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
		vector<long long> tmp(n + 1, 0);
		m  += it->second;
		pp[0] = 1LL;
		for (int i = 1; i <= n; ++i) {
			pp[i] = pp[i - 1] * (it->first - last) % MOD;
		}
		for (int i = m; i <= n; ++i) {
			for (int j = 0; j <= i; ++j) {
				long long x = pp[i - j] * c[n - j][i - j] % MOD;
				tmp[i] += dp[j] * x % MOD;
			}
		}
		for (int i = 0; i <= n; ++i) {
			dp[i] = tmp[i] % MOD;
		}
		last = it->first;
	}
	return (int)(dp[n] % MOD);
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
        string SARRAY[] = {"1 2"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        PickAndDelete theObject;
        eq(0, theObject.count(S),3);
    }
    {
        string SARRAY[] = {"2 2 2 2 2 2 2 2 2"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        PickAndDelete theObject;
        eq(1, theObject.count(S),512);
    }
    {
        string SARRAY[] = {"5", " 1 ", "2"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        PickAndDelete theObject;
        eq(2, theObject.count(S),34);
    }
    {
        string SARRAY[] = {"3 ", "14159 265", "3589 7", " 932"};
        vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        PickAndDelete theObject;
        eq(3, theObject.count(S),353127147);
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
