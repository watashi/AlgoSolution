#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;
static int64_t x[MAXN];

int main() {
  int n;
  int64_t a, s;

  scanf("%d", &n);
  s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a);
    if (i % 2 == 0) {
      s += a;
    } else {
      s -= a;
    }
    x[i] = s;
  }

  s = 0;
  a = 0;
  for (int i = 0; i < n; ++i) {
    a = max(a, x[i]);
    s = max(s, a - x[i]);
  }
  a = 0;
  for (int i = 0; i < n; ++i) {
    a = min(a, x[i]);
    s = max(s, x[i] - a);
  }
  printf("%lld\n", s);

  return 0;
}
