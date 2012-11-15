#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

struct Matrix {
  static const int MAXN = 128;

  int r, c;
  int64 a[MAXN][MAXN];

  int64* operator[](int i) {
    return a[i];
  }

  const int64* operator[](int i) const {
    return a[i];
  }

  void init(int n) {
    init(n, n, 0);
    for (int i = 0; i < n; ++i) {
      a[i][i] = 1;
    }
  }

  void init(int r, int c) {
    this->r = r;
    this->c = c;
  }

  void init(int r, int c, int64 x) {
    init(r, c);
    for (int i = 0; i < r; ++i) {
      fill(a[i], a[i] + c, x);
    }
  }

  void init(const Matrix& o) {
    init(o.r, o.c);
    for (int i = 0; i < r; ++i) {
      copy(o[i], o[i] + c, a[i]);
    }
  }
};

void mul(const Matrix& a, const Matrix& b, int64 m, Matrix& ret) {
  static Matrix c;
  c.init(a.r, b.c);
  for (int i = 0; i < c.r; ++i) {
    for (int j = 0; j < c.c; ++j) {
      int64 x = 0;
      for (int k = 0; k < a.c; ++k) {
        x += a[i][k] * b[k][j] % m;
      }
      c[i][j] = x % m;
    }
  }
  ret.init(c);
}

void pow(const Matrix& a, int64 b, int64 m, Matrix& ret) {
  static Matrix c;
  c.init(a);

  ret.init(c.r);
  while (b > 0) {
    if (b % 2 != 0) {
      mul(ret, c, m, ret);
    }
    b /= 2;
    mul(c, c, m, c);
  }
}

void init(int n, Matrix& a) {
  int m = (1 << (n - 1)) - 1;
  a.init(1 << n, 1 << n, 0);
  for (int i = 0; i < a.r; ++i) {
    for (int j = 0; j < a.c; ++j) {
      if ((m & ((i ^ (i >> 1)) | (i ^ (j >> 1)) | (i ^ j))) == m) {
        a[i][j] = 1;
      }
    }
  }
}

const int64 MOD = 1000000007;
Matrix a;

int main() {
  int n;
  long long m;

  scanf("%d%lld", &n, &m);
  init(n, a);
  pow(a, m - 1, MOD, a);
  m = 0;
  for (int i = 0; i < a.r; ++i) {
    for (int j = 0; j < a.c; ++j) {
      m += a[i][j];
    }
  }
  printf("%lld\n", m % MOD);

  return 0;
}

//Correct Answer
//Execution Time: 3.83
