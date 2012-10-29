#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
#ifndef __WATASHI__
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, m, ca, cb;
  vector<pair<int, int> > a, b, cc;

  scanf("%d", &n);
  a.resize(n);
  ca = 0;
  for (int i = 0; i < n; ++i) {
    a[i].first = i;
    scanf("%d", &a[i].second);
    if (i > 0 && a[i].second != a[i - 1].second) {
      ++ca;
    }
  }
  scanf("%d", &m);
  b.resize(m);
  cb = 0;
  for (int i = 0; i < m; ++i) {
    b[i].first = n + i;
    scanf("%d", &b[i].second);
    if (i > 0 && b[i].second != b[i - 1].second) {
      ++cb;
    }
  }
  if (ca < cb || (ca == cb && b.back().second != 0)) {
    swap(a, b);
  }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int tag = a.back().second; !a.empty() || !b.empty(); tag = 1 - tag) {
    int c = 0;
    // printf("tag = %d\n", tag);
    while (!a.empty() && a.back().second == tag) {
      printf("%d ", a.back().first + 1);
      a.pop_back();
      ++c;
    }
    while (!b.empty() && b.back().second == tag) {
      printf("%d ", b.back().first + 1);
      b.pop_back();
      ++c;
    }
    cc.push_back({c, tag});
  }
  while (!cc.empty() && cc.back().second == 0) {
    cc.pop_back();
  }
  printf("\n%d\n", (int)cc.size());
  for (int i = 0, j = 0; i < (int)cc.size(); ++i) {
    j += cc[i].first;
    printf("%d ", j);
  }

  return 0;
}
