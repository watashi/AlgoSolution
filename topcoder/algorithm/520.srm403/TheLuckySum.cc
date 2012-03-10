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

struct TheLuckySum {
	vector <int> sum(int n);
};

const int LIMIT = 1000000000;

vector<long long> cur, ans;

void gao(long long rem, long long ten, int tot) {
//	int dummy;
//	printf("[%p] > %lld, %lld, %d\n", &dummy, rem, ten, tot);
	if (!ans.empty() && cur >= ans) {
		return;
	}
	if (rem == 0) {
		ans = cur;
		return;
	}
	for (int i = 0, sum = 4 * tot; i <= tot && sum <= rem; ++i, sum += 3) {
		if (i > 0) {
			cur[cur.size() - i] += 3 * ten;
		}
		if (sum % 10 == rem % 10) {
			for (int j = 0; j <= tot; ++j) {
				if (j > 0) {
					cur[cur.size() - j] += 4 * ten * 10;
				}
				gao((rem - sum) / 10, ten * 10, j);
			}
			for (int j = 1; j <= tot; ++j) {
				cur[cur.size() - j] -= 4 * ten * 10;
			}
		}
	}
	for (int i = 1, sum = 4 * tot + 3; i <= tot && sum <= rem; ++i, sum += 3) {
		cur[cur.size() - i] -= 3 * ten;
	}
}

// 313.27pt (2y, 1resubmit/1wa for long long)
vector <int> TheLuckySum::sum(int n) {
	ans.clear();
	for (int i = 1; ans.empty() && i < 100; ++i) {
		vector<long long>(i, 4).swap(cur);
		gao(n, 1, i);
	}
	return vector<int>(ans.begin(), ans.end());
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
        int retrunValueARRAY[] = {4, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheLuckySum theObject;
        eq(0, theObject.sum(11),retrunValue);
    }
    {
        int retrunValueARRAY[] = {4, 4, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheLuckySum theObject;
        eq(1, theObject.sum(12),retrunValue);
    }
    {
        TheLuckySum theObject;
        eq(2, theObject.sum(13),vector <int>());
    }
    {
        int retrunValueARRAY[] = {4, 4, 4, 44, 44 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TheLuckySum theObject;
        eq(3, theObject.sum(100),retrunValue);
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
