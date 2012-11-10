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

struct TheLuckySequence {
	int count(vector <int> numbers, int length);
};

const long long MOD = 1234567891;

struct Mat {
	long long a[2][2];
	Mat() { MEMSET(a, 0); }
};

Mat operator*(const Mat& lhs, const Mat& rhs) {
	Mat ret;
	FOR(k, 2) FOR(i, 2) FOR(j, 2) ret.a[i][j] = (ret.a[i][j] + lhs.a[i][k] * rhs.a[k][j]) % MOD;
	return ret;
}

Mat pow(Mat a, long long b) {
	Mat ret;
	ret.a[0][0] = ret.a[1][1] = 1;
	while (b > 0) {
		if (b & 1) {
			ret = ret * a;
		}
		a = a * a;
		b /= 2;
	}
	return ret;
}

int TheLuckySequence::count(vector <int> numbers, int length) {
	sort(numbers.begin(), numbers.end());
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
	Mat m;
	FOREACH (n, numbers) {
		char buf[80];
		sprintf(buf, "%d", *n);
		string str = buf;
		if (std::count(str.begin(), str.end(), '4') + std::count(str.begin(), str.end(), '7') == str.length()) {
			++m.a[*str.rbegin() == '4' ? 0 : 1][*str.begin() == '4' ? 0 : 1];
		}
	}
	m = pow(m, length);
	return (m.a[0][0] + m.a[0][1] + m.a[1][0] + m.a[1][1]) % MOD;
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
        int numbersARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        TheLuckySequence theObject;
        eq(0, theObject.count(numbers, 1),2);
    }
    {
        int numbersARRAY[] = {47, 74, 47};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        TheLuckySequence theObject;
        eq(1, theObject.count(numbers, 3),2);
    }
    {
        int numbersARRAY[] = {100, 4774, 200, 747, 300};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        TheLuckySequence theObject;
        eq(2, theObject.count(numbers, 47),2);
    }
    {
        int numbersARRAY[] = {44, 47, 74, 77};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        TheLuckySequence theObject;
        eq(3, theObject.count(numbers, 2),8);
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
