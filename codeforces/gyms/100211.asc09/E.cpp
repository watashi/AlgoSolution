#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 150; // !!128!!WA!!

struct BPolynomial : vector<bool> {
  bool read(FILE* fp = stdin) {
    int n;
    if (fscanf(fp, "%d", &n) == EOF) {
      return false;
    }
    resize(n + 1);
    for (BPolynomial::reverse_iterator i = rbegin(); i != rend(); ++i) {
      fscanf(fp, "%d", &n);
      *i = (n != 0);
    }
    return true;
  }

  void write(FILE* fp = stdout) const {
    if (empty()) {
      fputs("-1\n", fp);
    } else {
      fprintf(fp, "%d ", (int)size() - 1);
      for (BPolynomial::const_reverse_iterator i = rbegin(); i != rend(); ++i) {
        fputs(*i ? " 1" : " 0", fp);
      }
      fputc('\n', fp);
    }
  }

  bool operator[](int i) const {
    return 0 <= i && i < (int)size() ? vector<bool>::operator[](i) : false;
  }

  void trim() {
    while (!(empty() || back())) {
      pop_back();
    }
  }
};

bool solve(int m, int n, bool a[MAXN * 3][MAXN], bool b[MAXN * 3], bool y[MAXN]) {
  static int p[MAXN * 3];
  int r = 0, c = 0;

  while (r < m && c < n) {
    int rr = -1;
    for (int i = r; i < m; ++i) {
      if (a[i][c]) {
        rr = i;
        break;
      }
    }
    if (rr != -1) {
      for (int j = c; j < n; ++j) {
        swap(a[r][j], a[rr][j]);
      }
      swap(b[r], b[rr]);
      for (int i = r + 1; i < m; ++i) {
        if (a[i][c]) {
          a[i][c] = false;
          for (int j = c + 1; j < n; ++j) {
            if (a[r][j]) {
              a[i][j] = !a[i][j];
            }
          }
          if (b[r]) {
            b[i] = !b[i];
          }
        }
      }
      p[r] = c;
      ++r;
    }
    ++c;
  }

  for (int i = r; i < m; ++i) {
    if (b[i]) {
      return false;
    }
  }

  c = n - 1;
  for (int i = r - 1; i >= 0; --i) {
    while (c > p[i]) {
      y[c--] = false;
    }
    y[c] = b[i];
    for (int j = n - 1; j > c; --j) {
      y[c] ^= a[i][j] && y[j];
    }
    --c;
  }
  while (c >= 0) {
    y[c--] = false;
  }
  return true;
}

int main() {
  BPolynomial a, b, c;
  bool x[MAXN * 3][MAXN], y[MAXN * 3], z[MAXN];
  int m, n;

#ifndef __WATASHI__
  freopen("quadratic.in", "r", stdin);
  freopen("quadratic.out", "w", stdout);
#endif
  a.read();
  b.read();
  c.read();
  n = max(a.size(), max(b.size(), c.size()));
  m = 3 * n;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      x[i][j] = a[i - 2 * j] ^ b[i - j];
    }
    y[i] = c[i];
  }

  if (solve(m + 1, n + 1, x, y, z)) {
    BPolynomial ans;
    ans.insert(ans.end(), z, z + n + 1);
    ans.trim();
    ans.write();
  } else {
    puts("no solution");
  }

  return 0;
}

