#include <cstdio>
#include <utility>
#include <unordered_map>

using namespace std;

const int MAXN = 3003;

int a[MAXN];
int dp[MAXN][MAXN];
unordered_map<int, int> mp(MAXN);

int main() {
  int n, m;
  pair<int, int> p;

#ifndef __WATASHI__
  freopen("fibsubseq.in", "r", stdin);
  freopen("fibsubseq.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    for (int j = i + 1; j < n; ++j) {
      dp[i][j] = 1;
    }
  }

  m = 0;
  p.first = a[0];
  mp.clear();
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      auto it = mp.find(a[j] + a[i]);
      if (it != mp.end()) {
        dp[j][i] = dp[i][it->second] + 1;
      }
      if (dp[j][i] > m) {
        m = dp[j][i];
        p = make_pair(a[j], a[i]);
      }
    }
    mp[a[i]] = i;
  }

  printf("%d\n", m + 1);
  printf("%d", p.first);
  for (int i = 0; i < m; ++i) {
    printf(" %d", p.second);
    p = make_pair(p.second, p.first + p.second);
  }
  puts("");

  return 0;
}

