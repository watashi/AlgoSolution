// TODO: this prob should have spj.

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int INF = 1000000000;

const string month[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

inline bool isleap(int yy) {
  return yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0);
}

inline bool after(int m1, int d1, int m2, int d2) {
  return m1 < m2 || (m1 == m2 && d1 < d2);
}

int m1[MAXN], d1[MAXN], op[MAXN], m2[MAXN], d2[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

void print(int n, int from, int to) {
  if (n > 1) {
    print(n - 1, from, pre[n][to]);
  }
  printf("%s %d %d, %s %s %d\n",
    month[m2[n]].c_str(), d2[n], from + to,
    op[n] == 1 ? "added" : "removed",
    month[m1[n]].c_str(), d1[n]);
}

int main() {
  int from, to, n, m;
  static char buf[1024];

#ifndef __WATASHI__
  freopen("holidays.in", "r", stdin);
  freopen("holidays.out", "w", stdout);
#endif
  scanf("%d%d%d", &from, &to, &n);
  m = to - from;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = (i == 0 ? 0 : -INF);
    }
  }

  m2[0] = d2[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%s%d", buf, &d2[i]);
    m2[i] = find(month, month + 13, buf) - month;
    scanf(",%s", buf);
    op[i] = (buf == string("added") ? 1 : -1);
    scanf("%s%d", buf, &d1[i]);
    m1[i] = find(month, month + 13, buf) - month;

    bool isafter = after(m2[i], d2[i], m1[i], d1[i]);
    int t = after(m2[i - 1], d2[i - 1], m2[i], d2[i]) ? 0 : 1;
    int d = 0;
    for (int j = m; j >= 0; --j) {
      if (isafter) {
        if (m1[i] != 2 || d1[i] != 29 || isleap(from + j)) {
          d += op[i];
        }
      }
      for (int k = j - t; k >= 0; --k) {
        // if (dp[i][j] < dp[i - 1][k] + d) {	// WA
        if (dp[i][j] <= dp[i - 1][k] + d) {
          dp[i][j] = dp[i - 1][k] + d;
          pre[i][j] = k;
        }
      }
      if (!isafter) {
        if (m1[i] != 2 || d1[i] != 29 || isleap(from + j)) {
          d += op[i];
        }
      }
    }

    if (m2[i] == 2 && d2[i] == 29) {
      for (int j = 0; j <= m; ++j) {
        if (!isleap(from + j)) {
          dp[i][j] = -INF;
        }
      }
    }
  }

  to = max_element(dp[n], dp[n] + m + 1) - dp[n];
  if (dp[n][to] < 0) {
    puts("-1");
  } else {
    printf("%d\n", dp[n][to]);
    print(n, from, to);
  }

  return 0;
}
