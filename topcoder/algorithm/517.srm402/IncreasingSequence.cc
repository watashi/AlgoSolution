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

struct IncreasingSequence {
	int getProduct(vector <string> digits);
};

const int MAXN = 2525;
const long long MOD = 1000000003;

int n;
string s;
int head[MAXN], prod[MAXN];
pair<int, int> dp[MAXN];

int lt(const pair<int, int>& lhs, const pair<int, int>& rhs) {
	if (lhs.second - lhs.first != rhs.second - rhs.first) {
		return lhs.second - lhs.first < rhs.second - rhs.first;
	}
	if (lhs != rhs) {
		for (int i = lhs.first, j = rhs.first; i < lhs.second; ++i, ++j) {
			if (s[i] != s[j]) {
				return s[i] < s[j];
			}
		}
	}
	return false;
}

long long value(const pair<int, int>& p) {
	long long ret = 0;
	for (int i = p.first; i < p.second; ++i) {
		ret = (ret * 10 + s[i] - '0') % MOD;
	}
	return ret;
}

int IncreasingSequence::getProduct(vector <string> digits) {
	s = "";
	FOREACH(d, digits) {
		s += *d;
	}
	n = s.length();
	head[n] = n;
	for (int i = n - 1; i >= 0; --i) {
		head[i] = (s[i] == '0') ? head[i + 1] : i;
	}

	pair<int, int> p;
	dp[0] = make_pair(0, 0);
	for (int i = 1; i <= n; ++i) {
	//	dp[i] = make_pair(0, n);
		for (int j = i - 1; j >= 0; --j) {
			p = make_pair(min(head[j], i - 1), i);
			if (lt(dp[j], p)) {
				dp[i] = p;
				break;
			}
		}
	}
	puts(s.substr(dp[n].first, string::npos).c_str());

	prod[n] = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (i > dp[n].first) {
			dp[i] = make_pair(i, i);
		} else if (head[i] >= dp[n].first) {
			dp[i] = make_pair(min(head[i], n - 1), n);
		} else {
			for (int j = n - 1; j > i; --j) {
				p = make_pair(min(head[i], j - 1), j);
				if (lt(p, dp[j])) {
					dp[i] = p;
					break;
				}
			}
		}
		prod[i] = value(dp[i]) * prod[dp[i].second] % MOD;
	}

	return prod[0];
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
        string digitsARRAY[] = {"12345"};
        vector <string> digits( digitsARRAY, digitsARRAY+ARRSIZE(digitsARRAY) );
        IncreasingSequence theObject;
        eq(0, theObject.getProduct(digits),120);
    }
    {
        string digitsARRAY[] = {"543210"};
        vector <string> digits( digitsARRAY, digitsARRAY+ARRSIZE(digitsARRAY) );
        IncreasingSequence theObject;
        eq(1, theObject.getProduct(digits),45150);
    }
    {
        string digitsARRAY[] = {"20210222"};
        vector <string> digits( digitsARRAY, digitsARRAY+ARRSIZE(digitsARRAY) );
        IncreasingSequence theObject;
        eq(2, theObject.getProduct(digits),932400);
    }
    {
        string digitsARRAY[] = {"1111111111"};
        vector <string> digits( digitsARRAY, digitsARRAY+ARRSIZE(digitsARRAY) );
        IncreasingSequence theObject;
        eq(3, theObject.getProduct(digits),1356531);
    }
    {
        string digitsARRAY[] = {"171829294246"};
        vector <string> digits( digitsARRAY, digitsARRAY+ARRSIZE(digitsARRAY) );
        IncreasingSequence theObject;
        eq(4, theObject.getProduct(digits),385769340);
    }
    {
        string digitsARRAY[] = {"3","235","236"};
        vector <string> digits( digitsARRAY, digitsARRAY+ARRSIZE(digitsARRAY) );
        IncreasingSequence theObject;
        eq(5, theObject.getProduct(digits),264320);
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
