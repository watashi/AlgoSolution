#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  int n, x, y;
  vector<pair<int, int>> v;
  multiset<pair<int, int>> ms;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    // ms.emplace(min(x, y), max(x, y));
    ms.insert({min(x, y), max(x, y)});
  }

  while (!ms.empty()) {
    tie(x, y) = *ms.begin();
    ms.erase(ms.begin());
    if (v.empty() || x > v.back().first || y > v.back().second) {
      v.emplace_back(x, y);
    } else if (x < y) {
      // ms.emplace(y, x);
      ms.insert({y, x});
    } else {
      puts("Chaos");
      return 0;
    }
  }

  reverse(v.begin(), v.end());
  for (const auto& i: v) {
    printf("%d %d\n", i.first, i.second);
  }

  return 0;
}
