#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

inline int sqr(int x) {
  return x * x;
}

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> p(n);
    for (auto& i: p) {
      scanf("%d%d", &i.first, &i.second);
    }

    int ans = 0;
    for (const auto& i: p) {
      unordered_map<int, int> c;
      for (const auto& j: p) {
        ++c[sqr(i.first - j.first) + sqr(i.second - j.second)];
      }
      for (const auto& k: c) {
        ans += k.second * (k.second - 1) / 2;
      }
    }
    printf("Case #%d: %d\n", ri, ans);
  }

  return 0;
}
