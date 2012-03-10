#include <algorithm>
#include <iostream>
#include <sstream>
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

struct DividingIntoTeams {
	string findYourTeam(vector <int> alexFriends, vector <int> bobFriends, vector <int> charlieFriends, int k);
};

string DividingIntoTeams::findYourTeam(vector <int> alexFriends, vector <int> bobFriends, vector <int> charlieFriends, int k) {
	set<int> s;
	vector<int> v[3];
	v[0].insert(v[0].end(), alexFriends.rbegin(), alexFriends.rend());
	v[1].insert(v[1].end(), bobFriends.rbegin(), bobFriends.rend());
	v[2].insert(v[2].end(), charlieFriends.rbegin(), charlieFriends.rend());
	string name[3] = {"Alex", "Bob", "Charlie"};
	while (true) {
		for (int i = 0; i < 3; ++i) {
			while (!v[i].empty() && s.count(v[i].back()) != 0) {
				v[i].pop_back();
			}
			if (!v[i].empty()) {
				s.insert(v[i].back());
				if (v[i].back() == k) {
					return name[i];
				}
				v[i].pop_back();
			}
		}
	}
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
        int alexFriendsARRAY[] = {1, 2, 3};
        vector <int> alexFriends( alexFriendsARRAY, alexFriendsARRAY+ARRSIZE(alexFriendsARRAY) );
        int bobFriendsARRAY[] = {1, 2, 3};
        vector <int> bobFriends( bobFriendsARRAY, bobFriendsARRAY+ARRSIZE(bobFriendsARRAY) );
        int charlieFriendsARRAY[] = {1, 2, 3};
        vector <int> charlieFriends( charlieFriendsARRAY, charlieFriendsARRAY+ARRSIZE(charlieFriendsARRAY) );
        DividingIntoTeams theObject;
        eq(0, theObject.findYourTeam(alexFriends, bobFriends, charlieFriends, 3),"Charlie");
    }
    {
        int alexFriendsARRAY[] = {1, 2, 3, 5, 4};
        vector <int> alexFriends( alexFriendsARRAY, alexFriendsARRAY+ARRSIZE(alexFriendsARRAY) );
        int bobFriendsARRAY[] = {3, 2, 1, 4, 5};
        vector <int> bobFriends( bobFriendsARRAY, bobFriendsARRAY+ARRSIZE(bobFriendsARRAY) );
        int charlieFriendsARRAY[] = {2, 1, 5, 3, 4};
        vector <int> charlieFriends( charlieFriendsARRAY, charlieFriendsARRAY+ARRSIZE(charlieFriendsARRAY) );
        DividingIntoTeams theObject;
        eq(1, theObject.findYourTeam(alexFriends, bobFriends, charlieFriends, 2),"Charlie");
    }
    {
        int alexFriendsARRAY[] = {1, 2, 3, 4, 5};
        vector <int> alexFriends( alexFriendsARRAY, alexFriendsARRAY+ARRSIZE(alexFriendsARRAY) );
        int bobFriendsARRAY[] = {1, 3, 5, 4, 2};
        vector <int> bobFriends( bobFriendsARRAY, bobFriendsARRAY+ARRSIZE(bobFriendsARRAY) );
        int charlieFriendsARRAY[] = {5, 4, 3, 2, 1};
        vector <int> charlieFriends( charlieFriendsARRAY, charlieFriendsARRAY+ARRSIZE(charlieFriendsARRAY) );
        DividingIntoTeams theObject;
        eq(2, theObject.findYourTeam(alexFriends, bobFriends, charlieFriends, 4),"Bob");
    }
    {
        int alexFriendsARRAY[] = {1};
        vector <int> alexFriends( alexFriendsARRAY, alexFriendsARRAY+ARRSIZE(alexFriendsARRAY) );
        int bobFriendsARRAY[] = {1};
        vector <int> bobFriends( bobFriendsARRAY, bobFriendsARRAY+ARRSIZE(bobFriendsARRAY) );
        int charlieFriendsARRAY[] = {1};
        vector <int> charlieFriends( charlieFriendsARRAY, charlieFriendsARRAY+ARRSIZE(charlieFriendsARRAY) );
        DividingIntoTeams theObject;
        eq(3, theObject.findYourTeam(alexFriends, bobFriends, charlieFriends, 1),"Alex");
    }
    {
        int alexFriendsARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector <int> alexFriends( alexFriendsARRAY, alexFriendsARRAY+ARRSIZE(alexFriendsARRAY) );
        int bobFriendsARRAY[] = {1, 8, 9, 4, 5, 6, 7, 3, 2, 10};
        vector <int> bobFriends( bobFriendsARRAY, bobFriendsARRAY+ARRSIZE(bobFriendsARRAY) );
        int charlieFriendsARRAY[] = {9, 10, 8, 4, 5, 7, 6, 1, 2, 3};
        vector <int> charlieFriends( charlieFriendsARRAY, charlieFriendsARRAY+ARRSIZE(charlieFriendsARRAY) );
        DividingIntoTeams theObject;
        eq(4, theObject.findYourTeam(alexFriends, bobFriends, charlieFriends, 4),"Bob");
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
