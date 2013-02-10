#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10;

int a[MAXN], b[MAXN], p[MAXN];
char c[MAXN];

int main() {
  int re, n, m;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
    for (int i = 1; i < n; ++i) {
      scanf("%d %c%d", &a[i], &c[i], &b[i]);
    }

    m = 0;
    do {
      bool flag = true;
      for (int i = 1; i < n; ++i) {
        flag &= (p[a[i]] < p[b[i]]) == (c[i] == '<');
      }
      if (flag) {
        ++m;
      }
    } while (next_permutation(p, p + n));

    printf("Case #%d: ", ri);
    printf("%d\n", m);
    fflush(stdout);
  }

  return 0;
}
