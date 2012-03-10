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

struct TournamentSeeding {
	vector <string> getSeeds(vector <string> teams, vector <string> games, vector <int> seeds);
};
	
map<string, vector<string> > win;

bool pr(const string& lhs, const string& rhs) {
	return win[lhs].size() < win[rhs].size();
}

vector<string> gao(int n, int k, set<string> s) {
	if (k == n) {
		return vector<string>(s.begin(), s.end());
	}
	set<string> a, b;
	FOREACH (t, win) {
		if ((int)t->second.size() > k) {
			a.insert(t->first);
			b.insert(t->second[k]);
			if (s.erase(t->first) != 1 || s.erase(t->second[k]) != 1) {
				throw 1;	// WA12
			}
		}
	}

	int m = s.size() / 2;
	FOR (i, m) {
		a.insert(*s.begin());
		s.erase(s.begin());
	}
	FOR (i, m) {
		b.insert(*s.begin());
		s.erase(s.begin());
	}

	vector<string> u = gao(n, k + 1, a);
	vector<string> v(u.size());
	FOREACH (t, u) {
		if ((int)win[*t].size() > k) {
			v[t - u.begin()] = win[*t][k];
			b.erase(win[*t][k]);
		}
	}
	reverse(v.begin(), v.end());
	FOREACH (t, v) {
		if (*t == "") {
			*t = *b.begin();
			b.erase(b.begin());
		}
	}
	u.insert(u.end(), v.begin(), v.end());
	return u;
}

vector <string> TournamentSeeding::getSeeds(vector <string> _teams, vector <string> _games, vector <int> _seeds) {
	string str, str2;
	set<string> teams;
	win.clear();
	istringstream isst(accumulate(_teams.begin(), _teams.end(), string()));
	while (isst >> str) {
		teams.insert(str);
		win[str];
	}
	istringstream issg(accumulate(_games.begin(), _games.end(), string()));
	while (issg >> str >> str2) {
		win[str].push_back(str2);
	}

	int n = win.size();
	int m = __builtin_ctz(n);

	try {
		FOREACH (t, win) {
			sort(t->second.begin(), t->second.end(), pr);
			FOREACH (i, t->second) {
				if ((int)win[*i].size() != i - t->second.begin()) {
					throw 1;
				}
			}
		}
		vector<string> ret, tmp = gao(m, 0, teams);
		FOR (i, (int)_seeds.size()) {
			ret.push_back(tmp[_seeds[i]]);
		}
		return ret;
	} catch (...) {
		return vector<string>();
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
        string teamsARRAY[] = {"CELTICS ", "LAKER", "S SPURS PISTONS"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        string gamesARRAY[] = {"CELTICS LAKERS CELTICS PISTONS LAKERS SPURS"};
        vector <string> games( gamesARRAY, gamesARRAY+ARRSIZE(gamesARRAY) );
        int seedsARRAY[] = {0, 1, 2, 3};
        vector <int> seeds( seedsARRAY, seedsARRAY+ARRSIZE(seedsARRAY) );
        string retrunValueARRAY[] = {"CELTICS", "LAKERS", "SPURS", "PISTONS" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TournamentSeeding theObject;
        eq(0, theObject.getSeeds(teams, games, seeds),retrunValue);
    }
    {
        string teamsARRAY[] = {"GIANTS PATRIOTS CHARGERS PACKERS"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        string gamesARRAY[] = {"PATRIOTS CHARGERS"};
        vector <string> games( gamesARRAY, gamesARRAY+ARRSIZE(gamesARRAY) );
        int seedsARRAY[] = {3, 2, 1, 0};
        vector <int> seeds( seedsARRAY, seedsARRAY+ARRSIZE(seedsARRAY) );
        string retrunValueARRAY[] = {"PACKERS", "CHARGERS", "PATRIOTS", "GIANTS" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TournamentSeeding theObject;
        eq(1, theObject.getSeeds(teams, games, seeds),retrunValue);
    }
    {
        string teamsARRAY[] = {"REDSOX PHILLIES METS DODGER",
            "S ORIOLES BLUEJAYS CUBS AN",
            "GELS"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        string gamesARRAY[] = {"METS ANGELS",
            " METS CU",
            "BS ORIO",
            "LES ANGELS"};
        vector <string> games( gamesARRAY, gamesARRAY+ARRSIZE(gamesARRAY) );
        int seedsARRAY[] = {0, 1, 2, 3, 4, 5, 5, 5};
        vector <int> seeds( seedsARRAY, seedsARRAY+ARRSIZE(seedsARRAY) );
        TournamentSeeding theObject;
        eq(2, theObject.getSeeds(teams, games, seeds),vector <string>());
    }
    {
        string teamsARRAY[] = {"REDSOX PHILLIES METS DODGER",
            "S ORIOLES BLUEJAYS CUBS AN",
            "GELS"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        string gamesARRAY[] = {"METS ANGELS",
            " METS CU",
            "BS CU",
            "BS DODGERS REDSOX PHILLIES"};
        vector <string> games( gamesARRAY, gamesARRAY+ARRSIZE(gamesARRAY) );
        int seedsARRAY[] = {0, 1, 2, 3, 4, 5, 6, 7};
        vector <int> seeds( seedsARRAY, seedsARRAY+ARRSIZE(seedsARRAY) );
        string retrunValueARRAY[] = {"BLUEJAYS", "METS", "CUBS", "REDSOX", "PHILLIES", "DODGERS", "ANGELS", "ORIOLES" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TournamentSeeding theObject;
        eq(3, theObject.getSeeds(teams, games, seeds),retrunValue);
    }
    {
        string teamsARRAY[] = {"A B C D E F 8 H I 3 9 L 4 N O P"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        string gamesARRAY[] = {"P A B H D C D E E N"};
        vector <string> games( gamesARRAY, gamesARRAY+ARRSIZE(gamesARRAY) );
        int seedsARRAY[] = {0, 2, 0, 0, 3, 4, 7, 2};
        vector <int> seeds( seedsARRAY, seedsARRAY+ARRSIZE(seedsARRAY) );
        string retrunValueARRAY[] = {"3", "8", "3", "3", "D", "E", "P", "8" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TournamentSeeding theObject;
        eq(4, theObject.getSeeds(teams, games, seeds),retrunValue);
    }
    {
        string teamsARRAY[] = {"A B C D E F G H"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        string gamesARRAY[] = {"A B C D A C E F"};
        vector <string> games( gamesARRAY, gamesARRAY+ARRSIZE(gamesARRAY) );
        int seedsARRAY[] = {0, 1, 2, 3, 4, 5, 6, 7};
        vector <int> seeds( seedsARRAY, seedsARRAY+ARRSIZE(seedsARRAY) );
        string retrunValueARRAY[] = {"A", "E", "G", "C", "D", "H", "F", "B" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TournamentSeeding theObject;
        eq(5, theObject.getSeeds(teams, games, seeds),retrunValue);
    }
    {
        string teamsARRAY[] = {"NEWYORKISLANDERS"};
        vector <string> teams( teamsARRAY, teamsARRAY+ARRSIZE(teamsARRAY) );
        int seedsARRAY[] = {0};
        vector <int> seeds( seedsARRAY, seedsARRAY+ARRSIZE(seedsARRAY) );
        string retrunValueARRAY[] = {"NEWYORKISLANDERS" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TournamentSeeding theObject;
        eq(6, theObject.getSeeds(teams, vector <string>(), seeds),retrunValue);
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
