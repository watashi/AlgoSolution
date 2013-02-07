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

struct MegaFactorial {
  int countTrailingZeros(int N, int K, int B);
};

const int MAXN = 18;

struct Matrix {
  static llint MOD;

  llint a[MAXN][MAXN];

  explicit Matrix(int n, int d = 0) {
    for (int i = 0; i < n; ++i) {
      fill(a[i], a[i] + n, 0);
      a[i][i] = d;
    }
  }

  llint* operator[](int i) {
    return a[i];
  }

  const llint* operator[](int i) const {
    return a[i];
  }

  void debug(int n) {
    for (int i = 0; i < n; ++i) {
      printf(" %c", i == 0 ? '+' : '|');
      for (int j = 0; j < n; ++j) {
        printf(" %lld", a[i][j]);
      }
      printf(" %c\n", i == n - 1 ? ';' : ',');
    }
  }
};

// A + B
Matrix add(int n, const Matrix& a, const Matrix& b) {
  Matrix c(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i][j] = a[i][j] + b[i][j];
      if (c[i][j] >= Matrix::MOD) {
        c[i][j] -= Matrix::MOD;
      }
    }
  }
  return c;
}

// A * B
Matrix mul(int n, const Matrix& a, const Matrix& b) {
  Matrix c(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % Matrix::MOD;
      }
    }
  }
  return c;
}

// A^b
Matrix pow(int n, Matrix a, llint b) {
  Matrix c(n, 1);
  while (b > 0) {
    if (b % 2 > 0) {
      c = mul(n, c, a);
    }
    b /= 2;
    if (b > 0) {
      a = mul(n, a, a);
    }
  }
  return c;
}

// A^0 + ... + A^(b-1)
Matrix sum(int n, const Matrix& a, llint b) {
  if (b == 0) {
    return Matrix(n);
  } else if (b % 2 != 0) {
    return add(n,
      pow(n, a, b - 1),
      sum(n, a, b - 1));
  } else {
    return mul(n,
      add(n, Matrix(n, 1), pow(n, a, b / 2)),
      sum(n, a, b / 2));
  }
}

llint Matrix::MOD;

Matrix unit(int n) {
  Matrix ret(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      ret[i][j] = 1;
    }
  }
  return ret;
}

const int BASE[] = {-1, -1, 2, 3, 2, 5, 3, 7, 2, 3, 5};
const int MULT[] = {-1, -1, 1, 1, 2, 1, 1, 1, 3, 2, 1};

const llint MOD = 1000000009LL;

int MegaFactorial::countTrailingZeros(int N, int K, int B) {
  int base = BASE[B];
  int mult = MULT[B];
  Matrix::MOD = mult * MOD;

  llint ans = 0;
  Matrix u = unit(K);
  for (llint b = base; b <= N; b *= base) {
    Matrix a = pow(K, u, b);
    a = sum(K, a, N / b);
    a = mul(K, a, pow(K, u, N % b));
    for (int i = 0; i < K; ++i) {
      ans += a[K - 1][i];
    }
  }
  ans %= Matrix::MOD;
  return ans / mult;
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
        MegaFactorial theObject;
        eq(0, theObject.countTrailingZeros(6, 1, 4),2);
    }
    {
        MegaFactorial theObject;
        eq(1, theObject.countTrailingZeros(4, 2, 6),2);
    }
    {
        MegaFactorial theObject;
        eq(2, theObject.countTrailingZeros(10, 3, 10),22);
    }
    {
        MegaFactorial theObject;
        eq(3, theObject.countTrailingZeros(50, 10, 8),806813906);
    }
    {
        MegaFactorial theObject;
        eq(4, theObject.countTrailingZeros(1000000000, 16, 2),633700413);
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
