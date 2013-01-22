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

struct Mountains {
  int countPlacements(vector <int> heights, vector <string> visibility);
};

typedef pair<int, int> PII;
const int MAXN = 16;
const llint MOD = 1000000009;

int n, m;
int l[MAXN], r[MAXN], y[MAXN];
map<vector<int>, llint> dp[MAXN];

inline int height(int x, int y, int xx) {
  return max(0, y - abs(x - xx));
}

llint gao(int k, const vector<int>& h) {
  if (k < 0) {
    return 1LL;
  } else if (dp[k].count(h) > 0) {
    return dp[k][h];
  } else if (l[k] <= r[k]) {
    llint& ret = dp[k][h];
    for (int i = l[k]; i <= r[k]; ++i) {
      bool flag = true;
      flag &= l[k] == 0 || height(i, y[k], l[k] - 1) <= h[l[k] - 1];
      flag &= height(i, y[k], l[k]) > h[l[k]];
      flag &= height(i, y[k], r[k]) > h[r[k]];
      flag &= r[k] == m - 1 || height(i, y[k], r[k] + 1) <= h[r[k] + 1];
      if (flag) {
        vector<int> hh(h);
        for (int j = l[k]; j <= r[k]; ++j) {
          hh[j] = height(i, y[k], j);
        }
        ret += gao(k - 1, hh);
      }
    }
    return ret %= MOD;
  } else {
    int mul = count_if(ALL(h), bind2nd(greater_equal<int>(), y[k]));
    return dp[k][h] = mul * gao(k - 1, h) % MOD;
  }
}

int Mountains::countPlacements(vector <int> h, vector <string> visibility) {
  n = h.size();
  m = visibility[0].size();
  FOR (i, n) {
    dp[i].clear();
    y[i] = h[i];
    string t = visibility[i];
    l[i] = m;
    r[i] = -1;
    FOR (j, m) {
      if (t[j] == 'X') {
        l[i] = min(l[i], j);
        r[i] = max(r[i], j);
      }
    }
  }
  return gao(n - 1, vector<int>(m, 0));
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
        int heightsARRAY[] = {2, 3, 2};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        string visibilityARRAY[] = {"------",
            "XXXX--",
            "---XXX"};
        vector <string> visibility( visibilityARRAY, visibilityARRAY+ARRSIZE(visibilityARRAY) );
        Mountains theObject;
        eq(0, theObject.countPlacements(heights, visibility),4);
    }
    {
        int heightsARRAY[] = {4, 3, 4};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        string visibilityARRAY[] = {"XXXXX--------",
            "----------XXX",
            "----XXXXXXX--"};
        vector <string> visibility( visibilityARRAY, visibilityARRAY+ARRSIZE(visibilityARRAY) );
        Mountains theObject;
        eq(1, theObject.countPlacements(heights, visibility),4);
    }
     // exit(0);
    {
        int heightsARRAY[] = {13, 2, 3, 2};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        string visibilityARRAY[] = {"XXXXXXXXX",
            "-XXX-----",
            "----XXXXX",
            "-----XXX-"};
        vector <string> visibility( visibilityARRAY, visibilityARRAY+ARRSIZE(visibilityARRAY) );
        Mountains theObject;
        eq(2, theObject.countPlacements(heights, visibility),9);
    }
    {
        int heightsARRAY[] = {8, 2, 9, 3, 10};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        string visibilityARRAY[] = {"X------",
            "-------",
            "------X",
            "-------",
            "XXXXXXX"};
        vector <string> visibility( visibilityARRAY, visibilityARRAY+ARRSIZE(visibilityARRAY) );
        Mountains theObject;
        eq(3, theObject.countPlacements(heights, visibility),98);
    }
    {
        int heightsARRAY[] = {20, 20, 20, 20, 20, 20, 45, 50, 49, 50};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        string visibilityARRAY[] = {"-------------------",
            "-------------------",
            "-------------------",
            "-------------------",
            "-------------------",
            "-------------------",
            "-------------------",
            "------------XXXXXXX",
            "XXXXXXX------------",
            "XXXXXXXXXXXXXXXXXXX"}
           ;
        vector <string> visibility( visibilityARRAY, visibilityARRAY+ARRSIZE(visibilityARRAY) );
        Mountains theObject;
        eq(4, theObject.countPlacements(heights, visibility),973726691);
    }
    {
      int heightsARRAY[] = {42, 40, 47, 49, 48, 50, 48, 48, 47, 50};
      vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
      string visibilityARRAY[] = {"--------------------------------------------------", "--------------------------------------------------", "XXXXX---------------------------------------------", "--------------------------------------------XXXXXX", "XXXXXXXXXX----------------------------------------", "XXXXXXXXXXXXXXXX----------------------------------", "--------------------------------------XXXXXXXXXXXX", "--------------------------------------------------", "-----------------------------XXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};
      vector <string> visibility( visibilityARRAY, visibilityARRAY+ARRSIZE(visibilityARRAY) );
      Mountains theObject;
      eq(-1, theObject.countPlacements(heights, visibility),2147405);
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
