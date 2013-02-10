#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const long long MOD = 1000000007;

long long c[MAXN][MAXN];

void init() {
  for (int i = 0; i < MAXN; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      if (c[i][j] >= MOD) {
        c[i][j] -= MOD;
      }
    }
  }
}

vector<pair<int, bool> > e[MAXN];

vector<long long> gao(int v, int p) {
  int n = 0;
  vector<long long> pre(1, 1);
  for (auto w: e[v]) {
    if (w.first == p) {
      continue;
    }
    vector<long long> sub = gao(w.first, v);
    int m = sub.size();
    n += m;
    vector<long long> cur(n + 1, 0);

    if (w.second) {
      for (int i = (int)sub.size() - 1; i > 0; --i) {
        sub[i - 1] = (sub[i - 1] + sub[i]) % MOD;
      }
      sub.push_back(0);
    } else {
      for (int i = 1; i < (int)sub.size(); ++i) {
        sub[i] = (sub[i] + sub[i - 1]) % MOD;
      }
      sub.insert(sub.begin(), 0);
    }
    for (int i = 0; i < (int)pre.size(); ++i) {
      for (int j = 0; j < (int)sub.size(); ++j) {
        long long x = pre[i] * sub[j] % MOD;
        long long y = c[i + j][j] * c[n - (i + j)][m - j] % MOD;
        cur[i + j] = (cur[i + j] + x * y) % MOD;
      }
    }
    cur.swap(pre);
  }

  /*
  printf("gao[%d] = {", v);
  for (int i: pre) {
    printf("%d, ", i);
  }
  puts("}");
  */
  return pre;
}

int main() {
  int re, n, a, b;
  char c;

  init();
  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      scanf("%d %c%d", &a, &c, &b);
      e[a].push_back({b, c == '<'});
      e[b].push_back({a, c == '>'});
    }

    auto ans = gao(0, 0);
    long long sum = 0;
    for (long long i: ans) {
      sum += i;
      sum %= MOD;
    }
    printf("Case #%d: ", ri);
    printf("%lld\n", sum);
    fflush(stdout);
  }

  return 0;
}
