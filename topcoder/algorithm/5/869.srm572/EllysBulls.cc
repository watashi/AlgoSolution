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
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct EllysBulls {
  string getNumber(vector <string> guesses, vector <int> bulls);
};

const int TEN[6] = {
  1,
  10,
  100,
  1000,
  10000,
  100000
};

map<vector<int>, string> gao(vector<string> v) {
  int n = v.size();
  int m = v[0].size();
  static char buf[10];
  vector<int> a(n);
  map<vector<int>, string> ret;

  fill(buf, buf + m, '0');
  buf[m] = '\0';
  FOR (i, TEN[m]) {
    FOR (j, n) {
      a[j] = 0;
      FOR (k, m) {
        if (buf[k] == v[j][k]) {
          ++a[j];
        }
      }
    }
    if (ret.count(a) == 0) {
      ret[a] = buf;
    } else {
      ret[a] = "*";
    }
    for (int j = m - 1; j >= 0; --j) {
      if (buf[j] == '9') {
        buf[j] = '0';
      } else {
        ++buf[j];
        break;
      }
    }
  }

  return ret;
}

string EllysBulls::getNumber(vector <string> g, vector <int> t) {
  int n = g.size();
  int m = g[0].size() / 2;
  vector<string> a, b;
  FOR (i, n) {
    a.push_back(g[i].substr(0, m));
    b.push_back(g[i].substr(m));
  }
  map<vector<int>, string> x = gao(a), y = gao(b);
  string ans = "Liar";
  for (map<vector<int>, string>::const_iterator i = x.begin(); i != x.end(); ++i) {
    // printf("%s\n", i->second.c_str());
    vector<int> v = i->first;
    FOR (j, n) {
      v[j] = t[j] - v[j];
    }
    if (y.count(v) > 0) {
      if (ans == "Liar") {
        ans = i->second + y[v];
      } else {
        ans = "*";
        break;
      }
    }
  }
  // if (ans[0] == '*') { // =____________________________=b
  if (ans.find('*') != string::npos) {
    ans = "Ambiguity";
  }
  return ans;
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

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        string guessesARRAY[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int bullsARRAY[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
        vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
        EllysBulls theObject;
        eq(0, theObject.getNumber(guesses, bulls),"1337");
    }
    {
        string guessesARRAY[] = {"0000", "1111", "2222"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int bullsARRAY[] = {2, 2, 2};
        vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
        EllysBulls theObject;
        eq(1, theObject.getNumber(guesses, bulls),"Liar");
    }
    {
        string guessesARRAY[] = {"666666", "666677", "777777", "999999"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int bullsARRAY[] = {2, 3, 1, 0};
        vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
        EllysBulls theObject;
        eq(2, theObject.getNumber(guesses, bulls),"Ambiguity");
    }
    {
        string guessesARRAY[] = {"000", "987", "654", "321", "100", "010"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int bullsARRAY[] = {2, 1, 0, 0, 1, 1};
        vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
        EllysBulls theObject;
        eq(3, theObject.getNumber(guesses, bulls),"007");
    }
    {
        string guessesARRAY[] = {"28", "92", "70", "30", "67", "63", "06", "65",
            "11", "06", "88", "48", "09", "65", "48", "08"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int bullsARRAY[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
        EllysBulls theObject;
        eq(4, theObject.getNumber(guesses, bulls),"54");
    }
    {
        string guessesARRAY[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
            "4166623", "1166638", "2767693", "8650248", "2486509",
            "6138934", "4018642", "6236742", "2961643", "8407361",
            "2097376", "6575410", "6071777", "3569948", "2606380"};
        vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int bullsARRAY[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
        vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
        EllysBulls theObject;
        eq(5, theObject.getNumber(guesses, bulls),"4266642");
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
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
