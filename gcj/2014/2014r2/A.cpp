#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
multiset<int> ms;

int main() {
  int re, n, m, t, ans;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &n, &m);
    ms.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", &t);
      ms.insert(t);
    }

    ans = 0;
    while (!ms.empty()) {
      ++ans;
      t = *ms.begin();
      ms.erase(ms.begin());
      auto it = ms.upper_bound(m - t);
      if (it != ms.begin()) {
        --it;
        ms.erase(it);
      }
    }
    printf("Case #%d: %d\n", ri, ans);
  }

  return 0;
}
