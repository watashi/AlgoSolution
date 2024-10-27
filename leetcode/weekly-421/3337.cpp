class Solution {
  typedef long long llint;

  struct Matrix {
    static constexpr int MAXN = 26;

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

  static constexpr llint MOD = 1000000007;

public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    static Matrix a;
    a.fill(Matrix::MAXN, Matrix::MAXN, 0);
    for (int i = 0; i < Matrix::MAXN; ++i) {
      for (int j = 1; j <= nums[i]; ++j) {
        ++a[(i + j) % Matrix::MAXN][i];
      }
    }

    static Matrix b;
    b.eye(Matrix::MAXN);
    while (t > 0) {
      if (t & 1) {
        mul(b, a, MOD, b);
      }
      t >>= 1;
      mul(a, a, MOD, a);
    }

    vector<int> v(Matrix::MAXN, 0);
    for (char c : s) {
      ++v[c - 'a'];
    }

    llint ret = 0;
    for (int i = 0; i < Matrix::MAXN; ++i) {
      for (int j = 0; j < Matrix::MAXN; ++j) {
        ret += b[i][j] * v[j] % MOD;
      }
    }
    ret %= MOD;
    return (int)ret;
  }
};

