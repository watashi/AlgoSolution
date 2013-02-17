#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
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

  void init(int r, int c) {
    this->r = r;
    this->c = c;
  }

  void fill(int r, int c, int64 x = 0) {
    init(r, c);
    for (int i = 0; i < r; ++i) {
      ::fill(a[i], a[i] + c, x);
    }
  }

  void eye(int n, int64 x = 1) {
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

void add(const Matrix& a, const Matrix& b, int64 m, Matrix& ret) {
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
  ret.set(c);
}

void pow(const Matrix& a, int64 b, int64 m, Matrix& ret) {
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

const int64 MOD = 1000000007LL;
int a[10][10];

int main() {
  int re;
  int64 n, ans;
  Matrix x;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%lld", &n);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        scanf("%d", &a[i][j]);
      }
    }

    x.eye(101, 0);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          if (a[i][k] == 0 && a[j][k] == 0) {
            x[k * 10 + j][j * 10 + i] = 1;
          }
        }
      }
    }
    for (int i = 10; i < 1000; ++i) {
      x[100][i] = 1;
    }

    pow(x, n - 1, MOD, x);
    ans = 9;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (a[i][j] == 0) {
          ans += x[100][i * 10 + j];
        }
      }
    }
    ans %= MOD;

    printf("Case #%d: ", ri);
    printf("%lld\n", ans);
    fflush(stdout);
  }

  return 0;
}
