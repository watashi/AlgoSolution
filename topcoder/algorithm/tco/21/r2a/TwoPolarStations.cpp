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

struct Matrix {
  static const int MAXN = 3;

  int r, c;
  llint a[MAXN][MAXN];

  llint* operator[](int i) {
    return a[i];
  }

  const llint* operator[](int i) const {
    return a[i];
  }

  void init(int row, int col) {
    this->r = row;
    this->c = col;
  }

  void fill(int row, int col, llint x = 0) {
    init(row, col);
    for (int i = 0; i < r; ++i) {
      ::fill(a[i], a[i] + c, x);
    }
  }

  void eye(int n, llint x = 1) {
    fill(n, n, 0);
    for (int i = 0; i < n; ++i) {
      a[i][i] = x;
    }
  }

  void set(const Matrix& o) {
    init(o.r, o.c);
    for (int i = 0; i < r; ++i) {
      copy(o[i], o[i] + c, a[i]);
    }
  }
};

void add(const Matrix& a, const Matrix& b, llint m, Matrix& ret) {
  static Matrix c;
  c.set(a);
  for (int i = 0; i < b.r; ++i) {
    for (int j = 0; j < b.c; ++j) {
      c[i][j] += b[i][j];
      if (c[i][j] >= m) {
        c[i][j] -= m;
      }
    }
  }
  ret.set(c);
}

void mul(const Matrix& a, const Matrix& b, llint m, Matrix& ret) {
  static Matrix c;
  c.init(a.r, b.c);
  for (int i = 0; i < c.r; ++i) {
    for (int j = 0; j < c.c; ++j) {
      llint x = 0;
      for (int k = 0; k < a.c; ++k) {
        x += a[i][k] * b[k][j] % m;
      }
      c[i][j] = x % m;
    }
  }
  ret.set(c);
}

void pow(const Matrix& a, llint b, llint m, Matrix& ret) {
  static Matrix c;
  c.set(a);
  ret.eye(c.r);
  while (b > 0) {
    if (b % 2 != 0) {
      mul(ret, c, m, ret);
    }
    b /= 2;
    mul(c, c, m, c);
  }
}

struct TwoPolarStations {
  int count(int N, int lo, int hi);
};

static constexpr llint MOD = 1000000007;

int TwoPolarStations::count(int N, int lo, int hi) {
  int M = hi - lo + 1;
  M = min(M, N - M);

  Matrix a;
  a.fill(2, 2);
  // 0: not connected to habitate
  // 1: connected to habitate
  a[0][0] = 1;
  a[0][1] = 1;
  a[1][0] = 1;
  a[1][1] = 2;

  llint ans = 0;
  Matrix c, d;

  // two habitates are connected
  pow(a, N, MOD, c);
  errf("[[%lld, %lld], [%lld, %lld]]\n", c[0][0], c[0][1], c[1][0], c[1][1]);
  ans += c[0][0] - 1;
  ans += c[1][1] - 1;

  // two habitates are not connected
  if (M > 0) {
    pow(a, M, MOD, d);
    errf("[[%lld, %lld], [%lld, %lld]]\n", d[0][0], d[0][1], d[1][0], d[1][1]);
    d[0][0] -= 1;
    pow(a, N - M, MOD, c);
    errf("[[%lld, %lld], [%lld, %lld]]\n", c[0][0], c[0][1], c[1][0], c[1][1]);
    c[1][1] -= 1;
    mul(c, d, MOD, d);
    errf("[[%lld, %lld], [%lld, %lld]]\n", d[0][0], d[0][1], d[1][0], d[1][1]);
    ans += 2 * d[1][0];
    // ans -= 2LL * M * (N - M);
  }

  return (ans % MOD + MOD) % MOD;
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
        TwoPolarStations theObject;
        eq(0, theObject.count(3, 0, 2),16);
    }
    {
        TwoPolarStations theObject;
        eq(1, theObject.count(3, 1, 1),24);
    }
    {
        TwoPolarStations theObject;
        eq(2, theObject.count(10, 1, 4),28325);
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
