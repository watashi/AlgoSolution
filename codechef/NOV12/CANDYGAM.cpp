#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 51;

int r, c;
long long a[MAXN][MAXN], s[MAXN][MAXN];
long long dp[MAXN][MAXN][MAXN][MAXN];

struct Rect {
  union {
    int p[4];
    struct {
      int r1, r2, c1, c2;
    } q;
  };

  Rect(int r1, int r2, int c1, int c2) {
    q.r1 = r1;
    q.r2 = r2;
    q.c1 = c1;
    q.c2 = c2;
  }

  long long& dp() const {
    return ::dp[q.r1][q.r2][q.c1][q.c2];
  }

  long long sum() const {
    return s[q.r1][q.c1] - s[q.r1][q.c2] - s[q.r2][q.c1] + s[q.r2][q.c2];
  }

  int r() const {
    return q.r2 - q.r1;
  }

  int c() const {
    return q.c2 - q.c1;
  }
};

const int d[4] = {1, -1, 1, -1};

long long gao(Rect s) {
  long long& ret = s.dp();
  if (ret == -1) {
    if (s.r() == 0 || s.c() == 0) {
      ret = 0;
    } else {
      int t = (r + c) - (s.r() + s.c());
      long long sum = s.sum();
      if (t % 2 == 0) {
        int k = -1;
        long long cmp = 0;
        for (int i = 0; i < 4; ++i) {
          s.p[i] += d[i];
          long long sub = s.sum();
          if (k == -1 || cmp > sum - sub) {
            k = i;
            cmp = sum - sub;
          }
          s.p[i] -= d[i];
        }
        s.p[k] += d[k];
        ret = gao(s);
      } else {
        for (int i = 0; i < 4; ++i) {
          s.p[i] += d[i];
          long long sub = s.sum();
          ret = max(ret, (sum - sub) + gao(s));
          s.p[i] -= d[i];
        }
      }
    }
  }
  return ret;
}

int main() {
  int re;
  long long ans;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        scanf("%lld", &a[i][j]);
      }
    }
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        s[i][j] = s[i][j - 1] + a[i - 1][j - 1];
      }
      for (int j = 1; j <= c; ++j) {
        s[i][j] += s[i - 1][j];
      }
    }
    memset(dp, -1, sizeof(dp));
    ans = gao(Rect(0, r, 0, c));
    if (ans * 2 == s[r][c]) {
      ans = s[r][c];
    } else {
      ans = max(ans, s[r][c] - ans);
    }
    printf("%lld\n", ans);
  }

  return 0;
}

//Correct Answer
//Execution Time: 9.27

