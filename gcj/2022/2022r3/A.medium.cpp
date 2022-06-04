#include "bits/stdc++.h"

using namespace std;

int main() {
  int re, n, k;

  (void)scanf("%d%d%d", &re, &n, &k);
  for (int ri = 1; ri <= re; ++ri) {
    int done = 0;
    vector<int> v(n), c(n);
    vector<bool> mark(n);
    while (done == 0) {
      for (auto& i : v) {
        (void)scanf("%d", &i);
        --i;
      }
      fill(mark.begin(), mark.end(), false);
      for (int i = 0; i < n; ++i) {
        for (int j = i; !mark[j]; j = v[j]) {
          c[j] = i;
          mark[j] = true;
        }
      }
      for (int i = 0; i < n; ++i) {
        if (i > 0) {
          putchar(' ');
        }
        printf("%d", c[i] + 1);
      }
      puts("");
      fflush(stdout);
      (void)scanf("%d", &done);
    }
  }

  return 0;
}
