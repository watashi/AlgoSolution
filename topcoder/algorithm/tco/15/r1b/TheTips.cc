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
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef int64_t LL;
typedef pair<int, int> PII;
const int E9 = 1000000000;
/// BEGIN CUT HERE
// <errf>
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  for (const auto& i: v) {
    errf(fmt, i);
  }
  errf("}\n");
}
// </errf>
/// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct TheTips {
  double solve(vector <string> clues, vector <int> probability);
};

const int MAXN = 64;
bool e[MAXN][MAXN];

double TheTips::solve(vector <string> clues, vector <int> probability) {
  int n = clues.size();
  vector<long double> p(n);
  FOR (i, n) {
    FOR (j, n) {
      e[i][j] = clues[i][j] == 'Y';
    }
    e[i][i] = true;
    p[i] = probability[i] / 100.0;
  }
  FOR (k, n) {
    FOR (i, n) {
      FOR (j, n) {
        e[i][j] = e[i][j] || (e[i][k] && e[k][j]);
      }
    }
  }
  long double ans = 0;
  FOR (i, n) {
    long double q = 1.0;
    FOR (j, n) {
      if (e[j][i]) {
        q *= 1.0 - p[j];
      }
    }
    errf("[%d] = %Lf\n", i, q);
    ans += 1.0 - q;
  }
  return (double)ans;
}

/// BEGIN CUT HERE
// <main>
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
        string cluesARRAY[] = {"Y"};
        vector <string> clues( cluesARRAY, cluesARRAY+ARRSIZE(cluesARRAY) );
        int probabilityARRAY[] = {50};
        vector <int> probability( probabilityARRAY, probabilityARRAY+ARRSIZE(probabilityARRAY) );
        TheTips theObject;
        eq(0, theObject.solve(clues, probability),0.5);
    }
    {
        string cluesARRAY[] = {"YN","NY"};
        vector <string> clues( cluesARRAY, cluesARRAY+ARRSIZE(cluesARRAY) );
        int probabilityARRAY[] = {100,50};
        vector <int> probability( probabilityARRAY, probabilityARRAY+ARRSIZE(probabilityARRAY) );
        TheTips theObject;
        eq(1, theObject.solve(clues, probability),1.5);
    }
    {
        string cluesARRAY[] = {"YYY","NYY","NNY"};
        vector <string> clues( cluesARRAY, cluesARRAY+ARRSIZE(cluesARRAY) );
        int probabilityARRAY[] = {100,0,0};
        vector <int> probability( probabilityARRAY, probabilityARRAY+ARRSIZE(probabilityARRAY) );
        TheTips theObject;
        eq(2, theObject.solve(clues, probability),3.0);
    }
    {
        string cluesARRAY[] = {"NNN","NNN","NNN"};
        vector <string> clues( cluesARRAY, cluesARRAY+ARRSIZE(cluesARRAY) );
        int probabilityARRAY[] = {0,0,0};
        vector <int> probability( probabilityARRAY, probabilityARRAY+ARRSIZE(probabilityARRAY) );
        TheTips theObject;
        eq(3, theObject.solve(clues, probability),0.0);
    }
    {
        string cluesARRAY[] = {"NYYNYYNNNN","NNNNYNNNYN","YNNYYYYYNN","YYNYNNNNYN","NYNNNNNNNY","YNYYNNYNNY","NYNNYYYYYY","NYYYYNNNNN","YYNYNNYYYN","NNYYNYNYYY"}
           ;
        vector <string> clues( cluesARRAY, cluesARRAY+ARRSIZE(cluesARRAY) );
        int probabilityARRAY[] = {11,66,99,37,64,45,21,67,71,62}
           ;
        vector <int> probability( probabilityARRAY, probabilityARRAY+ARRSIZE(probabilityARRAY) );
        TheTips theObject;
        eq(4, theObject.solve(clues, probability),9.999891558057332);
    }
    {
        string cluesARRAY[] = {"NNY","NNY","NNN"};
        vector <string> clues( cluesARRAY, cluesARRAY+ARRSIZE(cluesARRAY) );
        int probabilityARRAY[] = {50, 50, 1};
        vector <int> probability( probabilityARRAY, probabilityARRAY+ARRSIZE(probabilityARRAY) );
        TheTips theObject;
        eq(5, theObject.solve(clues, probability),1.7525);
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
 * __builtin_popcount __builtin_ctz
 * make_pair first second
 * iterator const_iterator
 * priority_queue
 * push_back
 */
/*
 * vim: ft=cpp.doxygen
 */
// </main>
/// END CUT HERE
