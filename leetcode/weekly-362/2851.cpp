class Solution {
  template<typename T = char>
  struct KMP {
    vector<T> pat;
    vector<int> fail;

    void init(int n, const T s[]) {
      vector<T>(s, s + n).swap(pat);
      fail.resize(n);
      if (n > 0) {
        fail[0] = -1;
      }
      for (int i = 1; i < n; ++i) {
        int k = fail[i - 1];
        while (k >= 0 && pat[k + 1] != pat[i]) {
          k = fail[k];
        }
        fail[i] = (pat[k + 1] == pat[i]) ? k + 1 : -1;
      }
    }

    vector<int> gao(int m, const T t[]) {
      if (pat.empty()) {
        return vector<int>(m, 0);
      }
      vector<int> ret(m);
      for (int i = 0, k = 0; i < m; ) {
        if (t[i] == pat[k]) {
          ++k;
          ret[i++] = k;
          if (k == (int)pat.size()) {
            k = fail[k - 1] + 1;
          }
        }
        else if (k > 0) {
          k = fail[k - 1] + 1;
        }
        else {
          ret[i++] = 0;
        }
      }
      return ret;
    }
  };

  using llint = long long;

  struct Matrix {
    static const int MAXN = 2;

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

  static const llint MOD = 1000000007;

public:
  int numberOfWays(string s, string t, long long k) {
    KMP kmp;
    kmp.init(t.size(), t.data());
    auto ss = s + s;
    auto match = kmp.gao(ss.size(), ss.data());

    int n = s.size();
    Matrix a, b;
    a.init(2, 2);
    a[0][0] = 0;
    a[0][1] = n - 1;
    a[1][0] = 1;
    a[1][1] = n - 2;
    b.eye(2);
    while (k > 0) {
      if (k & 1) {
        mul(a, b, MOD, b);
      }
      k >>= 1;
      mul(a, a, MOD, a);
    }

    llint ret = match[n - 1] == n ? b[0][0] : 0;
    for (int i = n; i < n + n - 1; ++i) {
      if (match[i] == n) {
        ret += b[1][0];
      }
    }
    return ret % MOD;
  }
};

