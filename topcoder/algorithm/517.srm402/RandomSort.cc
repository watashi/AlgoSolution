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

struct RandomSort {
	double getExpected(vector <int> permutation);
};

map<vector<int>, double> dp;

double gao(vector<int>& v) {
	if (dp.count(v) > 0) {
		return dp[v];
	}
	int cnt = 0;
	double sum = 0;
	FOR(i, v.size()) {
		FOR(j, i) {
			if (v[i] < v[j]) {
				swap(v[i], v[j]);
				++cnt;
				sum += gao(v);
				swap(v[i], v[j]);
			}
		}
	}
	return dp[v] = 1 + sum / cnt;
}

double RandomSort::getExpected(vector <int> permutation) {
	vector<int> sorted;
	FOR(i, permutation.size()) {
		sorted.push_back(i + 1);
	}
	dp.clear();
	dp[sorted] = 0;
	return gao(permutation);
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
        int permutationARRAY[] = {1,3,2};
        vector <int> permutation( permutationARRAY, permutationARRAY+ARRSIZE(permutationARRAY) );
        RandomSort theObject;
        eq(0, theObject.getExpected(permutation),1.0);
    }
    {
        int permutationARRAY[] = {4,3,2,1};
        vector <int> permutation( permutationARRAY, permutationARRAY+ARRSIZE(permutationARRAY) );
        RandomSort theObject;
        eq(1, theObject.getExpected(permutation),4.066666666666666);
    }
    {
        int permutationARRAY[] = {1};
        vector <int> permutation( permutationARRAY, permutationARRAY+ARRSIZE(permutationARRAY) );
        RandomSort theObject;
        eq(2, theObject.getExpected(permutation),0.0);
    }
    {
        int permutationARRAY[] = {2,5,1,6,3,4};
        vector <int> permutation( permutationARRAY, permutationARRAY+ARRSIZE(permutationARRAY) );
        RandomSort theObject;
        eq(3, theObject.getExpected(permutation),5.666666666666666);
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
