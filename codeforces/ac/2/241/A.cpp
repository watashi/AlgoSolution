#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int d[MAXN], s[MAXN];
int t[MAXN], r[MAXN];

int main() {
  int n, m, ss;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }

  t[0] = 0;
  r[0] = 0;
  ss = s[0];
  for (int i = 0; i < n; ++i) {
    t[i + 1] = t[i] + d[i];
    r[i + 1] = r[i] + s[i] - d[i];
    ss = max(ss, s[i]);
    if (r[i + 1] < 0) {
      int c = (-r[i + 1] + ss - 1) / ss;
      t[i + 1] += c * m;
      r[i + 1] += c * ss;
    }
    // printf("%d %d\n", t[i + 1], r[i + 1]);
  }
  printf("%d\n", t[n]);

  return 0;
}

