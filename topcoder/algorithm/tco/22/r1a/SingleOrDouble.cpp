#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
// BEGIN CUT HERE
#define __WATASHI__
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
// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct SingleOrDouble {
  double probAlice(int N, int D, int A, int B);
};

void mul(const long double x[4][4], const long double y[4][4], long double z[4][4]) {
    FOR(i, 4) {
        FOR(j, 4) {
            z[i][j] = 0;
            FOR(k, 4) {
                z[i][j] += x[i][k] * y[k][j];
            }
        }
    }
}

double SingleOrDouble::probAlice(int N, int D, int A, int B) {
    vector<int64_t> dp(1, 1);
    int64_t tot = 1;
    FOR(i, N) {
        vector<int64_t> pre((i + 1) * D + 1, 0);
        pre.swap(dp);
        tot *= D;
        FOR(j, pre.size()) {
            FOR(k, D) {
                dp[j + k + 1] += pre[j];
            }
        }
    }
    long double pa = (long double)dp[A] / tot;
    long double pb = (long double)dp[B] / tot;
    long double pc = (long double)(tot - dp[A] - dp[B]) / tot;
    long double a[4][4], b[4][4];
    MEMSET(a, 0);
    a[0][0] = a[0][1] = pc;
    a[1][0] = pb;
    a[2][0] = a[2][1] = pa;
    a[3][1] = pb;
    a[2][2] = a[3][3] = 1;
    FOR(i, 1000) {
        mul(a, a, b);
        memcpy(a, b, sizeof(a));
    }
    double ans = pa * (pb + 1) / (1 - pc - pc * pb);
    errf("%Lf %Lf\n", a[2][0], ans);
    return a[2][0];
}

// BEGIN CUT HERE
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
        SingleOrDouble theObject;
        eq(0, theObject.probAlice(1, 2, 1, 2),0.75);
    }
    {
        SingleOrDouble theObject;
        eq(1, theObject.probAlice(1, 6, 1, 2),0.8749999999999999);
    }
    {
        SingleOrDouble theObject;
        eq(2, theObject.probAlice(2, 6, 2, 7),0.538461538461538);
    }
    {
        SingleOrDouble theObject;
        eq(3, theObject.probAlice(3, 10, 29, 16),0.3644067796610159);
    }
    SingleOrDouble theObject;
    theObject.probAlice(10, 10, 10, 100);
    theObject.probAlice(10, 10, 10, 90);
    theObject.probAlice(10, 10, 10, 80);
    theObject.probAlice(10, 10, 10, 50);
    theObject.probAlice(10, 10, 15, 90);


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
// END CUT HERE
