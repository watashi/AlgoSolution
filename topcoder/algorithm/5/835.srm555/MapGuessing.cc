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

struct MapGuessing {
	long long countPatterns(string goal, vector <string> code);
};

long long gao(vector<long long>::const_iterator begin,
              vector<long long>::const_iterator end,
              long long mask) {
    if (begin == end) {
        return 1LL << __builtin_popcountll(mask);
    } else if (mask == 0) {
        return 0;
    } else {
        return gao(begin + 1, end, mask) - gao(begin + 1, end, mask & *begin);
    }
}

long long MapGuessing::countPatterns(string goal, vector <string> code) {
    string p = "";
    for (int i = 0; i < (int)code.size(); ++i) {
        p += code[i];
    }
    vector<long long> v;
    for (int i = 0; i < (int)goal.length(); ++i) {
        long long mask = 0;
        string cur = goal;
        int pos = i;
        v.push_back(mask);
        for (int j = 0; j < (int)p.length(); ++j) {
            switch (p[j]) {
            case '<':
                --pos;
                break;
            case '>':
                ++pos;
                break;
            default:
                cur[pos] = p[j];
                mask |= 1LL << pos;
                break;
            }
            if (pos < 0 || pos >= (int)goal.length()) {
                v.pop_back();
                break;
            } else if (cur == goal) {
                v.back() = mask;
            }
        }
    }

    bool loop = true;
    while (loop) {
        loop = false;
        for (int i = 0; i < (int)v.size(); ++i) {
            for (int j = 0; j < (int)v.size(); ++j) {
                if (i != j && (v[i] & v[j]) == v[j]) {
                    v.erase(v.begin() + j);
                    goto NEXT;
                }
            }
        }
NEXT:
        continue;
    }

    for (int i = 0; i < (int)v.size(); ++i) {
    //    printf("%llx\n", v[i]);
    }
    int n = (int)goal.length();
    return (1LL << n) - gao(v.begin(), v.end(), (1LL << n) - 1);
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
        string codeARRAY[] = {"0"};
        vector <string> code( codeARRAY, codeARRAY+ARRSIZE(codeARRAY) );
        MapGuessing theObject;
        eq(0, theObject.countPatterns("000", code),4L);
    }
    {
        string codeARRAY[] = {"0>1"};
        vector <string> code( codeARRAY, codeARRAY+ARRSIZE(codeARRAY) );
        MapGuessing theObject;
        eq(1, theObject.countPatterns("001", code),5L);
    }
    {
        string codeARRAY[] = {"1>1>1"};
        vector <string> code( codeARRAY, codeARRAY+ARRSIZE(codeARRAY) );
        MapGuessing theObject;
        eq(2, theObject.countPatterns("000", code),1L);
    }
    {
        string codeARRAY[] = {">><<<<><<"};
        vector <string> code( codeARRAY, codeARRAY+ARRSIZE(codeARRAY) );
        MapGuessing theObject;
        eq(3, theObject.countPatterns("11001", code),0L);
    }
    {
        string codeARRAY[] = {"1<<0>>0>1"};
        vector <string> code( codeARRAY, codeARRAY+ARRSIZE(codeARRAY) );
        MapGuessing theObject;
        eq(4, theObject.countPatterns("1000101011", code),22L);
    }
    {
        string codeARRAY[] = {"><>>0<0<>>1>0><>", "<<0>>0<>><0>0>>><><", ">>>0<>", ">0><>>>>0<<><>>0>>>0<0>>0>"};
        vector <string> code( codeARRAY, codeARRAY+ARRSIZE(codeARRAY) );
        MapGuessing theObject;
        eq(5, theObject.countPatterns("00000010000000000000000000000000", code),13601L);
    }
    {
        string codeARRAY[] = {"11111111111111111111"
           ,"1<><><><><><><><><>1"
           ,"1<>000>000><0<><0<>1"
           ,"1<0<><>0><0<00>00<>1"
           ,"1<>00<>000><0<0<0<>1"
           ,"1<><>0>0><0<0<><0<>1"
           ,"1<000<>0><0<0<><0<>1"
           ,"1<><><><><><><><><>1"
           ,"1<>000><000<>000><>1"
           ,"1<>0><><0<><>0><><>1"
           ,"1<>000><000<>000><>1"
           ,"1<><>0><><0<><>0><>1"
           ,"1<>000><000<>000><>1"
           ,"1<><><><><><><><><>1"
           ,"11111111111111111111"};
        vector <string> code( codeARRAY, codeARRAY+ARRSIZE(codeARRAY) );
        MapGuessing theObject;
        eq(6, theObject.countPatterns("11100011010111111010100100110001101", code),90L);
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

