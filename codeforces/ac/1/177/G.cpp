#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;
struct Matrix {
  static const int MAXN = 4;

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

const int MAXN = 100100;
const int MAXF = 31;  // odd
const llint MOD = 1000000007;

int len[MAXF];

void init() {
  len[0] = len[1] = 1;
  for (int i = 2; i < MAXF; ++i) {
    len[i] = len[i - 1] + len[i - 2];
  }
}

void genpre(int n, const char str[], int pre[]) {
  static bool inf[MAXN];
  for (int i = n - 1; i >= 0; --i) {
    if (str[i] == 'a') {
      pre[i] = 0;
      inf[i] = false;
    } else if (str[i + 1] != 'a') {
      pre[i] = 1;
      inf[i] = str[i + 1] != 'b';
    } else {
      pre[i] = 2;
      inf[i] = true;
      for (int j = 3; i + len[j - 1] < n && inf[i]; ++j) {
        if (pre[i + len[j - 1]] >= j - 2 || inf[i + len[j - 1]]) {
          pre[i] = j;
        } else {
          inf[i] = false;
        }
      }
    }
    // printf("%c: %d%s\n", str[i], pre[i], inf[i] ? "+" : "");
  }
}

void gensuf(int n, const char str[], int suf[]) {
  static bool inf[MAXN];
  for (int i = 0; i < n; ++i) {
    suf[i] = str[i] == 'a' ? 0 : 1;
    inf[i] = true;
    for (int j = suf[i] + 2; len[j - 2] <= i && inf[i]; j += 2) {
      if (suf[i - len[j - 2]] % 2 != suf[i] % 2 &&
          (suf[i - len[j - 2]] >= j - 1 || inf[i - len[j - 2]])) {
        suf[i] = j;
      } else {
        inf[i] = false;
      }
    }
    // printf("%c: %d%s\n", str[i], suf[i], inf[i] ? "+" : "");
  }
}

int main() {
  int n, re;
  llint m, ans;
  static char str[MAXN];
  static int pre[MAXN], suf[MAXN];
  static llint diff[MAXF + 2], sum[MAXF];
  static Matrix odd, even, trans;

  init();
  scanf("%I64d%d", &m, &re);
  --m;
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%s", str);
    n = strlen(str);

    fill(diff, diff + MAXF + 2, 0);
    if (strcmp(str, "a") == 0) {
      diff[0] = 1;
    } else if (strcmp(str, "b") == 0) {
      diff[1] = 1;
    } else if (strcmp(str, "ba") == 0) {
      diff[2] = 1;
    } else {
      genpre(n, str, pre);
      gensuf(n, str, suf);
      for (int i = 1; i < n; ++i) {
        if (str[i] != 'a' && len[suf[i - 1]] >= i && len[pre[i]] >= n - i) {
          for (int j = suf[i - 1] + 1; j < MAXF + 2; j += 2) {
            if (j >= pre[i] + 2) {
              ++diff[j];
            }
          }
        }
      }
    }

    fill(sum, sum + MAXF, 0);
    sum[0] = diff[0];
    sum[1] = diff[1];
    for (int i = 2; i < MAXF; ++i) {
      sum[i] = (sum[i - 1] + sum[i - 2] + diff[i]) % MOD;
    }

    if (m < MAXF) {
      ans = sum[m];
    } else {
      odd.fill(3, 3, 0);
      even.fill(3, 3, 0);
      odd[0][0] = even[0][0] = 1;
      odd[0][1] = even[0][1] = 1;
      odd[1][0] = even[1][0] = 1;
      odd[2][2] = even[2][2] = 1;
      odd[0][2] = diff[MAXF];
      even[0][2] = diff[MAXF + 1];
      mul(even, odd, MOD, trans);
      pow(trans, (m - MAXF + 1) / 2, MOD, trans);
      if (m % 2 != 0) {
        mul(odd, trans, MOD, trans);
      }
      ans = (trans[0][0] * sum[MAXF - 1] +
             trans[0][1] * sum[MAXF - 2] +
             trans[0][2] * 1) % MOD;
    }
    printf("%I64d\n", ans);
  }

  return 0;
}

