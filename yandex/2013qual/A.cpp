#include <cstdio>

int main() {
  int n, m, t, d, a[2];

  scanf("%d%d", &n, &m);
  a[0] = a[1] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &t, &d);
    --t;
    if (d == -1) {
      a[t] += 1;
    } else if (d <= m) {
      a[t] += 2;
    } else {
      a[t] += 3;
    }
  }
  printf("%d:%d\n", a[0], a[1]);

  return 0;
}

