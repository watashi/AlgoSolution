#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int re, n, a;
  long long e, f;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    e = 0;
    f = 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a);
      f += e * (a + 1) + 1;
      f += a * (a - 1) / 2;
      e += a + 1;
    }

    printf("Case #%d: ", ri);
    printf("%lld\n", f);
    fflush(stdout);
  }

  return 0;
}
