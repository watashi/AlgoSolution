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
#define FOREACH(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
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

struct EllysReversals {
  int getMin(vector <string> words);
};

int EllysReversals::getMin(vector <string> w) {
  int n = w.size();
  map<vector<string>, int> mp;
  FOR (i, n) {
    vector<string> v;
    for (int j = 0; j + 2 <= (int)w[i].size(); j += 2) {
      v.push_back(w[i].substr(j, 2));
      sort(ALL(v.back()));
    }
    sort(ALL(v));
    if ((int)w[i].size() % 2 != 0) {
      v.push_back(w[i].substr(w[i].size() - 1));
    }
    ++mp[v];
  }
  int ans = 0;
  FOREACH (i, mp) {
    if (i->second % 2 != 0) {
      ++ans;
    }
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
        string wordsARRAY[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(0, theObject.getMin(words),3);
    }
    {
        string wordsARRAY[] = {"no", "zaphod", "just", "very", "improbable"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(1, theObject.getMin(words),5);
    }
    {
        string wordsARRAY[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(2, theObject.getMin(words),0);
    }
    {
        string wordsARRAY[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(3, theObject.getMin(words),1);
    }
    {
        string wordsARRAY[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
            "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
            "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
            "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
            "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
        vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
        EllysReversals theObject;
        eq(4, theObject.getMin(words),16);
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
