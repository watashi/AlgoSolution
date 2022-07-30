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

template <typename, typename = void>
constexpr bool is_iterable{};

template <typename T>
constexpr bool is_iterable<
  T,
  std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
  >
> = true;

template<typename T, typename = enable_if_t<is_iterable<T>>>
inline void errf(const char* fmt, const T& v) {
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

constexpr int MAXN = 77;
constexpr int64_t MOD = 1000000007;

static int64_t memo[3][MAXN][MAXN][MAXN];

struct PreInPostOrder {
  int reconstruct(vector <int> PIP, vector <int> IPP);

  vector<int> xx, yy;

  int64_t gao(int d, int n, int x, int y);
};

int PreInPostOrder::reconstruct(vector <int> PIP, vector <int> IPP) {
  int n = (int)PIP.size();
  xx = PIP;
  yy = IPP;
  fill(memo[0][0][0], memo[3][0][0], -1);
  return (int)gao(0, n, 0, 0);
}

int64_t PreInPostOrder::gao(int d, int n, int x, int y) {
  if (n == 0) {
    return 1;
  }
  int64_t& ret = memo[d][n][x][y];
  if (ret != -1) {
    return ret;
  }
  if (d == 0) {
    // CLR, LCR
    for (int z = 0; z < n; ++z) {
      if (yy[y + z] == xx[x + 0]) {
        return ret = gao(1, z, x + 1, y) * gao(1, n - 1 - z, x + z + 1, y + z + 1) % MOD;
      }
    }
    return ret = 0;
  }
  else if (d == 1) {
    // LCR, LRC
    for (int z = 0; z < n; ++z) {
      if (xx[x + z] == yy[y + n - 1]) {
        return ret = gao(2, z, x, y) * gao(2, n - 1 - z, x + z + 1, y + z) % MOD;
      }
    }
    return ret = 0;
  }
  else {
    // LRC, CLR
    ret = 0;
    if (xx[x + n - 1] == yy[y]) {
      vector<int> diff(MAXN, 0);
      int nz = 0;
      for (int i = 0; i < n; ++i) {
        if (nz == 0) {
          ret += gao(0, i, x, y + 1) * gao(0, n - 1 - i, x + i, y + 1 + i) % MOD;
        }
        if (++diff[xx[x + i]] == 0) {
          --nz;
        }
        else {
          ++nz;
        }
        if (--diff[yy[y + 1 + i]] == 0) {
          --nz;
        }
        else {
          ++nz;
        }
      }
    }
    ret %= MOD;
    return ret;
  }
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
        int PIPARRAY[] = {0, 1, 2};
        vector <int> PIP( PIPARRAY, PIPARRAY+ARRSIZE(PIPARRAY) );
        int IPPARRAY[] = {0, 2, 1};
        vector <int> IPP( IPPARRAY, IPPARRAY+ARRSIZE(IPPARRAY) );
        PreInPostOrder theObject;
        eq(0, theObject.reconstruct(PIP, IPP),1);
    }
    {
        int PIPARRAY[] = {1, 2, 0};
        vector <int> PIP( PIPARRAY, PIPARRAY+ARRSIZE(PIPARRAY) );
        int IPPARRAY[] = {1, 0, 2};
        vector <int> IPP( IPPARRAY, IPPARRAY+ARRSIZE(IPPARRAY) );
        PreInPostOrder theObject;
        eq(1, theObject.reconstruct(PIP, IPP),1);
    }
    {
        int PIPARRAY[] = {1, 2, 0};
        vector <int> PIP( PIPARRAY, PIPARRAY+ARRSIZE(PIPARRAY) );
        int IPPARRAY[] = {0, 1, 2};
        vector <int> IPP( IPPARRAY, IPPARRAY+ARRSIZE(IPPARRAY) );
        PreInPostOrder theObject;
        eq(2, theObject.reconstruct(PIP, IPP),0);
    }
    {
        int PIPARRAY[] = {2, 1, 3, 0};
        vector <int> PIP( PIPARRAY, PIPARRAY+ARRSIZE(PIPARRAY) );
        int IPPARRAY[] = {0, 3, 1, 2};
        vector <int> IPP( IPPARRAY, IPPARRAY+ARRSIZE(IPPARRAY) );
        PreInPostOrder theObject;
        eq(3, theObject.reconstruct(PIP, IPP),2);
    }
    {
        int PIPARRAY[] = {0, 3, 4, 2, 1, 7, 8, 6, 5, 10, 9};
        vector <int> PIP( PIPARRAY, PIPARRAY+ARRSIZE(PIPARRAY) );
        int IPPARRAY[] = {2, 3, 4, 1, 0, 6, 7, 8, 9, 10, 5};
        vector <int> IPP( IPPARRAY, IPPARRAY+ARRSIZE(IPPARRAY) );
        PreInPostOrder theObject;
        eq(4, theObject.reconstruct(PIP, IPP),18);
    }
    {
        int PIPARRAY[] = {0,1,3,5,4,2};
        vector <int> PIP( PIPARRAY, PIPARRAY+ARRSIZE(PIPARRAY) );
        int IPPARRAY[] = {0,2,3,5,4,1};
        vector <int> IPP( IPPARRAY, IPPARRAY+ARRSIZE(IPPARRAY) );
        PreInPostOrder theObject;
        eq(5, theObject.reconstruct(PIP, IPP),4);
    }

    {
      int n = 70;
      vector<int> PIP(n), IPP(n);
      FOR(i, n) {
        PIP[i] = i;
        IPP[i] = i;
      }
      errf("%d, ", PreInPostOrder().reconstruct(PIP, IPP));
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
  (void)getchar();

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
