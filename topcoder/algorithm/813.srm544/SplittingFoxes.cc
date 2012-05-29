#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
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

struct SplittingFoxes {
	int sum(long long n, int S, int L, int R);
};

const llint MOD = 1000000007LL;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int left(int i) {
    return (i + 1) & 3;
}

int right(int i) {
    return (i + 3) & 3;
}

struct Rec {
    llint s[4];
    llint sx[4];
    llint sy[4];
    llint sxy[4];

    void init() {
        fill(s, s + 4, 0);
        fill(sx, sx + 4, 0);
        fill(sy, sy + 4, 0);
        fill(sxy, sxy + 4, 0);
    }

    void dump(const char* p) {
        puts(p);
        for (int i = 0; i < 4; ++i) {
            printf("[%d] %lld +%lld +%lld *%lld\n", i, s[i], sx[i], sy[i], sxy[i]);
        }
    }
};

Rec operator*(Rec lhs, Rec rhs) {
    Rec ret;
    ret.init();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int k = (i + j) & 3;
            llint n = lhs.s[i];
            llint m = rhs.s[j];
            ret.s[k] = (ret.s[k] + n * m) % MOD;
            ret.sx[k] = (ret.sx[k] + lhs.sx[i] * m + rhs.sx[j] * n) % MOD;
            ret.sy[k] = (ret.sy[k] + lhs.sy[i] * m + rhs.sy[j] * n) % MOD;
            ret.sxy[k] = (ret.sxy[k] + lhs.sxy[i] * m + rhs.sxy[j] * n) % MOD;
            ret.sxy[k] = (ret.sxy[k] + lhs.sx[i] * rhs.sy[j]) % MOD;
            ret.sxy[k] = (ret.sxy[k] + lhs.sy[i] * rhs.sx[j]) % MOD;
        }
        for (int j = 0; j < 4; ++j) {
            swap(rhs.sx[j], rhs.sy[j]);
            rhs.sx[j] = -rhs.sx[j];
            rhs.sxy[j] = -rhs.sxy[j];
        }
    }
    return ret;
}

int SplittingFoxes::sum(long long n, int S, int L, int R) {
    Rec a, b;
    a.init();
    a.s[0] = S;
    a.s[1] = L;
    a.s[3] = R;
    a.sx[0] = S;
    b.init();
    b.s[0] = 1;
    // a.dump("a");
    // b.dump("b");
    while (n > 0) {
        if (n & 1) {
            b = b * a;
        }
        n >>= 1;
        a = a * a;
    }
    llint ret = 0;
    // b.dump("ans");
    for (int i = 0; i < 4; ++i) {
        ret += b.sxy[i];
    }
    ret = (ret % MOD + MOD) % MOD;
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
        SplittingFoxes theObject;
        eq(0, theObject.sum(58L, 2, 0, 0),0);
    }
    {
        SplittingFoxes theObject;
        eq(1, theObject.sum(3L, 1, 1, 0),1);
    }
    {
        SplittingFoxes theObject;
        eq(2, theObject.sum(5L, 1, 3, 2),34);
    }
    {
        SplittingFoxes theObject;
        eq(3, theObject.sum(5L, 1, 2, 3),999999973);
    }
    {
        SplittingFoxes theObject;
        eq(4, theObject.sum(123456789L, 987654321, 544, 544),0);
    }
    {
        SplittingFoxes theObject;
        eq(5, theObject.sum(65536L, 1024, 512, 4096),371473914);
    }

	puts("\033[1;33mPress any key to continue...\033[0m");
	getchar();

	return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE

