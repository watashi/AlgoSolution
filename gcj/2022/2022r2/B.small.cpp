#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 109;

int isqrt(int64_t xx) {
  int lo = 0, hi = 2 * MAXN + 1;
  xx *= 4;
  while (lo < hi) {
    int mi = (lo + hi) / 2;
    if ((int64_t)mi * mi < xx) {
      lo = mi + 1;
    } else {
      hi = mi;
    }
  }
  // (hi - 1, hi]
  return hi / 2;
}


int main() {
  vector<int> ans(MAXN);
  vector<vector<int>> v(MAXN);
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j <= i; ++j) {
      int k = isqrt(i * i - j * j);
      // printf("isqrt(%d, %d) = %d\n", j, i, k);
      v[j].push_back(k);
      v[k].push_back(j);
      while (isqrt(j * j + k * k) <= i) {
        ++k;
      }
      ans[i] += k;
    }
    for (int j = 0; j <= i; ++j) {
      sort(v[j].begin(), v[j].end());
      v[j].erase(unique(v[j].begin(), v[j].end()), v[j].end());
      ans[i] -= (int)v[j].size();
    }
    // printf("[%d] = %d\n", i, ans[i]);
  }

  int re;
  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int r;
    scanf("%d", &r);
    printf("Case #%d: %d\n", ri, 4 * ans[r]);
  }

  return 0;
}
