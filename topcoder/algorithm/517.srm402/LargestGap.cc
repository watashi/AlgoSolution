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

struct LargestGap {
	int getLargest(vector <string> board);
};

int LargestGap::getLargest(vector <string> board) {
	string s = "";
	FOREACH(b, board) {
		s += *b;
	}
	
	int n = s.length();
	vector<pair<int, int> > v;
	FOR(i, n) {
		if (s[i] == 'X' && s[(i + n - 1) % n] == '.') {
			v.push_back(make_pair(i, 0));
			for (int j = i; s[j] == 'X'; j = (j + 1) % n) {
				v.back().first = min(v.back().first, j);
			}
			for (int j = (i + n - 1) % n; s[j] == '.'; j = (j + n - 1) % n) {
				++v.back().second;
			}
		}
	}
	sort(v.begin(), v.end());

	int m = v.size();
	int sum = 0, big = 0, pos = 0;
	v.push_back(v.front());
	for (int i = 0; i < m; ++i) {
		if (v[i].second + v[i + 1].second > sum ||
			((v[i].second + v[i + 1].second == sum) && max(v[i].second, v[i + 1].second) < big)) {
			sum = v[i].second + v[i + 1].second;
			big = max(v[i].second, v[i + 1].second);
			pos = v[i].first;
		}
	}
	return pos;
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
        string boardARRAY[] = {".....X.X......."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LargestGap theObject;
        eq(0, theObject.getLargest(board),5);
    }
    {
        string boardARRAY[] = {"XXXX","....","XXXX","....","XXXX","...."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LargestGap theObject;
        eq(1, theObject.getLargest(board),0);
    }
    {
        string boardARRAY[] = {"XXX.........XX...........XX..X"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LargestGap theObject;
        eq(2, theObject.getLargest(board),12);
    }
    {
        string boardARRAY[] = {"XXX","X.....","....XX..XXXXXX","X........X..",".XXX."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        LargestGap theObject;
        eq(3, theObject.getLargest(board),32);
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
