#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 55;
const int INF = 1 << 20;
const long long MOD = 1000000007LL;

long long choose[MAXN][MAXN];

void init() {
  for (int i = 0; i < MAXN; ++i) {
    choose[i][0] = choose[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
      if (choose[i][j] >= MOD) {
        choose[i][j] -= MOD;
      }
    }
  }
}

int d[MAXN][MAXN][2];
long long dp[MAXN][MAXN][2];

struct State {
  int a, b, c;

  int& d() const {
    return ::d[a][b][c];
  }

  long long& dp() const {
    return ::dp[a][b][c];
  }
};

int main() {
  int n, m, na, nb;
  State s, t;
  vector<int> v;
  multimap<int, State> pq;

  init();
  scanf("%d%d", &n, &m);
  m /= 50;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  na = count(v.begin(), v.end(), 50);
  nb = count(v.begin(), v.end(), 100);

  for (int i = 0; i <= na; ++i) {
    for (int j = 0; j <= nb; ++j) {
      d[i][j][0] = d[i][j][1] = INF;
    }
  }
  s = {na, nb, 0};
  s.d() = 0;
  s.dp() = 1;
  pq.insert({s.d(), s});

  while (!pq.empty()) {
    int d = pq.begin()->first;
    s = pq.begin()->second;
    pq.erase(pq.begin());
    if (d > s.d()) {
      continue;
    }
    ++d;
    s.dp() %= MOD;
    if (s.c == 0) {
      for (int i = 0; i <= s.a; ++i) {
        for (int j = 0; j <= s.b; ++j) {
          if (i + 2 * j > m) {
            break;
          }
          if (i == 0 && j == 0) {
            continue;
          }
          t = {s.a - i, s.b - j, 1};
          if (t.d() >= d) {
            if (t.d() > d) {
              t.d() = d;
              t.dp() = 0;
              pq.insert({t.d(), t});
            }
            t.dp() += choose[s.a][i] * choose[s.b][j] % MOD *
              s.dp() % MOD;
          }
        }
      }
    } else {
      for (int i = s.a; i <= na; ++i) {
        for (int j = s.b; j <= nb; ++j) {
          if ((i - s.a) + 2 * (j - s.b) > m) {
            break;
          }
          if (i == s.a && j == s.b) {
            continue;
          }
          t = {i, j, 0};
          if (t.d() >= d) {
            if (t.d() > d) {
              t.d() = d;
              t.dp() = 0;
              pq.insert({t.d(), t});
            }
            t.dp() += choose[na - s.a][i - s.a] * choose[nb - s.b][j - s.b] % MOD *
              s.dp() % MOD;
          }
        }
      }
    }
  }

  s = {0, 0, 1};
  if (s.d() == INF) {
    s.d() = -1;
    s.dp() = 0;
  }
  printf("%d\n%d\n", s.d(), (int)s.dp());

  return 0;
}

