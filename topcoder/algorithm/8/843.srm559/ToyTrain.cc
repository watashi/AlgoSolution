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

struct ToyTrain {
	int getMinCost(vector <string> field);
};

const int MAXN = 64;

bool mark[MAXN][MAXN];

int ToyTrain::getMinCost(vector <string> field) {
  int r = field.size();
  int c = field[0].size();
  bool empty = true;
  vector<pair<int, int> > byr[MAXN], byc[MAXN];
  FOR (i, r) {
    FOR (j, c) {
      if (field[i][j] == 'A' || field[i][j] == 'B') {
        byr[i].push_back(make_pair(i, j));
        byc[j].push_back(make_pair(i, j));
        empty = false;
      }
    }
  }
  if (empty) {
    return -1;
  }
  MEMSET(mark, 0);

  FOR (i, r) {
    if (byr[i].size() % 2 != 0) {
      return -1;
    }
    for (int j = 0; j < (int)byr[i].size(); j += 2) {
      int s = byr[i][j].second;
      int t = byr[i][j + 1].second;
      if (field[i][s] == field[i][t]) {
        return -1;
      }
      for (int k = s + 1; k < t; ++k) {
        if (mark[i][k]) {
          return -1;
        } else {
          mark[i][k] = true;
        }
      }
    }
  }

  FOR (i, c) {
    if (byc[i].size() % 2 != 0) {
      return -1;
    }
    for (int j = 0; j < (int)byc[i].size(); j += 2) {
      int s = byc[i][j].first;
      int t = byc[i][j + 1].first;
      if (field[s][i] == field[t][i]) {
        return -1;
      }
      for (int k = s + 1; k < t; ++k) {
        if (mark[k][i]) {
          return -1;
        } else {
          mark[k][i] = true;
        }
      }
    }
  }

  set<int> ans;
  FOR (i, r) {
    FOR (j, c) {
      if (mark[i][j]) {
        if (isdigit(field[i][j])) {
          ans.insert(field[i][j] - '0');
        }
      } else if (field[i][j] == 'S') {
        return -1;
      }
    }
  }

  int sum = 0;
  for (set<int>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
    sum += *it;
  }
  return sum;
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
        string fieldARRAY[] = {"BA",
            "SS",
            "AB"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(0, theObject.getMinCost(field),0);
    }
    {
        string fieldARRAY[] = {"."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(1, theObject.getMinCost(field),-1);
    }
    {
        string fieldARRAY[] = {"ABBA",
            "BAAB"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(2, theObject.getMinCost(field),0);
    }
    {
        string fieldARRAY[] = {"AA",
            "AA"}
           ;
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(3, theObject.getMinCost(field),-1);
    }
    {
        string fieldARRAY[] = {"..AB",
            "B..A",
            "....",
            "A.B."};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(4, theObject.getMinCost(field),-1);
    }
    {
        string fieldARRAY[] = {"A1B8A2B",
            "16A.B22",
            "BAB.9.A",
            "ABA.7.B",
            "B12345A"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(5, theObject.getMinCost(field),31);
    }
    {
        string fieldARRAY[] = {"..A.B",
            ".1.2.",
            "A.B..",
            ".3.4.",
            "B...A"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(6, theObject.getMinCost(field),0);
    }
    {
        string fieldARRAY[] = {"ASBSBSA",
            "S.S.S.S",
            "BSASASB"};
        vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
        ToyTrain theObject;
        eq(7, theObject.getMinCost(field),-1);
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

