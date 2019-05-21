#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n, t;
    vector<int> v[2], w;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &t);
      v[i % 2].emplace_back(t);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    for (int i = 0; i < n; ++i) {
      w.emplace_back(v[i % 2][i / 2]);
    }
    for (int i = 1; i <= n; ++i) {
      if (i == n) {
        printf("Case #%d: OK\n", ri);
      } else if (w[i] < w[i - 1]) {
        printf("Case #%d: %d\n", ri, i - 1);
        break;
      }
    }
  }

  return 0;
}
