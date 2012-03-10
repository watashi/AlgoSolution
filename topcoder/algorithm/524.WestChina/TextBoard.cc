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

struct TextBoard {
	vector <string> draw(vector <string> pieces);
};

vector <string> TextBoard::draw(vector <string> pieces) {
	vector<string> ret(8, "........");
	FOR (i, 8) {
		FOR (j, 8) {
			ret[i][j] = (i + j) % 2 == 0 ? '#' : '.';
		}
	}
	char buf[80], col;
	int row;
	FOREACH (it, pieces) {
		sscanf(it->c_str(), "%s %c%d", buf, &col, &row);
		ret[row - 1][col - 'A'] = buf[0];
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
        string piecesARRAY[] = {"WHITE B2", "BLACK A3"};
        vector <string> pieces( piecesARRAY, piecesARRAY+ARRSIZE(piecesARRAY) );
        string retrunValueARRAY[] = {"#.#.#.#.", ".W.#.#.#", "B.#.#.#.", ".#.#.#.#", "#.#.#.#.", ".#.#.#.#", "#.#.#.#.", ".#.#.#.#" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TextBoard theObject;
        eq(0, theObject.draw(pieces),retrunValue);
    }
    {
        string piecesARRAY[] = {"BLACK A1", "BLACK C1", "BLACK E1", "BLACK G1", "BLACK B2", "BLACK D2",
            "BLACK F2", "BLACK H2", "BLACK A3", "BLACK C3", "BLACK E3", "BLACK G3",
            "WHITE B6", "WHITE D6", "WHITE F6", "WHITE H6", "WHITE A7", "WHITE C7",
            "WHITE E7", "WHITE G7", "WHITE B8", "WHITE D8", "WHITE F8", "WHITE H8"};
        vector <string> pieces( piecesARRAY, piecesARRAY+ARRSIZE(piecesARRAY) );
        string retrunValueARRAY[] = {"B.B.B.B.", ".B.B.B.B", "B.B.B.B.", ".#.#.#.#", "#.#.#.#.", ".W.W.W.W", "W.W.W.W.", ".W.W.W.W" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TextBoard theObject;
        eq(1, theObject.draw(pieces),retrunValue);
    }
    {
        string piecesARRAY[] = {"BLACK A1", "BLACK A2", "BLACK A3", "BLACK A4", "BLACK A5", "BLACK A6",
            "BLACK A7", "BLACK A8", "BLACK B1", "WHITE B2", "WHITE B3", "WHITE B4",
            "WHITE B5", "WHITE B6", "WHITE B7", "BLACK B8", "BLACK C1", "WHITE C2",
            "WHITE C7", "BLACK C8", "BLACK D1", "WHITE D2", "WHITE D7", "BLACK D8",
            "BLACK E1", "WHITE E2", "WHITE E7", "BLACK E8", "BLACK F1", "WHITE F2",
            "WHITE F7", "BLACK F8", "BLACK G1", "WHITE G2", "WHITE G3", "WHITE G4",
            "WHITE G5", "WHITE G6", "WHITE G7", "BLACK G8", "BLACK H1", "BLACK H2",
            "BLACK H3", "BLACK H4", "BLACK H5", "BLACK H6", "BLACK H7", "BLACK H8"};
        vector <string> pieces( piecesARRAY, piecesARRAY+ARRSIZE(piecesARRAY) );
        string retrunValueARRAY[] = {"BBBBBBBB", "BWWWWWWB", "BW#.#.WB", "BW.#.#WB", "BW#.#.WB", "BW.#.#WB", "BWWWWWWB", "BBBBBBBB" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TextBoard theObject;
        eq(2, theObject.draw(pieces),retrunValue);
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
