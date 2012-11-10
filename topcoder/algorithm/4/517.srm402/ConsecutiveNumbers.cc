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

struct ConsecutiveNumbers {
	vector <int> missingNumber(vector <int> numbers);
};

vector <int> ConsecutiveNumbers::missingNumber(vector <int> numbers) {
	vector<int> ret;
	sort(numbers.begin(), numbers.end());
	if (unique(numbers.begin(), numbers.end()) != numbers.end()) {
	} else if (numbers.back() - numbers.front() == numbers.size() - 1) {
		if (numbers.front() > 1) {
			ret.push_back(numbers.front() - 1);
		}
		ret.push_back(numbers.back() + 1);
	} else if (numbers.back() - numbers.front() == numbers.size()) {
		for (int i = 1; i < (int)numbers.size(); ++i) {
			if (numbers[i] - numbers[i - 1] == 2) {
				ret.push_back(numbers[i] - 1);
			}
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
        int numbersARRAY[] = {10,7,12,8,11};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {9 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConsecutiveNumbers theObject;
        eq(0, theObject.missingNumber(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = {3,6};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        ConsecutiveNumbers theObject;
        eq(1, theObject.missingNumber(numbers),vector <int>());
    }
    {
        int numbersARRAY[] = {5,6,7,8};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {4, 9 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConsecutiveNumbers theObject;
        eq(2, theObject.missingNumber(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = {1000000000};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {999999999, 1000000001 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConsecutiveNumbers theObject;
        eq(3, theObject.missingNumber(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = {1,6,9,3,8,12,7,4,11,5,10};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConsecutiveNumbers theObject;
        eq(4, theObject.missingNumber(numbers),retrunValue);
    }
    {
        int numbersARRAY[] = {1};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        int retrunValueARRAY[] = {2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ConsecutiveNumbers theObject;
        eq(5, theObject.missingNumber(numbers),retrunValue);
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
