#include <bits/stdc++.h>

using namespace std;

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n, k;
    scanf("%d%d", &n, &k);
    k = n * n - 1 - k;
    printf("Case #%d: ", ri);

    vector<pair<int, int>> ans;
    int m = n / 2, s = 1, d = 8 * m - 2;
    for (int i = 2 * m; i >= 2; i -= 2) {
      bool used = false;
      for (int j = 0; j < 4; ++j) {
        if (!used && k > 0 && k >= d) {
          used = true;
          k -= d;
          ans.emplace_back(s + 1, s + 2 + d);
        }
        s += i;
        d -= 2;
      }
    }
    if (k > 0) {
      puts("IMPOSSIBLE");
    } else {
      printf("%d\n", (int)ans.size());
      for (const auto& i: ans) {
        printf("%d %d\n", i.first, i.second);
      }
    }
  }

  return 0;
}
