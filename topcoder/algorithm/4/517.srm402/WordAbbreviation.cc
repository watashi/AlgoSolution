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

struct WordAbbreviation {
	vector <string> getAbbreviations(vector <string> words);
};

vector <string> WordAbbreviation::getAbbreviations(vector <string> words) {
	map<string, int> mp;
	mp[""] = 1;
	FOREACH(w, words) {
		FOR(i, w->length() + 1) {
			++mp[w->substr(0, i)];
		}
	}
	vector<string> v;
	FOREACH(w, words) {
		FOR(i, w->length() + 1) {
			if (mp[w->substr(0, i)] == 1) {
				v.push_back(w->substr(0, i));
				break;
			}
		}
	}
	return v;
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
        string wordsARRAY[] = {"abc","def","ghi"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        string retrunValueARRAY[] = {"a", "d", "g" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        WordAbbreviation theObject;
        eq(0, theObject.getAbbreviations(words),retrunValue);
    }
    {
        string wordsARRAY[] = {"aaab","aaac","aaad"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        string retrunValueARRAY[] = {"aaab", "aaac", "aaad" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        WordAbbreviation theObject;
        eq(1, theObject.getAbbreviations(words),retrunValue);
    }
    {
        string wordsARRAY[] = {"top","coder","contest"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        string retrunValueARRAY[] = {"t", "cod", "con" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        WordAbbreviation theObject;
        eq(2, theObject.getAbbreviations(words),retrunValue);
    }
    {
        string wordsARRAY[] = {
            "bababaaaaa",
            "baaabaababa",
            "bbabaaabbaaabbabaabaabbbbbaabb",
            "aaababababbbbababbbaabaaaaaaaabbabbbaaab",
            "baaaaabaababbbaabbbabbababbbabbbbbbbbab"
           };
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        string retrunValueARRAY[] = {"bab", "baaab", "bb", "a", "baaaa" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        WordAbbreviation theObject;
        eq(3, theObject.getAbbreviations(words),retrunValue);
    }
    {
        string wordsARRAY[] = {"oneword"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        string retrunValueARRAY[] = {"o" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        WordAbbreviation theObject;
        eq(4, theObject.getAbbreviations(words),retrunValue);
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
