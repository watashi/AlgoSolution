#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 55;

typedef long long llint;
typedef llint Matrix[MAXN][MAXN];

const llint MOD = 1000000007;

void mul(int n, const Matrix a, const Matrix b, Matrix ret) {
  static Matrix c;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i][j] = 0;
      for (int k = 0; k < n; ++k) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  memcpy(ret, c, sizeof(Matrix));
}

void pow(int n, const Matrix a, llint b, Matrix ret) {
  static Matrix t;
  memcpy(t, a, sizeof(Matrix));
  memset(ret, 0, sizeof(Matrix));
  for (int i = 0; i < n; ++i) {
    ret[i][i] = 1;
  }
  while (b > 0) {
    if (b & 1) {
      mul(n, ret, t, ret);
    }
    b >>= 1;
    mul(n, t, t, t);
  }
}

int main() {
  int n, m;
  llint ans;
  Matrix t;
  vector<llint> bin;

  bin.resize(1024);
  bin[0] = 1;
  for (int i = 1; i < (int)bin.size(); ++i) {
    bin[i] = bin[i - 1] * 2 % MOD;
  }

  scanf("%d%d", &n, &m);
  memset(t, 0, sizeof(Matrix));
  for (int i = 0; i <= m; ++i) {    // cur_step_length
    for (int j = 0; j <= m; ++j) {  // pre_step_length
      if (i == 0) {
        t[i][j] = 1;
      } else if (i + j > m) {
        t[i][j] = bin[i + j - m - 1];
      } else {
        t[i][j] = 0;
      }
    }
  }
  pow(m + 1, t, n, t);

  ans = 0;
  for (int i = 0; i <= m; ++i) {
    ans += t[i][m];
  }
  ans %= MOD;
  ans *= ans;
  ans %= MOD;
  printf("%d\n", (int)ans);

  return 0;
}
