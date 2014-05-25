#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

char buf[MAXN];
int g[MAXN], s[MAXN];

int main() {
  int n, m, t;

  m = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    t = strlen(buf);
    m = max(m, t);
    for (int j = 0; j < t; ++j) {
      if (buf[j] == 'G') {
        ++g[j];
      } else {
        ++s[j];
      }
    }
  }

  int g0 = g[0], s0 = s[0], n0 = n, slot = 0;
  int ans = 0;

  for (int i = 1; i <= m; ++i) {
    int g1 = min(g0, g[i]);
    int s1 = min(s0, s[i]);
    int n1 = min(n0, g[i] + s[i]);
    slot += n0 - n1;
    if (g1 < g0) {
      int diff = min(slot, g0 - g1);
      slot -= diff;
      ans += diff;
    }
    if (s1 < s0) {
      int diff = min(slot, s0 - s1);
      slot -= diff;
      ans += diff;
    }
    g0 = g1;
    s0 = s1;
    n0 = n1;
  }
  printf("%d\n", ans);

  return 0;
}

