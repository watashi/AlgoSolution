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

struct TheBrickTowerHardDivOne {
	int find(int C, int K, long long H);
};

const int MAXN = 128;
const llint MOD = 1234567891LL;
const llint LIMIT = 6917529027641081856LL;

map<string, int> from, to;

void O(int n, int a[MAXN][MAXN]) {
    FOR (i, n) FOR (j, n) a[i][j] = 0LL;
}

void I(int n, int a[MAXN][MAXN]) {
    O(n, a);
    FOR (i, n) a[i][i] = 1LL;
}

void clone(int n, const int a[MAXN][MAXN], int b[MAXN][MAXN]) {
    FOR (i, n) FOR (j, n) b[i][j] = a[i][j];
}

void mul(int n, const int a[MAXN][MAXN], const int b[MAXN][MAXN], int ret[MAXN][MAXN]) {
    static int c[MAXN][MAXN];
    FOR (i, n) {
        FOR (j, n) {
            llint t = 0;
            FOR (k, n) {
                t += (llint)a[i][k] * b[k][j];
                if (t >= LIMIT) {
                    t %= MOD;
                }
            }
            c[i][j] = t % MOD;
        }
    }
    clone(n, c, ret);
}

void pow(int n, const int a[MAXN][MAXN], llint b, int ret[MAXN][MAXN]) {
    static int c[MAXN][MAXN];
    clone(n, a, c);
    I(n, ret);
    while (b > 0) {
        if (b & 1) {
            mul(n, ret, c, ret);
        }
        b >>= 1;
        mul(n, c, c, c);
    }
}

void gen(int len, char cur, string str) {
    if (len == 0) {
        from[str.substr(0, 4)];
        to[str];
    } else {
        for (char ch = 'A'; ch <= cur; ++ch) {
            gen(len - 1, ch == cur ? cur + 1 : cur, str + ch);
        }
    }
}

void label(map<string, int>& mp) {
    int id = 0;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        it->second = id++;
    }
}

string remap(string s) {
    map<char, char> mp;
    char cur = 'A';
    for (int i = 0; i < (int)s.length(); ++i) {
        if (mp.count(s[i]) == 0) {
            mp[s[i]] = cur;
            ++cur;
        }
        s[i] = mp[s[i]];
    }
    return s;
}

int same(string s) {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((i ^ j) != 3 && s[i] == s[j]) {
                ++ret;
            }
        }
    }
    return ret;
}

int a[MAXN][MAXN];
llint b[MAXN];

int TheBrickTowerHardDivOne::find(int C, int K, long long H) {
    gen(8, 'A', "");
    label(from);
    label(to);
    // printf("%d %d\n", (int)from.size(), (int)to.size());

    int S = from.size();
    fill(b, b + MAXN, 0LL);
    for (map<string, int>::const_iterator it = from.begin(); it != from.end(); ++it) {
        int c = *max_element(ALL(it->first)) - 'A' + 1;
        llint x = 1;
        FOR (i, c) {
            x *= (C - i);
        }
        int diff = same(it->first);
        if (diff <= K) {
            b[same(it->first) * S + it->second] = x % MOD;
        }
    }

    int N = (K + 1) * S + 1;
    O(N, a);
    for (map<string, int>::const_iterator it = to.begin(); it != to.end(); ++it) {
        int c = *max_element(it->first.begin(), it->first.begin() + 4) - 'A' + 1;
        int d = *max_element(ALL(it->first)) - 'A' + 1;
        llint x = 1;
        for (int i = c; i < d; ++i) {
            x *= (C - i);
        }
        int s = from[it->first.substr(0, 4)];
        string jt = remap(it->first.substr(4));
        int t = from[jt];
        int diff = same(jt);
        FOR (k, 4) {
            if (it->first[k] == it->first[k + 4]) {
                ++diff;
            }
        }
        for (int k = diff; k <= K; ++k) {
            int& y = a[k * S + t][(k - diff) * S + s];
            y = ((llint)y + x) % MOD;
        }
    }
    FOR (i, N) {
        a[N - 1][i] = 1LL;
    }
    pow(N, a, H, a);

    llint ans = 0;
    FOR (i, N) {
        ans = (ans + (llint)a[N - 1][i] * b[i]) % MOD;
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
        TheBrickTowerHardDivOne theObject;
        eq(0, theObject.find(2, 0, 2L),4);
    }
    {
        TheBrickTowerHardDivOne theObject;
        eq(1, theObject.find(1, 7, 19L),1);
    }
    {
        TheBrickTowerHardDivOne theObject;
        eq(2, theObject.find(2, 3, 1L),14);
    }
    {
        TheBrickTowerHardDivOne theObject;
        eq(3, theObject.find(4, 7, 47L),1008981254);
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

