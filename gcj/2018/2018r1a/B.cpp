#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Cashier {
  long long m, s, p;

  long long operator()(long long t) const {
    return min(m, max(0LL, t - p) / s);
  }
};

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    long long r, c, b;
    vector<Cashier> cs;
    scanf("%lld%lld%lld", &r, &b, &c);
    cs.resize(c);
    for (auto& i: cs) {
      scanf("%lld%lld%lld", &i.m, &i.s, &i.p);
    }

    long long lo = 0, hi = 1000000007LL * 1000000007LL;
    while (lo < hi) {
      long long mi = (lo + hi) / 2;
      vector<long long> v;
      v.reserve(cs.size());
      for (const auto& i: cs) {
        v.emplace_back(i(mi));
      }
      sort(v.rbegin(), v.rend());
      if (accumulate(v.begin(), v.begin() + r, 0LL) >= b) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    printf("Case #%d: %lld\n", ri, hi);
  }

  return 0;
}
